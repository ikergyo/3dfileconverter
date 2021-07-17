#include "converter\ObjReader.h"
#include "converter\STLWriter.h"
#include "tools\ModelCalculator.h"
#include "model\Matrix4x4.h"
#include "model\Vector3.h"

int main() 
{
	std::string source;
	std::string output;
	std::cout << "Give the name of the source file: " << std::endl;
	std::cin >> source;
	std::cout << "Give the name of the output file: " << std::endl;
	std::cin >> output;

	ObjReader objReader;
	std::vector<Triangle> triangles = objReader.ReadTriangles("examples\\" + source);

	Matrix4x4 scaleMatrix;
	scaleMatrix.SetScale(Vector3(1.0f, 1.0f, 1.0f));

	Matrix4x4 translateMatrix;
	translateMatrix.SetTranslation(Vector3(0.0f, 0.0f, 0.0f));

	Matrix4x4 transformationMatrix =  scaleMatrix * translateMatrix;

	ModelCalculator::SetTranformation(triangles, transformationMatrix);

	float surfaceArea = ModelCalculator::GetSurfaceArea(triangles);
	float volume = ModelCalculator::GetVolume(triangles);

	std::cout << "Surface area of the model: " << surfaceArea << std::endl;
	std::cout << "Volume of the model: " << volume << std::endl;


	Vector3 testPointInside(0.38f, -0.1f, 0.1f);
	Vector3 testPointOutside(5.5f, 5.5f, 5.5f);

	bool insidePoint = ModelCalculator::IsPointInsideTheModel(testPointInside, triangles);
	bool outsidePoint = ModelCalculator::IsPointInsideTheModel(testPointOutside, triangles);


	std::cout << "Inside point: " << (insidePoint == true ? "True" : "False") << std::endl;
	std::cout << "Outside point: " << (outsidePoint == true ? "True" : "False") << std::endl;

	STLWriter stlWriter;
	stlWriter.WriteTriangles(triangles, "examples\\" + output);

}