

#ifndef Vector2_h
#define Vector2_h

struct Vector2
{
    float x;
    float y;
    Vector2();
    Vector2(float input1, float input2);
    Vector2 operator+(Vector2& other);
    Vector2 operator-(Vector2& other);
    Vector2 operator*(float other);
    float magnitude();
    float dot(Vector2 input);
    Vector2 normalize();
    Vector2 prependicular();

};

struct Vector4
{
    float x;
    float y;
    float z;
    float w;
    Vector4();
    Vector4(float pX, float pY, float pZ, float pW);
    Vector4 operator+(Vector4& other);
    Vector4 operator-(Vector4& other);
    Vector4 operator*(float other);
    float magnitude();
    Vector4 normalize();
    float dot(Vector4 other);
    void print();
		Vector4 cross(Vector4 other);
};

float determinant(Vector2 a, Vector2 b);

#endif 
