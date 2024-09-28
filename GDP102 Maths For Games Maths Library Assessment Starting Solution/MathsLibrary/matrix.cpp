#include "matrix.h"

Matrix2::Matrix2()
{
	//Sets the entire matrix to 0;
	memset(this, 0, sizeof(float) * 2 * 2);
}

Matrix2::Matrix2(float _00, float _01, float _10, float _11)
{
	data[0][0] = _00;
	data[1][0] = _01;
	data[0][1] = _10;
	data[1][1] = _11;
}

Matrix2::Matrix2(const Matrix2& other)
{
	memcpy(this, &other, sizeof(float) * 2 * 2);
}

Matrix2& Matrix2::operator = (const Matrix2& other)
{
	memcpy(this, &other, sizeof(float) * 2 * 2);
	return *this;
}

Vector2& Matrix2::operator[] (int index)
{
	return axis[index];
}

const Vector2& Matrix2::operator[] (int index) const
{
	return axis[index];
}

void Matrix2::setIdentity()
{
	data[0][0] = 1;
	data[1][0] = 0;
	data[0][1] = 0;
	data[1][1] = 1;
}

Matrix2 Matrix2::transposed() const
{
	Matrix2 result(*this);
	float temp = 0;

	temp = result.data[0][1];
	result.data[0][1] = result.data[1][0];
	result.data[1][0] = temp;

	return result;
}

Matrix2 Matrix2::operator * (const Matrix2& other) const
{
	Matrix2 result;

	result.data[0][0] = (data[0][0] * other.data[0][0]) + (data[1][0] * other.data[0][1]);
	result.data[1][0] = (data[0][0] * other.data[1][0]) + (data[1][0] * other.data[1][1]);

	result.data[0][1] = (data[0][1] * other.data[0][0]) + (data[1][1] * other.data[0][1]);
	result.data[1][1] = (data[0][1] * other.data[1][0]) + (data[1][1] * other.data[1][1]);

	return result;
}

Vector2 Matrix2::operator* (const Vector2& v) const
{
	Vector2 result;

	result.x = (data[0][0] * v.x) + (data[1][0] * v.y);
	result.y = (data[0][1] * v.x) + (data[1][1] * v.y);

	return result;

}

//Constructors
Matrix3::Matrix3()
{
	//Sets the entire matrix to 0;
	memset(this, 0, sizeof(float) * 3 * 3);
}

Matrix3::Matrix3(float _00, float _01, float _02,
	float _10, float _11, float _12,
	float _20, float _21, float _22)
{
	data[0][0] = _00;
	data[1][0] = _01;
	data[2][0] = _02;

	data[0][1] = _10;
	data[1][1] = _11;
	data[2][1] = _12;

	data[0][2] = _20;
	data[1][2] = _21;
	data[2][2] = _22;
}

Matrix3::Matrix3(const Matrix3& other)
{
	memcpy(this, &other, sizeof(float) * 3 * 3);
}

Matrix3& Matrix3::operator = (const Matrix3& other)
{
	memcpy(this, &other, sizeof(float) * 3 * 3);
	return *this;
}

