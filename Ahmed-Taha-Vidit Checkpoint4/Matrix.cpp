

#include "Matrix.h"
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Matrix4::Matrix4()
{
    ix = 1;
    jx = 0;
    kx = 0;
    ox = 0;
    iy = 0;
    jy = 1;
    ky = 0;
    oy = 0;
    iz = 0;
    jz = 0;
    kz = 1;
    oz = 0;
    iw = 0;
    jw = 0;
    kw = 0;
    ow = 1;
}

Matrix4::Matrix4(float pix, float pjx, float pkx, float pox,
    float piy, float pjy, float pky, float poy,
    float piz, float pjz, float pkz, float poz,
    float piw, float pjw, float pkw, float pow)
{
    ix = pix;
    jx = pjx;
    kx = pkx;
    ox = pox;
    iy = piy;
    jy = pjy;
    ky = pky;
    oy = poy;
    iz = piz;
    jz = pjz;
    kz = pkz;
    oz = poz;
    iw = piw;
    jw = pjw;
    kw = pkw;
    ow = pow;
}

Vector4 Matrix4::operator*(Vector4 other)
{
  
	Vector4 result;
    result.x = (other.x * ix) + (other.y * jx) + (other.z * kx) + (other.w * ox);
    result.y = (other.x * iy) + (other.y * jy) + (other.z * ky) + (other.w * oy);
    result.z = (other.x * iz) + (other.y * jz) + (other.z * kz) + (other.w * oz);
    result.w = (other.x * iw) + (other.y * jw) + (other.z * kw) + (other.w * ow);
    return result;


}

Matrix4 Matrix4::operator*(Matrix4 other)
{
	Vector4 one = Vector4(other.ix, other.iy, other.iz, other.iw);
    Vector4 two = Vector4(other.jx, other.jy, other.jz, other.jw);
    Vector4 three = Vector4(other.kx, other.ky, other.kz, other.kw);
    Vector4 four = Vector4(other.ox, other.oy, other.oz, other.ow);
    one =  *this * one;
    two = *this * two;
    three=  *this * three;
    four = *this * four;
    Matrix4 result;
    result.ix = one.x;
    result.iy = one.y;
    result.iz = one.z;
    result.iw = one.w;
    result.jx = two.x;
    result.jy = two.y;
    result.jz = two.z;
    result.jw = two.w;
    result.kx = three.x;
    result.ky = three.y;
    result.kz = three.z;
    result.kw = three.w;
    result.ox = four.x;
    result.oy = four.y;
    result.oz = four.z;
    result.ow = four.w;
		return result;
}

Matrix4 Translate3D(float tX, float tY, float tZ)
{
Matrix4 translate3D = Matrix4(1, 0, 0, tX,
                              0, 1, 0, tY,
                              0, 0, 1, tZ,
                              0, 0, 0, 1);
return translate3D;
}

Matrix4 Scale3D(float sX, float sY, float sZ)
{
Matrix4 scale3D =
Matrix4(sX, 0, 0, 0,
        0, sY, 0, 0,
        0, 0, sZ, 0,
        0, 0, 0, 1);
return scale3D;
}

Matrix4 RotateX3D(float degrees)
{
float radians = degrees * M_PI / 180.0;
Matrix4 rotateX3D =
Matrix4(1, 0, 0, 0,
0, cosf(radians), sinf(radians), 0,
0, -sinf(radians), cosf(radians), 0,
0, 0, 0, 1);
return rotateX3D;
}

Matrix4 RotateY3D(float degrees)
{
float radians = degrees * M_PI / 180.0;
Matrix4 rotateY3D =
Matrix4(cosf(radians), 0, -sinf(radians), 0,
0, 1, 0, 0,
sinf(radians), 0, cosf(radians), 0,
0, 0, 0, 1);
return rotateY3D;
}


Matrix4 RotateZ3D(float degrees)
{

float radians = degrees * (M_PI / 180.0);
Matrix4 rotateZ3D =
Matrix4(cosf(radians), sinf(radians), 0, 0,
-sinf(radians), cosf(radians), 0, 0,
0, 0, 1, 0,
0, 0, 0, 1);
return rotateZ3D;
}

Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ)
{

    Matrix4 rotate3D = RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
return rotate3D;
}

Matrix4 Rotate3D(float degrees, Vector4 vec)
{
		float alpha = atanf(vec.x/vec.z);
    float beta = acosf(vec.y/vec.magnitude());
		alpha = alpha * (180.0/ M_PI);
		beta = beta * (180.0/ M_PI);
    Matrix4 firstStep = RotateY3D(alpha);
    Matrix4 secondStep = RotateX3D(beta);
    Matrix4 thirdStep = RotateY3D(degrees);
    Matrix4 fourthStep = RotateX3D(-beta);
    Matrix4 fifthStep = RotateY3D(-alpha);
    Matrix4 rotate3D = fifthStep * fourthStep * thirdStep * secondStep * firstStep;
    return rotate3D;
}

Matrix4 LookAt(Vector4 eye, Vector4 spot, Vector4 up)
{
	Matrix4 newMatrix;
	Vector4 look = (spot-eye).normalize();
	Vector4 right = look.cross(up).normalize();
	up = up.normalize();
	newMatrix = Translate3D(-eye.x, -eye.y, -eye.z);
	Matrix4 map = Matrix4(right.x, right.y, right.z, 0, up.x, up.y, up.z, 0, -look.x, -look.y, -look.z, 0, 0, 0, 0, 1);
	return map*newMatrix;
}

Matrix4 Orthographic(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
{
	Matrix4 translate = Translate3D(-(minX + maxX)/2, -(minY + maxY)/2, -(minZ + maxZ)/2);
	Matrix4 scale = Scale3D(2/(maxX - minX), 2/(maxY - minY), 2/(maxZ - minZ));
	return scale*translate;
}

Matrix4 Perspective(float fovY, float aspect, float nearZ, float farZ)
{
	float F = 1/(tan((fovY* M_PI / 180.0)/2));
	float val1 = (farZ + nearZ)/(nearZ - farZ);
	float val2 = (2*nearZ*farZ)/(nearZ - farZ);
	Matrix4 perspective = Matrix4(F/aspect, 0, 0, 0,
																0, F, 0, 0,
																0, 0, val1, val2,
																0, 0, -1, 0);
	return perspective;

}

Matrix4 Viewport(float x, float y, float width, float height)
{
	Matrix4 translate1 = Translate3D(x, y, 0);
	Matrix4 scale1 = Scale3D(width, height, 1);
	Matrix4 scale2 = Scale3D(0.5, 0.5, 0.5);
	Matrix4 translate2 = Translate3D(1, 1, -1);
	return translate1*scale1*scale2*translate2;
}

void Matrix4::print()
{
    cout << ix << " " << jx << " " << kx << " " << ox << endl;
    cout << iy << " " << jy << " " << ky << " " << oy << endl;
    cout << iz << " " << jz << " " << kz << " " << oz << endl;
    cout << iw << " " << jw << " " << kw << " " << ow << endl;

}

