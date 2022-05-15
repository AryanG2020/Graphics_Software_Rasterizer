

#ifndef Color_h
#define Color_h
#define Red Color(1.0,0.0,0.0,1.0)
#define Green Color(0.0,1.0,0.0,1.0)
#define Blue Color(0.0,0.0,1.0,1.0)
#define Black Color(0.0,0.0,0.0,1.0)
#define White Color(1.0,1.0,1.0,1.0)
#define Background Color(1.0,1.0,1.0,1.0)


struct Color
{

    float red;
    float green;
    float blue;
    float alpha;
    Color();
    Color(float pRed, float pGreen, float pBlue, float pAlpha);
    Color operator+(Color other);
    Color operator-(Color& other);
    Color operator*(float other);
    void clamp();

};

#endif 
