#include <iostream>
#include <ctype.h>
#include <conio.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Corners.h"

#define SIZE_OF_WINDOW 720 //Размер окна

using namespace std;


int main(void)
{
	initwindow(SIZE_OF_WINDOW, SIZE_OF_WINDOW);

	
	while (1)
	{
		float SHIFT = 5;// Коэффициент сдвиг
		float Scaling = 1.015;	// Коэффициент маштабирования
		float Turn = 0.025;	// Угол в радианах на который вращаем
		float xc, yc;	// средний х, y

		//float Xc, Yc;	// средний y

		Corners A(260, 240);
		Corners B(460, 570);
		Corners C(160, 570);
		Corners D(310, 670);

		//int iw = 2;
		//iw = 3;
		//iw = 4;
		//iw = 5;
		//iw = 6;
		//iw = 7;

		/*float FIG[3][3] = { {A.x, A.y, 1}, {B.x, B.y, 1}, {C.x, C.y, 1} };

		float FIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {A.x, A.y, 1} };

		float FIG[1][3] = { {A.x, A.y, 1} };
		float SDVIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {SHIFT, SHIFT, 1} };*/

		int i, j;
		char BUTTON;

		setcolor(RGB(255, 255, 255));
		line(A.x, A.y, B.x, B.y);
		setcolor(RGB(255, 255, 255));
		line(A.x, A.y, C.x, C.y);
		setcolor(RGB(255, 255, 255));
		line(A.x, A.y, D.x, D.y);

		setcolor(RGB(255, 255, 255));
		line(B.x, B.y, C.x, C.y);
		setcolor(RGB(255, 255, 255));
		line(B.x, B.y, D.x, D.y);

		setcolor(RGB(255, 255, 255));
		line(C.x, C.y, D.x, D.y);

		while (BUTTON = _getch())
		{
			switch (BUTTON)
			{
			//case -32:	// сдвиг
			{
			case 'w':	// вверх
				A.y -= 5;
				B.y -= 5;
				C.y -= 5;
				D.y -= 5;
				break;

			case 's':	// вниз
				A.y += 5;
				B.y += 5;
				C.y += 5;
				D.y += 5;
				break;

			case 'a':	// влево
				A.x -= 5;
				B.x -= 5;
				C.x -= 5;
				D.x -= 5;
				break;

			case 'd':	// вправо
				A.x += 5;
				B.x += 5;
				C.x += 5;
				D.x += 5;
				break;
				//}
				//break;
				}

			// поворот
			{
			case 'q':
				xc = (A.x + B.x + C.x + D.x) / 4;
				yc = (A.y + B.y + C.y + D.y) / 4;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;
				D.x -= xc;
				D.y -= yc;

				A.x = ((A.x * cos(-Turn)) - (A.y * sin(-Turn))) * 1.0003125;
				A.y = ((A.x * sin(-Turn)) + (A.y * cos(-Turn))) * 1.0003125;
				B.x = ((B.x * cos(-Turn)) - (B.y * sin(-Turn))) * 1.0003125;
				B.y = ((B.x * sin(-Turn)) + (B.y * cos(-Turn))) * 1.0003125;
				C.x = ((C.x * cos(-Turn)) - (C.y * sin(-Turn))) * 1.0003125;
				C.y = ((C.x * sin(-Turn)) + (C.y * cos(-Turn))) * 1.0003125;
				D.x = ((D.x * cos(-Turn)) - (D.y * sin(-Turn))) * 1.0003125;
				D.y = ((D.x * sin(-Turn)) + (D.y * cos(-Turn))) * 1.0003125;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;
				D.x += xc;
				D.y += yc;

				break;

			case 'e':
				xc = (A.x + B.x + C.x + D.x) / 4;
				yc = (A.y + B.y + C.y + D.y) / 4;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;
				D.x -= xc;
				D.y -= yc;

				A.x = ((A.x * cos(Turn)) - (A.y * sin(Turn))) * 1.0003125;
				A.y = ((A.x * sin(Turn)) + (A.y * cos(Turn))) * 1.0003125;
				B.x = ((B.x * cos(Turn)) - (B.y * sin(Turn))) * 1.0003125;
				B.y = ((B.x * sin(Turn)) + (B.y * cos(Turn))) * 1.0003125;
				C.x = ((C.x * cos(Turn)) - (C.y * sin(Turn))) * 1.0003125;
				C.y = ((C.x * sin(Turn)) + (C.y * cos(Turn))) * 1.0003125;
				D.x = ((D.x * cos(Turn)) - (D.y * sin(Turn))) * 1.0003125;
				D.y = ((D.x * sin(Turn)) + (D.y * cos(Turn))) * 1.0003125;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;
				D.x += xc;
				D.y += yc;

				break;
			}

			// масштабирование
			{
			case '+':	// увеличение

				xc = (A.x + B.x + C.x + D.x) / 4;
				yc = (A.y + B.y + C.y + D.y) / 4;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;
				D.x -= xc;
				D.y -= yc;

				//putpixel(xc, yc, RGB(0, 255, 0));

				A.x *= Scaling;
				A.y *= Scaling;
				B.x *= Scaling;
				B.y *= Scaling;
				C.x *= Scaling;
				C.y *= Scaling;
				D.x *= Scaling;
				D.y *= Scaling;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;
				D.x += xc;
				D.y += yc;

				break;

			case '-':	// масштабирование

				xc = (A.x + B.x + C.x + D.x) / 4;
				yc = (A.y + B.y + C.y + D.y) / 4;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;
				D.x -= xc;
				D.y -= yc;

				A.x /= Scaling;
				A.y /= Scaling;
				B.x /= Scaling;
				B.y /= Scaling;
				C.x /= Scaling;
				C.y /= Scaling;
				D.x /= Scaling;
				D.y /= Scaling;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;
				D.x += xc;
				D.y += yc;

				break;
			}
			}

			cleardevice();

			// закраска
			//FOO(A, B, C);
			setcolor(RGB(255, 255, 255));
			line(A.x, A.y, B.x, B.y);
			setcolor(RGB(255, 255, 255));
			line(A.x, A.y, C.x, C.y);
			setcolor(RGB(255, 255, 255));
			line(A.x, A.y, D.x, D.y);

			setcolor(RGB(255, 255, 255));
			line(B.x, B.y, C.x, C.y);
			setcolor(RGB(255, 255, 255));
			line(B.x, B.y, D.x, D.y);

			setcolor(RGB(255, 255, 255));
			line(C.x, C.y, D.x, D.y);

			//setcolor(RGB(100, 100, 255));
			//line(round(A.x), round(A.y), round(B.x), round(B.y));
			//setcolor(RGB(0, 255, 0));
			//line(round(C.x), round(C.y), round(B.x), round(B.y));
			//setcolor(RGB(255, 200, 0));
			//line(round(A.x), round(A.y), round(C.x), round(C.y));
		}
	}
	return 0;
}

