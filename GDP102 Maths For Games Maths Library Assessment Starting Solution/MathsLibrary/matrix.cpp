#include "matrix.h"

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
	data[0][1] = _01;
	data[0][2] = _02;

	data[1][0] = _10;
	data[1][1] = _11;
	data[1][2] = _12;

	data[2][0] = _20;
	data[2][1] = _21;
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
	result.data[1][2] = result.data[1][0];
	result.data[1][0] = temp;

	return result;
}

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;

	result.data[0][0] = (data[0][0] * other.data[0][0]) + (data[1][0] * data[0][1]) + (data[2][0] * data[0][2]);

	return result;
}