

#ifndef Model_h
#define Model_h

#include <stdio.h>
#include <vector>
#include "Triangle2D.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Model{
private:
    vector<Triangle3D> triangles;
    
public:
    Model();
    int numTriangles();
    Triangle3D operator[](int i);
    void transform(Matrix4 other);
    void readFromOBJFile(string filepath, Color pFillColor);
		void homogenize();
    void performBackfaceCulling(Vector4 eye, Vector4 spot);
};

#endif 
