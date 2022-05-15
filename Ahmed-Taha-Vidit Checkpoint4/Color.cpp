

#include "Color.h"
#include <math.h>

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
    alpha = 1.0f;
}

Color::Color(float pRed, float pGreen, float pBlue, float pAlpha)
{
    red = pRed;
    green = pGreen;
    blue = pBlue;
    alpha = pAlpha;
    clamp();
}

void Color::clamp()
{
    
    red = fmin(red, 1.0f);
    red = fmax(red, 0.0f);
    blue = fmin(blue, 1.0f);
    blue = fmax(blue, 0.0f);
    green = fmin(green, 1.0f);
    green = fmax(green, 0.0f);
    alpha = fmin(alpha, 1.0f);
    alpha = fmax(alpha, 0.0f);

}

Color Color::operator+(Color other) {

	Color newColor(red, green, blue, alpha);
	newColor.red += other.red;
	newColor.green += other.green;
	newColor.blue += other.blue;
	newColor.alpha += other.alpha;
	newColor.clamp(); 
	return newColor;
}

Color Color::operator-(Color& other) {
    Color x = Color(red - other.red, green - other.green, blue - other.blue, alpha - other.alpha);
    return x;
}

Color Color::operator*(float other) {
    Color x = Color(red * other, green * other, blue * other, alpha * other);
    return x;
}
