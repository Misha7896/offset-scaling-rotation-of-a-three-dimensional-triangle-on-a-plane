#pragma once
#include <iostream>
#include <ctype.h>
#include <conio.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

class Corners
{
public:
	float x;
	float y;
	float z;

	Corners(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	friend void FOO(Corners& A, Corners& B, Corners& C);
	friend void FOO2(Corners& A, Corners& B, Corners& C, Corners& D, float& Turn);
	friend void FOO3(Corners& A, Corners& B, Corners& C, Corners& D, float& Turn);
	friend void FOO4(Corners& A, Corners& B, Corners& C, Corners& D, float& Turn);
};
