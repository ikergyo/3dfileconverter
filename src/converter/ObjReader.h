#pragma once
#include "..\interface\IModelReader.h"
#include <string>
#include <fstream>
#include <functional>
#include <iostream>


class ObjReader : IModelReader
{
public:
	ObjReader();
	~ObjReader();
	std::vector<Triangle> ReadTriangles(std::string filename);

private:
	size_t GetCommand(const std::string& line, std::string& oCommand);
	std::vector<std::string> GetValuesOfLine(const std::string& line, const std::string& delimeter);
	Vertex GetVertexOfString(const std::string& line);
	void AddTriangles(std::vector<Triangle>& triangles, std::vector<Vertex>& vertices);
	std::vector<std::string> split(const std::string& line, const std::string& delimiter);
	template <class T>
	inline const T& GetElement(const std::vector<T>& elements, std::string& index);

	std::vector<Vector3> vPos;
	std::vector<Vector2> vText;
	std::vector<Vector3> vNorm;
	std::unique_ptr<std::vector<Vertex>> Vertices;
};

