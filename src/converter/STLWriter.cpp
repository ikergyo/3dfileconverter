#include "STLWriter.h"
#include <fstream>

bool STLWriter::WriteTriangles(std::vector<Triangle>& triangles, std::string filename)
{
	std::fstream output_file;
	output_file.open(filename, std::ios::out | std::ios::binary);

	std::string header_text = filename + " - file";
	char header[80];
	strncpy_s(header, header_text.c_str(), sizeof(header) - 1);
	unsigned long triangle_num = triangles.size();

	char attribute[2] = "0";

	output_file.write(header, sizeof(header));
	output_file.write((char*)&triangle_num, 4);

	for (int i = 0; i < triangles.size(); i++)
	{
		output_file.write((char*)&triangles[i].normal.x, sizeof(triangles[i].normal.x));
		output_file.write((char*)&triangles[i].normal.y, sizeof(triangles[i].normal.y));
		output_file.write((char*)&triangles[i].normal.z, sizeof(triangles[i].normal.z));

		for (int j = 0; j < triangles[i].vertices.size(); j++)
		{
			output_file.write((char*)&triangles[i].vertices[j].Position.x, sizeof(triangles[i].vertices[j].Position.x));
			output_file.write((char*)&triangles[i].vertices[j].Position.y, sizeof(triangles[i].vertices[j].Position.y));
			output_file.write((char*)&triangles[i].vertices[j].Position.z, sizeof(triangles[i].vertices[j].Position.z));
		}
		
		output_file.write(attribute, 2);
	}

	output_file.close();

	return true;
}
