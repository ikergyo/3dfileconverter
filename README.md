# Example program usage
In the beginning, it asks the input file name from the user. The file should be in the examples folder, and the user should pass the extension as well.
The second input is the output file name, which will be created in the "examples" folder.

Example first input: box.obj

Example second input: box.stl

Default, there is no transformation. The implemented transformations are: scale and translate. Those can be added with coding, in the main function.


# Implementation
## Interfaces
### IModelReader
This is responsible for the reader requirements. Which class implements, it should have a function which returns with a vector of triangles. So it should create triangles based on the actual file format.
Only the ObjReader class implements the interface, which is responsible for reading an .obj file.

### IModelWriter
This interface requires a WriteTriangles method, which has a bool return type and two input parameters: triangles vector and filename.
Which class implements this interface, should create an output file based on the file name, from the given triangles.
The STLWriter class implements that interface which can create a binary stl file from the triangles.


## Converter
There are two converters. 
### ObjReader
The first is the ObjReader which can read an obj file and create triangles based on that.
It can read the v, vt, vn, and f lines. Based on the line, it creates a list of vertices or texture coords or normals and at the face creation, it creates the triangles.
If the face contains more than 3 vertices, it can handle it and generate triangles from it.

### STLWriter
STLWriter can write a binary .stl file from the triangles. It implements the IModelWriter interface and it has only the WriteTriangles method.
That method is responsible for everything, creating the file and write the data.

## Model
The model folder contains the basic classes which used to store mesh information and helps in the calculations.
There are some base classes: Vector2, Vector3, Vector4, Matrix4x4 (helper class to create 4 by 4 matrices for transformations in a column-major way).
The Vertex class has a Vector3 for the vertex position, Vector3 for the vertex normals and a Vector2 for the texture coords.
The Triangle has a std::vector to store the vertices that belong to that triangle. 

## Tools
### ModelCalculator
It is responsible for the 3D model calculations. It has the GetSurfaceArea, it calculates the surface area of the model (based on the triangles).
The GetVolume calculates the volume of the model, and the IsPointInsideTheModel function calculates the point is inside the given model or not.
For the inside-outside checking, it checks the direction between the middle of every triangle and the point, and using the dot product and also the surface normal it can decide the point is on which side of the triangle.
Finally, it has a SetTranformation method, which goes through the triangles and applies the transformation on every vertex.



# TODO
## Math
Implementing an efficient math lib or using an existing one (dot product and cross product).

## Improving inside-outside checking
Find a more efficient and accurate way to check that calculation. Actually, it's not working with complex meshes.