void FOO(Corners& A, Corners& B, Corners& C)
{
	float Max_x = A.x;		// Нахожу максимальный x
	if (Max_x < B.x) Max_x = B.x;
	if (Max_x < C.x) Max_x = C.x;

	float Max_y = A.y;		// Нахожу максимальный y
	if (Max_y < B.y) Max_y = B.y;
	if (Max_y < C.y) Max_y = C.y;

	float Min_x = A.x;		// Нахожу минимальный x
	if (Min_x > B.x) Min_x = B.x;
	if (Min_x > C.x) Min_x = C.x;

	float Min_y = A.y;		// Нахожу минимальный y
	if (Min_y > B.y) Min_y = B.y;
	if (Min_y > C.y) Min_y = C.y;

	// Переменные функции прямой
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
	float Y1;

	//------------------------------------------Закраска
	for (Y1 = Min_y + 1; Y1 < Max_y; Y1++)
	{
		if (A.x != B.x) X1 = (Y1 - Bab) / Kab;
		else X1 = A.x;

		if (X1 < Min_x || X1 > Max_x)
		{
			if (A.x != C.x) X1 = (Y1 - Bac) / Kac;
			else X1 = A.x;
			if (C.x != B.x) X2 = (Y1 - Bbc) / Kbc;
			else X2 = B.x;
		}
		else
		{
			if (A.x != C.x) X2 = (Y1 - Bac) / Kac;
			else X2 = A.x;

			if (X2 < Min_x || X2 > Max_x)
				if (C.x != B.x)
					X2 = (Y1 - Bbc) / Kbc;
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
		line(round(X1-1), round(Y1), round(X2+1), round(Y1));
	}
}

