#include "ObjReader.h"

ObjReader::ObjReader() 
{
}

ObjReader::~ObjReader()
{

}

std::vector<Triangle> ObjReader::ReadTriangles(std::string filename)
{
	auto triangles = std::vector<Triangle>();

	std::ifstream file(filename);
	if (!file.is_open())
		return triangles;

	std::string command;
	std::string line;
	while (std::getline(file, line))
	{
		GetCommand(line, command);
		if (command == "v")
		{
			//std::cout << "Command: " << command << std::endl;
			std::vector<std::string> values = GetValuesOfLine(line, " ");

			Vector3 vect(std::stof(values[0]), std::stof(values[1]), std::stof(values[2]));

			vPos.push_back(vect);
		}
		else if (command == "vt")
		{
			std::vector<std::string> values = GetValuesOfLine(line, " ");

			Vector2 text(std::stof(values[0]), std::stof(values[1]));

			vText.push_back(text);
		}
		else if (command == "vn")
		{
			std::vector<std::string> values = GetValuesOfLine(line, " ");

			Vector3 norm(std::stof(values[0]), std::stof(values[1]), std::stof(values[2]));

			vNorm.push_back(norm);
		}
		else if (command == "f")
		{
			//std::cout << "Command: " << command << std::endl;
			std::vector<std::string> values = GetValuesOfLine(line, " ");
			std::vector<Vertex> vVertices;
			for (int i = 0; i < values.size(); i++)
			{
				vVertices.push_back(GetVertexOfString(values[i]));
			}
			//std::vector<std::string> faces = split(values[0], "/");
			AddTriangles(triangles, vVertices);
		}
		
	}

	file.close();

	return triangles;
}

size_t ObjReader::GetCommand(const std::string& line, std::string& oCommand) 
{
	oCommand = "";
	if (line.empty())
		return 0;
	std::string delimiter = " \t\r\n";
	//auto first_not_empty_char = find_if(line.begin(), line.end(), std::not1(isspace)) - line.begin();
	auto first_not_empty_char = line.find_first_not_of(delimiter);
	auto first_empty_after_char = line.find_first_of(delimiter, first_not_empty_char);
	auto character = line.substr(first_not_empty_char, first_empty_after_char);
	oCommand = character;

	return first_empty_after_char;
}

std::vector<std::string> ObjReader::GetValuesOfLine(const std::string& line, const std::string& delimiter)
{
	std::string o;
	auto command_char_index = GetCommand(line, o);
	std::string temp_line = line;

	size_t pos = command_char_index + 1;
	std::string token;
	temp_line.erase(0, pos);

	std::vector<std::string> result;

	while ((pos = temp_line.find(delimiter)) != std::string::npos) {
		token = temp_line.substr(0, pos);
		temp_line.erase(0, pos + delimiter.length());
		if (token.empty())
			continue;
		result.push_back(token);
	}
	result.push_back(temp_line);
	return result;
}



Vertex ObjReader::GetVertexOfString(const std::string& line)
{
	std::vector<std::string> temp_line = split(line, "/");

	Vertex vx;
	vx.Position = GetElement(vPos, temp_line[0]);

	//position and texture or position and normal
	if (temp_line.size() == 2)
	{
		// v/vt or v//vn

		if (temp_line[2].empty()) 
		{
			vx.Normal = GetElement(vNorm, temp_line[2]);
		}
		else
		{
			vx.TextureCoordinate = GetElement(vText, temp_line[1]);
		}
		
	}
	//position, texture and normal
	else if (temp_line.size() == 3)
	{
		vx.TextureCoordinate = GetElement(vText, temp_line[1]);
		vx.Normal = GetElement(vNorm, temp_line[2]);
	}
	return vx;

}

std::vector<std::string> ObjReader::split(const std::string& line, const std::string& delimiter)
{
	std::vector<std::string> result;
	std::string temp_line = line;
	size_t pos = 0;

	std::string token;
	while ((pos = temp_line.find(delimiter)) != std::string::npos) {
		token = temp_line.substr(0, pos);
		temp_line.erase(0, pos + delimiter.length());
		result.push_back(token);
	}
	result.push_back(temp_line);
	return result;
}

void ObjReader::AddTriangles(std::vector<Triangle>& triangles, std::vector<Vertex>& vertices)
{
	for (int i = 1; i < vertices.size()-1; i++)
	{
		std::vector<Vertex> tVerts;
		tVerts.push_back(vertices[0]);
		tVerts.push_back(vertices[i]);
		tVerts.push_back(vertices[i+1]);
		triangles.push_back(Triangle(tVerts));
	}
}

template <class T>
inline const T& ObjReader::GetElement(const std::vector<T>& elements, std::string& index)
{
	int idx = std::stoi(index);
	if (idx < 0)
		idx = int(elements.size()) + idx;
	else
		idx--;
	return elements[idx];
}