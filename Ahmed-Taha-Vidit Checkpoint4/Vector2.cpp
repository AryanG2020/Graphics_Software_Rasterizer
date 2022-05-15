

#include "Vector2.h"
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Vector2::Vector2() {
    x = 0.0;
    y = 0.0;
}

Vector2::Vector2(float input1, float input2) {
    x = input1;
    y = input2;
}

Vector2 Vector2::operator+(Vector2& other) {
    Vector2 result = Vector2(x + other.x, y + other.y);
    return result;
}

Vector2 Vector2::operator-(Vector2& other) {
    Vector2 result = Vector2(x - other.x, y - other.y);
    return result;
}

Vector2 Vector2::operator*(float other) {
    Vector2 result = Vector2( other * x , other * y );
    return result;
}

float Vector2::magnitude() {
    float result = sqrt(pow(x, 2) + pow(y, 2));
    return result;
}

float Vector2::dot(Vector2 input) {
    float result = (x * input.x) + (y * input.y);
    return result;
}

Vector2 Vector2::normalize() {
    Vector2 result;
    float magnitudeResult = 1/magnitude();
    result.x = magnitudeResult * x;
    result.y = magnitudeResult * y;
    return result;
}

Vector2 Vector2::prependicular() {
    Vector2 result;
    result.x = -y;
    result.y = x;
    return result;
}

float determinant(Vector2 a, Vector2 b) {
    float result = (b.x * a.y) - (a.x * b.y);
    return result;
}

Vector4::Vector4()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
    w = 0.0;
}

Vector4::Vector4(float pX, float pY, float pZ, float pW)
{
    x = pX;
    y = pY;
    z = pZ;
    w = pW;
}

Vector4 Vector4::operator*(float other)
{
    
    Vector4 result = Vector4(other * x, other * y,  other * z, other * w);
    return result;
}

Vector4 Vector4::operator+(Vector4& other)
{
    Vector4 result = Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    return result;
}

Vector4 Vector4::operator-(Vector4& other)
{
    Vector4 result = Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    return result;
}

float Vector4::magnitude()
{
    float result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    return result;
}

Vector4 Vector4::normalize() {
    Vector4 result;
    float magnitudeResult = 1 / magnitude();
    result.x = magnitudeResult * x;
    result.y = magnitudeResult * y;
    result.z = magnitudeResult * z;
    result.w = magnitudeResult * w;
    return result;
}

float Vector4::dot(Vector4 input) {
    float result = (x * input.x) + (y * input.y) + (z * input.z) + (w * input.w);
    return result;
}
void Vector4::print()
{
    cout << x << " " << y << " " << z << " " << w << endl;
}

Vector4 Vector4::cross(Vector4 other)
{
	Vector4 crossProduct = Vector4(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x, 1);
	return crossProduct;
}