Vector3& Matrix3::operator [] (int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator[] (int index) const
{
	return axis[index];
}

void Matrix3::setIdentity()
{
	data[0][0] = 1;
	data[0][1] = 0;
	data[0][2] = 0;

	data[1][0] = 0;
	data[1][1] = 1;
	data[1][2] = 0;

	data[2][0] = 0;
	data[2][1] = 0;
	data[2][2] = 1;
}

Matrix3 Matrix3::transposed() const
{
	Matrix3 result(*this);
	float temp = 0;

	temp = result.data[0][1];
	result.data[0][1] = result.data[1][0];
	result.data[1][0] = temp;

	temp = result.data[0][2];
	result.data[0][2] = result.data[2][0];
	result.data[2][0] = temp;

	temp = result.data[1][2];
	result.data[1][2] = result.data[2][1];
	result.data[2][1] = temp;

	return result;
}

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;

	result.data[0][0] = (data[0][0] * other.data[0][0]) + (data[1][0] * other.data[0][1]) + (data[2][0] * other.data[0][2]);
	result.data[1][0] = (data[0][0] * other.data[1][0]) + (data[1][0] * other.data[1][1]) + (data[2][0] * other.data[1][2]);
	result.data[2][0] = (data[0][0] * other.data[2][0]) + (data[1][0] * other.data[2][1]) + (data[2][0] * other.data[2][2]);

	result.data[0][1] = (data[0][1] * other.data[0][0]) + (data[1][1] * other.data[0][1]) + (data[2][1] * other.data[0][2]);
	result.data[1][1] = (data[0][1] * other.data[1][0]) + (data[1][1] * other.data[1][1]) + (data[2][1] * other.data[1][2]);
	result.data[2][1] = (data[0][1] * other.data[2][0]) + (data[1][1] * other.data[2][1]) + (data[2][1] * other.data[2][2]);

	result.data[0][2] = (data[0][2] * other.data[0][0]) + (data[1][2] * other.data[0][1]) + (data[2][2] * other.data[0][2]);
	result.data[1][2] = (data[0][2] * other.data[1][0]) + (data[1][2] * other.data[1][1]) + (data[2][2] * other.data[1][2]);
	result.data[2][2] = (data[0][2] * other.data[2][0]) + (data[1][2] * other.data[2][1]) + (data[2][2] * other.data[2][2]);

	return result;
}

Vector3 Matrix3::operator * (const Vector3& v) const
{
	Vector3 result;
	result.x = (data[0][0] * v.x) + (data[1][0] * v.y) + (data[2][0] * v.z);
	result.y = (data[0][1] * v.x) + (data[1][1] * v.y) + (data[2][1] * v.z);
	result.z = (data[0][2] * v.x) + (data[1][2] * v.y) + (data[2][2] * v.z);
	return result;
}

Matrix4::Matrix4()
{
	//Sets the entire matrix to 0;
	memset(this, 0, sizeof(float) * 4 * 4);
}

Matrix4::Matrix4(const Matrix4& other)
{
	memcpy(this, &other, sizeof(float) * 4 * 4);
}

Matrix4::Matrix4(float _00, float _01, float _02, float _03,
	float _10, float _11, float _12, float _13,
	float _20, float _21, float _22, float _23,
	float _30, float _31, float _32, float _33)
{
	data[0][0] = _00;
	data[1][0] = _01;
	data[2][0] = _02;
	data[3][0] = _03;

	data[0][1] = _10;
	data[1][1] = _11;
	data[2][1] = _12;
	data[3][1] = _13;

	data[0][2] = _20;
	data[1][2] = _21;
	data[2][2] = _22;
	data[3][2] = _23;
	
	data[0][3] = _30;
	data[1][3] = _31;
	data[2][3] = _32;
	data[3][3] = _33;
}

Matrix4& Matrix4::operator = (const Matrix4& other)
{
	memcpy(this, &other, sizeof(float) * 4 * 4);
	return *this;
}

Vector4& Matrix4::operator[] (int index)
{
	return axis[index];
}

const Vector4& Matrix4::operator[] (int index) const
{
	return axis[index];
}

void Matrix4::setIdentity()
{
	memset(this, 0, sizeof(float) * 4 * 4);
	data[0][0] = 1;
	data[1][1] = 1;
	data[2][2] = 1;
	data[3][3] = 1;
}

