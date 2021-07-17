#include "Triangle.h"


Triangle::Triangle() 
{

}
Triangle::Triangle(std::vector<Vertex> vertices) : vertices(vertices)
{
	GetNormal();
}
Triangle::~Triangle() 
{

}
float Triangle::GetSurfaceArea() const
{
	Vector3 AB = vertices[1].Position - vertices[0].Position;
	Vector3 AC = vertices[2].Position - vertices[0].Position;
	float fir = (AB.y * AC.z - AB.z * AC.y) * (AB.y * AC.z - AB.z * AC.y);
	float sec = (AB.z * AC.x - AB.x * AC.z) * (AB.z * AC.x - AB.x * AC.z);
	float thi = (AB.x * AC.y - AB.y * AC.x) * (AB.x * AC.y - AB.y * AC.x);
	float s = (1.0f / 2.0f) * (sqrt(fir + sec + thi));
	return s;
}

float Triangle::GetSignedVolume() const
{
	Vector3 A = vertices[0].Position;
	Vector3 B = vertices[1].Position;
	Vector3 C = vertices[2].Position;

	float vCBA = C.x * B.y * A.z;
	float vBCA = B.x * C.y * A.z;
	float vCAB = C.x * A.y * B.z;
	float vACB = A.x * C.y * B.z;
	float vBAC = B.x * A.y * C.z;
	float vABC = A.x * B.y * C.z;

	return (1.0f / 6.0f) * (-vCBA + vBCA + vCAB - vACB - vBAC + vABC);
}

void Triangle::GetNormal() 
{
	Vector3 V = vertices[1].Position - vertices[0].Position;
	Vector3 W = vertices[2].Position - vertices[0].Position;
	Vector3 n;
	n.x = (V.y * W.z) - (V.z * W.y);
	n.y = (V.z * W.x) - (V.x * W.z);
	n.z = (V.x * W.y) - (V.y * W.z);

	float n_magnitude = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	if(n_magnitude > 0.000001f)
		n = n / n_magnitude;
	normal = n;	
}