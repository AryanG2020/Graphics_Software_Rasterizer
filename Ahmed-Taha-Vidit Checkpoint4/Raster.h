

#ifndef Raster_h
#define Raster_h
#include "Color.h"
#include "Triangle2D.h"
#include "Model.h"

class Raster
{
public:
    Raster();
    Raster(int pWidth, int pHeight, Color pFillColor);
    ~Raster();
    int getWidth();
    int getHeight();
    Color getColorPixel(int x, int y);
    void setColorPixel(int x, int y, Color pFillColor);
    float getDepthPixel(int x, int y);
    void setDepthPixel(int x, int y, float depth);
    void clear(Color pFillColor);
    void clear(float depth);
    void writeToPPM();
    void drawLineDDA(float x1, float y1, float x2, float y2, Color fillColor);
    void drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2);
    void drawTriangle_DotProduct(Triangle2D t1);
    void drawTriangle3D_Barycentric(Triangle3D T);
    void drawModel(Model m);

private:
    int width;
    int height;
    Color* pixels;
    float* depthPixels;
    bool inside(float x, float y, Triangle2D t);
    
    
};


#endif 