Matrix4 Matrix4::transposed() const
{
	Matrix4 result(*this);
	float temp = 0;

	temp = result.data[0][1];
	result.data[0][1] = result.data[1][0];
	result.data[1][0] = temp;

	temp = result.data[0][2];
	result.data[0][2] = result.data[2][0];
	result.data[2][0] = temp;

	temp = result.data[0][3];
	result.data[0][3] = result.data[3][0];
	result.data[3][0] = temp;

	temp = result.data[1][2];
	result.data[1][2] = result.data[2][1];
	result.data[2][1] = temp;

	temp = result.data[1][3];
	result.data[1][3] = result.data[3][1];
	result.data[3][1] = temp;

	temp = result.data[2][3];
	result.data[2][3] = result.data[3][2];
	result.data[3][2] = temp;

	return result;
}

Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;

	result.data[0][0] = (data[0][0] * other.data[0][0]) + (data[1][0] * other.data[0][1]) + (data[2][0] * other.data[0][2]) + (data[3][0] * other.data[0][3]);
	result.data[1][0] = (data[0][0] * other.data[1][0]) + (data[1][0] * other.data[1][1]) + (data[2][0] * other.data[1][2]) + (data[3][0] * other.data[1][3]);
	result.data[2][0] = (data[0][0] * other.data[2][0]) + (data[1][0] * other.data[2][1]) + (data[2][0] * other.data[2][2]) + (data[3][0] * other.data[2][3]);
	result.data[3][0] = (data[0][0] * other.data[3][0]) + (data[1][0] * other.data[3][1]) + (data[2][0] * other.data[3][2]) + (data[3][0] * other.data[3][3]);

	result.data[0][1] = (data[0][1] * other.data[0][0]) + (data[1][1] * other.data[0][1]) + (data[2][1] * other.data[0][2]) + (data[3][1] * other.data[0][3]);
	result.data[1][1] = (data[0][1] * other.data[1][0]) + (data[1][1] * other.data[1][1]) + (data[2][1] * other.data[1][2]) + (data[3][1] * other.data[1][3]);
	result.data[2][1] = (data[0][1] * other.data[2][0]) + (data[1][1] * other.data[2][1]) + (data[2][1] * other.data[2][2]) + (data[3][1] * other.data[2][3]);
	result.data[3][1] = (data[0][1] * other.data[3][0]) + (data[1][1] * other.data[3][1]) + (data[2][1] * other.data[3][2]) + (data[3][1] * other.data[3][3]);

	result.data[0][2] = (data[0][2] * other.data[0][0]) + (data[1][2] * other.data[0][1]) + (data[2][2] * other.data[0][2]) + (data[3][2] * other.data[0][3]);
	result.data[1][2] = (data[0][2] * other.data[1][0]) + (data[1][2] * other.data[1][1]) + (data[2][2] * other.data[1][2]) + (data[3][2] * other.data[1][3]);
	result.data[2][2] = (data[0][2] * other.data[2][0]) + (data[1][2] * other.data[2][1]) + (data[2][2] * other.data[2][2]) + (data[3][2] * other.data[2][3]);
	result.data[3][2] = (data[0][2] * other.data[3][0]) + (data[1][2] * other.data[3][1]) + (data[2][2] * other.data[3][2]) + (data[3][2] * other.data[3][3]);

	result.data[0][3] = (data[0][3] * other.data[0][0]) + (data[1][3] * other.data[0][1]) + (data[2][3] * other.data[0][2]) + (data[3][3] * other.data[0][3]);
	result.data[1][3] = (data[0][3] * other.data[1][0]) + (data[1][3] * other.data[1][1]) + (data[2][3] * other.data[1][2]) + (data[3][3] * other.data[1][3]);
	result.data[2][3] = (data[0][3] * other.data[2][0]) + (data[1][3] * other.data[2][1]) + (data[2][3] * other.data[2][2]) + (data[3][3] * other.data[2][3]);
	result.data[3][3] = (data[0][3] * other.data[3][0]) + (data[1][3] * other.data[3][1]) + (data[2][3] * other.data[3][2]) + (data[3][3] * other.data[3][3]);

	return result;
}

Vector4 Matrix4::operator * (const Vector4& v) const
{
	Vector4 result;

	result.x = (data[0][0] * v.x) + (data[1][0] * v.y) + (data[2][0] * v.z) + (data[3][0] * v.w);
	result.y = (data[0][1] * v.x) + (data[1][1] * v.y) + (data[2][1] * v.z) + (data[3][1] * v.w);
	result.z = (data[0][2] * v.x) + (data[1][2] * v.y) + (data[2][2] * v.z) + (data[3][2] * v.w);
	result.w = (data[0][3] * v.x) + (data[1][3] * v.y) + (data[2][3] * v.z) + (data[3][3] * v.w);

	return result;
}