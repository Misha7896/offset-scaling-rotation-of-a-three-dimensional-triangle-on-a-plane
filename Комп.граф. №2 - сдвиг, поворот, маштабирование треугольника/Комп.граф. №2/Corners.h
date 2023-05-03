#pragma once
#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")


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


void FOO(Corners& A, Corners& B, Corners& C)
{
	float Max_x = A.x;
	if (Max_x < B.x) Max_x = B.x;
	if (Max_x < C.x) Max_x = C.x;

	float Max_y = A.y;
	if (Max_y < B.y) Max_y = B.y;
	if (Max_y < C.y) Max_y = C.y;

	float Min_x = A.x;
	if (Min_x > B.x) Min_x = B.x;
	if (Min_x > C.x) Min_x = C.x;

	float Min_y = A.y;
	if (Min_y > B.y) Min_y = B.y;
	if (Min_y > C.y) Min_y = C.y;

	float Kab;
	float Bab;

	float Kac;
	float Bac;

	float Kbc;
	float Bbc;

	int index = 1;

	if (A.x != B.x)
	{
		if ((A.y - B.y < 0 && A.x - B.x > 0) || (A.y - B.y > 0 && A.x - B.x < 0)) index = -1;
		Kab = (abs(A.y - B.y) / abs(A.x - B.x)) * index;
		Bab = A.y - Kab * A.x;
	}

	if (A.x != C.x)
	{
		index = 1;
		if ((A.y - C.y < 0 && A.x - C.x > 0) || (A.y - C.y > 0 && A.x - C.x < 0)) index = -1;
		Kac = (abs(A.y - C.y) / abs(A.x - C.x)) * index;
		Bac = A.y - Kac * A.x;
	}

	if (C.x != B.x)
	{
		index = 1;
		if ((C.y - B.y < 0 && C.x - B.x > 0) || (C.y - B.y > 0 && C.x - B.x < 0)) index = -1;
		Kbc = (abs(C.y - B.y) / abs(C.x - B.x)) * index;
		Bbc = B.y - Kbc * B.x;
	}

	float X1;
	float X2;
	float y;


	for (y = Min_y + 1; y < Max_y; y++)
	{
		if (A.x != B.x) X1 = (y - Bab) / Kab;
		else X1 = A.x;

		if (X1 < Min_x || X1 > Max_x)
		{
			if (A.x != C.x) X1 = (y - Bac) / Kac;
			else X1 = A.x;
			if (C.x != B.x) X2 = (y - Bbc) / Kbc;
			else X2 = B.x;
		}
		else
		{
			if (A.x != C.x) X2 = (y - Bac) / Kac;
			else X2 = A.x;

			if (X2 < Min_x || X2 > Max_x)
				if (C.x != B.x)
					X2 = (y - Bbc) / Kbc;
				else X2 = B.x;
		}

		if (A.y == B.y)
		{
			X1 = A.x;
			X2 = B.x;
		}
		if (A.y == C.y)
		{
			X1 = A.x;
			X2 = C.x;
		}
		if (C.y == B.y)
		{
			X1 = C.x;
			X2 = B.x;
		}

		setcolor(RGB(255, 255, 255));
		line(round(X1), round(y), round(X2), round(y));
	}
}
