

#include "Triangle2D.h"
#include "Raster.h"
#include "Vector2.h"
#include "Color.h"
#include "Matrix.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Triangle2D::Triangle2D() {
    v1 = Vector2(0.0, 0.0);
    v2 = Vector2(0.0, 0.0);
    v3 = Vector2(0.0, 0.0);
    c1 = Black;
    c2 = Black;
    c3 = Black;
    }

Triangle2D::Triangle2D(Vector2 point1, Vector2 point2, Vector2 point3, Color color1, Color color2, Color color3) {
    v1 = point1;
    v2 = point2;
    v3 = point3;
    c1 = color1;
    c2 = color2;
    c3 = color3;
}

void Triangle2D::calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3) {

    lambda1 = determinant(v1 - v2, P - v2)/determinant(v1 - v2, v3 - v2);
    lambda2 = determinant(P - v2, v3 - v2) / determinant(v1 - v2, v3 - v2);
    lambda3 = 1.0 - lambda1 - lambda2;
}

Triangle3D::Triangle3D()
{
    v1 = Vector4(0.0, 0.0, 0.0, 1.0);
    v2 = Vector4(0.0, 0.0, 0.0, 1.0);
    v3 = Vector4(0.0, 0.0, 0.0, 1.0);
    
    c1 = White;
		c2 = White;
		c3 = White;

    shouldDraw = true;
}

Triangle3D::Triangle3D(Vector4 pV1, Vector4 pV2, Vector4 pV3, Color pC1, Color pC2, Color pC3)
{
    v1 = pV1;
    v2 = pV2;
    v3 = pV3;
    
    c1 = pC1;
    c2 = pC2;
    c3 = pC3;

    shouldDraw = true;
}

void Triangle3D::transform(Matrix4 other)
{
    Vector4 one = other * v1;
    Vector4 two = other * v2;
    Vector4 three = other * v3;
    v1 = one;
    v2 = two;
    v3 = three;
}

Triangle2D::Triangle2D(Triangle3D T)
{
		v1 = Vector2(T.v1.x, T.v1.y);
		v2 = Vector2(T.v2.x, T.v2.y);
		v3 = Vector2(T.v3.x, T.v3.y);

    c1 = T.c1;
    c2 = T.c2;
    c3 = T.c3;
}


