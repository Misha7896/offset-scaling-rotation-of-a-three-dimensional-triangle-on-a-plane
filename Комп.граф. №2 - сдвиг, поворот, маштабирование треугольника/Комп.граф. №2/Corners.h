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

	Corners(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	friend void FOO(Corners& A, Corners& B, Corners& C);
};



