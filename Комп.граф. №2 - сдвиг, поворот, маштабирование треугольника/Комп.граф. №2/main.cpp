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
		Corners B(460, 240);
		Corners C(260, 570);


		//float A.x = 260, B.x = 460, C.x = 260;
		//float A.y = 240, B.y = 240, C.y = 570;
		//float;

		/*float FIG[3][3] = { {A.x, A.y, 1}, {B.x, B.y, 1}, {C.x, C.y, 1} };

		float FIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {A.x, A.y, 1} };

		float FIG[1][3] = { {A.x, A.y, 1} };
		float SDVIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {SHIFT, SHIFT, 1} };*/

		int i, j;
		char BUTTON;

		setcolor(RGB(100, 100, 255));
		line(A.x, A.y, B.x, B.y);
		setcolor(RGB(0, 255, 0));
		line(C.x, C.y, B.x, B.y);
		setcolor(RGB(255, 200, 0));
		line(A.x, A.y, C.x, C.y);
		while (BUTTON = _getch())
		{

			switch (BUTTON)
			{
			//case -32:	// сдвиг
			{
					//BUTTON = _getch();
					//case 72 80 75 77

					//switch (BUTTON) {
			case 'w':	// вверх
				A.y -= 5;
				B.y -= 5;
				C.y -= 5;
				break;

			case 's':	// вниз
				A.y += 5;
				B.y += 5;
				C.y += 5;
				break;

			case 'a':	// влево
				A.x -= 5;
				B.x -= 5;
				C.x -= 5;
				break;

			case 'd':	// вправо
				A.x += 5;
				B.x += 5;
				C.x += 5;
				break;
				//}
				//break;
				}

			// поворот
			{
			case 'q':
				xc = (A.x + B.x + C.x) / 3;
				yc = (A.y + B.y + C.y) / 3;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;

				A.x = ((A.x * cos(-Turn)) - (A.y * sin(-Turn))) * 1.0003125;
				A.y = ((A.x * sin(-Turn)) + (A.y * cos(-Turn))) * 1.0003125;
				B.x = ((B.x * cos(-Turn)) - (B.y * sin(-Turn))) * 1.0003125;
				B.y = ((B.x * sin(-Turn)) + (B.y * cos(-Turn))) * 1.0003125;
				C.x = ((C.x * cos(-Turn)) - (C.y * sin(-Turn))) * 1.0003125;
				C.y = ((C.x * sin(-Turn)) + (C.y * cos(-Turn))) * 1.0003125;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;

				break;

			case 'e':
				xc = (A.x + B.x + C.x) / 3;
				yc = (A.y + B.y + C.y) / 3;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;

				A.x = ((A.x * cos(Turn)) - (A.y * sin(Turn))) * 1.0003125;
				A.y = ((A.x * sin(Turn)) + (A.y * cos(Turn))) * 1.0003125;
				B.x = ((B.x * cos(Turn)) - (B.y * sin(Turn))) * 1.0003125;
				B.y = ((B.x * sin(Turn)) + (B.y * cos(Turn))) * 1.0003125;
				C.x = ((C.x * cos(Turn)) - (C.y * sin(Turn))) * 1.0003125;
				C.y = ((C.x * sin(Turn)) + (C.y * cos(Turn))) * 1.0003125;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;

				break;
			}

			// масштабирование
			{
			case '+':	// увеличение

				xc = (A.x + B.x + C.x) / 3;
				yc = (A.y + B.y + C.y) / 3;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;

				//putpixel(xc, yc, RGB(0, 255, 0));

				A.x *= Scaling;
				A.y *= Scaling;
				B.x *= Scaling;
				B.y *= Scaling;
				C.x *= Scaling;
				C.y *= Scaling;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;

				break;

			case '-':	// масштабирование

				xc = (A.x + B.x + C.x) / 3;
				yc = (A.y + B.y + C.y) / 3;
				A.x -= xc;
				A.y -= yc;
				B.x -= xc;
				B.y -= yc;
				C.x -= xc;
				C.y -= yc;

				A.x /= Scaling;
				A.y /= Scaling;
				B.x /= Scaling;
				B.y /= Scaling;
				C.x /= Scaling;
				C.y /= Scaling;

				A.x += xc;
				A.y += yc;
				B.x += xc;
				B.y += yc;
				C.x += xc;
				C.y += yc;

				break;
			}
			}

			cleardevice();

			// закраска
			FOO(A, B, C);
			


			setcolor(RGB(100, 100, 255));
			line(round(A.x), round(A.y), round(B.x), round(B.y));
			setcolor(RGB(0, 255, 0));
			line(round(C.x), round(C.y), round(B.x), round(B.y));
			setcolor(RGB(255, 200, 0));
			line(round(A.x), round(A.y), round(C.x), round(C.y));
		}
	}
	return 0;
}
