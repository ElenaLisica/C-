#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include<stdlib.h>
#include<time.h>
#include <cstdio>
#include <ctype.h>
using namespace std;

void GotoXY(int X, int Y);


void Show(int X1, int X2, int Y1, int Y2);

class Point
{
	
public:
	int X;
	int Y;
	Point()
	{
		X = Y = 0;
	}
	void SetPoint(int iX, int iY)
	{
		X = iX;
		Y = iY;
	}
	
};
class Figura
{
	Point*obj;
	int count;
	
public:
	Figura()
	{
		obj = NULL;
	}

	void CreateFigura( int ct)
	{
		if (ct < 3) exit(0);
		count = ct;
		
		obj = new Point[count];
		if (!obj) exit(0);
		int tempX, tempY;
		for (int i = 0; i < count; i++) {
			cout << "Set X\n";
			cin >> tempX;
			cout << "Set Y\n";
			cin >> tempY;
			obj[i].SetPoint(tempX, tempY);
		}
	}

	void ShowFigura()
	{
		int x1, x2, y1, y2;
		for (int i = 0; i < count; i++)
		{
			x1 = obj[i].X;
			y1 = obj[i].Y;
			if (i != count - 1)
			{
				x2 = obj[i + 1].X;
				y2 = obj[i + 1].Y;
			}
			else
			{
				x2 = obj[0].X;
				y2 = obj[0].Y;
			}
			Show(x1, x2, y1, y2);

		}
	}

	~Figura()
	{
		if (obj != NULL) delete[]obj;
	}
};


class Instrument{
public:
	char *name;


	Instrument() {
		name = "";
	}


	Instrument(char *c) {
		name = new char[255];
		strcpy(name, c);
	}

};


class Stringed :public Instrument {
public:
	void Play() {
		cout << name << endl;
	}
};


class Wind :public Instrument {
public:
	void Play() {
		cout << name << endl;
	}
};


class Orchestra :public Stringed, public Wind {
public:
	void Orchestra_Play() {
		Stringed::Play();

	}
};








void main()
{
	setlocale(LC_ALL, "russian");
	Figura f;
	Stringed inst_str;
	Wind inst_w;
	int answer;
	do{
		cout << "Задания:" << endl << "1.Постороение фигуры" << endl << "2.Музыкальные инструменты" << endl << "3.Выход" << endl << "Выбирите один из вариантов" << endl;
		cin >> answer;

		switch (answer) {

		case 1:
			do {
				cout << "Введите номер фигуры, которую хотите построить: " << endl << "1. Треугольник" << endl << "2.Четырехуголньник" << endl << "3.Пятиугольник" <<endl<< "4.Выход" << endl;
				cin >> answer;
				if (answer != 4) {
					f.CreateFigura(answer + 2);
					f.ShowFigura();
				}
				system("pause");
				system("cls");
			} while (answer != 4);
			break;


		case 2:
			char music[6][255] = { "труба ", "кларнет", "флейта", "скрипка ", "виолончель", "арфа" };
			do {
				cout << "Концерт :" << endl << "1.Только из духовых инструментов" << endl << "2.Только из струнных инструментов" <<endl<< "3.Выход" << endl << "Введите один из пунктов" << endl << endl;

				cin >> answer;
				cout << "Играют:" << endl << endl;
				switch (answer) {
				case 1:
					for (int i = 0; i < 3; i++)
					{
						inst_w.name = music[i];
						inst_w.Play();
					}
					break;

				case 2:
					for (int i = 3; i < 6; i++)
					{
						inst_str.name = music[i];
						inst_str.Play();
					}
					break;

				}
			} while (answer != 3);
			system("pause");
			system("cls");
			break;
		}

} while (answer != 3);

}
// функции

void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}


void Show(int X1, int X2, int Y1, int Y2)
{
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	SelectObject(hdc, Pen);
	MoveToEx(hdc, 200 + 10 * X1, 200 + 10 * Y1, NULL);
	LineTo(hdc, 200 + 10 * X2, 200 + 10 * Y2);
	DeleteObject(Pen);
	ReleaseDC(NULL, hdc);
}
