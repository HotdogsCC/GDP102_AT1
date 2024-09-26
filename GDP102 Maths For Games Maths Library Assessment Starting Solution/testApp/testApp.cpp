// testApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
#include "matrix.h"

int main()
{
    Matrix3 mat(0,1,2,3,4,5,6,7,8);

    std::cout << "[ " << mat.data[0][0] << mat.data[0][1] << mat.data[0][2] << " ]";
}
