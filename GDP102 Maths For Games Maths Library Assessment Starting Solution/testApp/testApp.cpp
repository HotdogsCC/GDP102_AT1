// testApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
#include "matrix.h"

int main()
{
    const float PI = 3.14159265358979323846f;
    Vector3 point(1, 0, 1);
    Matrix3 rotMat;
    rotMat.setIdentity();

    rotMat.setRotateZ(4*PI/3);
    
    Vector3 result;
    result = rotMat * point;

    std::cout << result;

    
}
