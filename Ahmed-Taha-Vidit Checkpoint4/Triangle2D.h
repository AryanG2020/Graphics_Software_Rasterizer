

#ifndef Triangle2D_h
#define Triangle2D_h

#include "Vector2.h"
#include "Color.h"
#include "Matrix.h"


struct Triangle3D
{
    Vector4 v1;
    Vector4 v2;
    Vector4 v3;
    
    Color c1;
    Color c2;
    Color c3;
    
    bool shouldDraw;
    
    Triangle3D();
    Triangle3D(Vector4 pV1, Vector4 pV2, Vector4 pV3, Color pC1, Color pC2, Color pC3);
    void transform(Matrix4 other);
};

struct Triangle2D
{
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;
    Color c1;
    Color c2;
    Color c3;
    Triangle2D();
    Triangle2D(Triangle3D T);
    Triangle2D(Vector2 point1, Vector2 point2, Vector2 point3, Color color1, Color color2, Color color3);
    void calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3);
    
};


#endif 