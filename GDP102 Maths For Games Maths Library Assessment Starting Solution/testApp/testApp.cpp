// testApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"

int main()
{
    Vector2 v0(2, 3);
    Vector2 v1(4, 6);

    Vector4 v2(0, 0, 0, 178.54f);
    float mag = v2.magnitude();
    //Vector2 v2 = v0 -= v1;
    std::cout << mag;
}
