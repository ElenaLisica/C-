#include<iostream>
#include<Windows.h>

using namespace std;




class Figure {
private: double X, Y;
public:
	Figure() {
		X = NULL;
		Y = NULL;
	}
	void SetX() {
		cout << "Введите Х" << endl;
		cin >> X; }
	void SetY() {
		cout << "Введите Y" << endl;
		cin >> Y;
	}
	double GetX() { return X; }
	double GetY() { return Y; }
	virtual void Draw() = 0;
};


class Point :public Figure {
public:
	Point() {
	}
	virtual void Draw() = 0;
};



class Circle :public Point {
private: double R;
public:
	Circle() { R = 1; }
	void SetRadius() {
		cout << "Введите R" << endl;
		cin >> R;
	}
	double GetRadius() { return R; }
	virtual void Draw() { /*	double X, Y, R;*/
		SetX();
		SetY();
		SetRadius();

		HWND hwnd = GetConsoleWindow();  // идентификатор окна консоли 
		HDC hdc = GetDC(hwnd); // дескриптор контекста консольного окна 
		RECT clientRect;           // координаты прямоугольника 
		GetClientRect(hwnd, &clientRect);  // получаем размеры окна 
		COLORREF penColor = RGB(0, 0, 255);   //синее перо  
		SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(120, 0, 120)));  //кисть по умолчанию WHITE_BRUSH 
		SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
		Ellipse(hdc, 400 - R * 10, 400 - R * 10, 400 + R * 10, 400 + R * 10);
}

};

class Triangle :public Point {
private: double X2, X3, Y2, Y3;
public:
	Triangle() {
		X2 = NULL;
		Y2 = NULL;
		X3 = NULL;
		Y3 = NULL;
	}
	void SetX2() {
		cout << "Введите Х2" << endl;
		cin >> X2;
	}
	void SetX3() {
		cout << "Введите Х3" << endl;
		cin >> X3;
	}
	void SetY2() {
		cout << "Введите Y2" << endl;
		cin >> Y2;
	}
	void SetY3() {
		cout << "Введите Y3" << endl;
		cin >> Y3;
	}
	double GetX2() { return X2; }
	double GetX3() { return X3; }
	double GetY2() { return Y2; }
	double GetY3() { return Y3; }
	virtual void Draw() {
		SetX();
		SetY();
		SetX2();
		SetY2();
		SetX3();
		SetY3();
		HDC hdc = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		SelectObject(hdc, Pen);
		MoveToEx(hdc, 200 + 10 *GetX(), 200 + 10 * GetY(), NULL);
		LineTo(hdc, 200 + 10 * GetX2(), 200 + 10 *GetY2());
		MoveToEx(hdc, 200 + 10 * GetX2(), 200 + 10 * GetY2(), NULL);
		LineTo(hdc, 200 + 10 * GetX3(), 200 + 10 * GetY3());
		MoveToEx(hdc, 200 + 10 * GetX3(), 200 + 10 * GetY3(), NULL);
		LineTo(hdc, 200 + 10 * GetX(), 200 + 10 * GetY());
		DeleteObject(Pen);
		ReleaseDC(NULL, hdc);
		 };
};


class LineD :public Point {
private: double endX, endY;
public:
	LineD() {
		endX = NULL;
		endY = NULL;
	}


	void SetEndX() {
		cout << "Введите Х2" << endl;
		cin >> endX;
	}
	void SetEndY() {
		cout << "Введите Y2" << endl;
		cin >> endY;
	}
	double GetEndX() { return endX; }
	double GetEndY() { return endY; }
	virtual void Draw() {
		SetX();
		SetY();
		SetEndX();
		SetEndY();
		HDC hdc = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		SelectObject(hdc, Pen);
		MoveToEx(hdc, 200 + 10 * GetX(), 200 + 10 * GetY(), NULL);
		LineTo(hdc, 200 + 10 * GetEndX(), 200 + 10 * GetEndY());
		DeleteObject(Pen);
		ReleaseDC(NULL, hdc);



	}
};


class Square :public Point {
private: double width;
public:
	Square() { width = NULL; }
	void SetWidth() {
		cout << "Введите длину стороны" << endl;
		cin >> width;
	}
	double GetWidth() { return width; }
	virtual void Draw() {
		SetX();
		SetY();		
		SetWidth();
		HDC hdc = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		SelectObject(hdc, Pen);
		MoveToEx(hdc, 300 + 10 * GetX(), 300 + 10 * GetY(), NULL);
		LineTo(hdc, 300 + 10 * GetX()+ 10 * width, 300 + 10 * GetY());
		MoveToEx(hdc, 300 + 10 * GetX() + 10 * width, 300 + 10 * GetY(), NULL);
		LineTo(hdc, 300 + 10 * GetX() + 10 * width, 300 + 10 * GetY()+ 10 * width);
		MoveToEx(hdc, 300 + 10 * GetX() + 10 * width, 300 + 10 * GetY() + 10 * width, NULL);
		LineTo(hdc, 300 + 10 * GetX(), 300 + 10 * GetY() + 10 * width);
		MoveToEx(hdc, 300 + 10 * GetX(), 300 + 10 * GetY() + 10 * width, NULL);
		LineTo(hdc, 300 + 10 * GetX(), 300 + 10 * GetY() );
		DeleteObject(Pen);
		ReleaseDC(NULL, hdc);

	};
};


class Rect : public Square {
private: double height;
public:
	Rect() { height = NULL; }
	void SetHeight() {
		cout << "Введите ширину стороны" << endl;
		cin >> height;
	}
	double GetHeight() { return height; }
	virtual void Draw() {
		SetX();
		SetY();
		SetWidth();
		SetHeight();
		HDC hdc = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		SelectObject(hdc, Pen);
		MoveToEx(hdc, 300 + 10 * GetX(), 300 + 10 * GetY(), NULL);
		LineTo(hdc, 300 + 10 * GetX() + 10*height, 300 + 10 * GetY());
		MoveToEx(hdc, 300 + 10 * GetX() + 10 * height, 300 + 10 * GetY(), NULL);
		LineTo(hdc, 300 + 10 * GetX() + 10 * height, 300 + 10 * GetY() + 10 * GetWidth());
		MoveToEx(hdc, 300 + 10 * GetX() + 10 * height, 300 + 10 * GetY() + 10 * GetWidth(), NULL);
		LineTo(hdc, 300 + 10 * GetX(), 300 + 10 * GetY() + 10 * GetWidth());
		MoveToEx(hdc, 300 + 10 * GetX(), 300 + 10 * GetY() + 10 * GetWidth(), NULL);
		LineTo(hdc, 300 + 10 * GetX(), 300 + 10 * GetY());
		DeleteObject(Pen);
		ReleaseDC(NULL, hdc);
		 };
};


void main() {
	setlocale(LC_ALL, "russian");
	SetConsoleTitle(L"Draw");

	int answer;
	do {
		cout << "Введите номер фигуры" << endl << "1.Круг" << endl << "2.Отрезок" << endl
			<< "3.Треугольник" << endl << "4.Квадрат" << endl << "5.Прямоугольник" << endl
			<< "6.Выход" << endl;
		Circle C;
		LineD L;
		Square S;
		Rect R;
		Triangle T;
		cin >> answer;
		switch (answer) {
		case 1:
			C.Draw();
			break;

		case 2:
			L.Draw();
			break;

		case 3:
			T.Draw();
			break;

		case 4:
			S.Draw();
			break;

		case 5:
			R.Draw();
			break;
		}
		system("pause");
		system("cls");
	} while (answer != 6);
}