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

#define for_control int code = 0;int check = 1; int x; 
#define hat1 GotoXY(31, 0); SetColor(LightRed, Black); cout << "Hw_4 класс Matrix" << endl<<endl; SetColor(White, Black);
#define exit cout << endl << endl;cout << "Для возврата в главное меню нажмите Esc" << endl;cout << "Для повторной проверки - любая клавиша" << endl; x = _getch();
#define exit_progr GotoXY(28, 0); SetColor(LightRed, Black); cout << "Всего доброго!!" << endl; SetColor(White, Black);

#define adequacy int n, m;SetColor(LightGreen, Black);cout << "Введите количество строк" << endl;SetColor(White, Black); cin >> n;SetColor(LightGreen, Black);cout << "Введите количество столбцов" << endl;SetColor(White, Black); cin >> m;while ((n<=0) || (m<=0) ){SetColor(LightRed, Black);cout << "Количество строк и столбцов не может быть отрицательным или равным 0!!! Давайте еще разок ;-)" << endl;SetColor(White, Black);;cin >> n>>m;}
// Ввод колличества строк и столбцов + проверка;


using namespace std;

enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
class matrix
{
public:
	int rows;
	int cols;
	int **arr;
	matrix();  // Конструктор по-умолчанию;
	matrix(int n, int m); // Конструктор с параметрами;
	matrix(const matrix &other); // Конструктор копирования;
	~matrix(); // Деструктор;
			   //////////////////////////
	void fill(); // Метод заполнения матрицы случайными числами от 0 до 9 (чтоб легче проверять было);
	void show(); // Метод вывода матрицы на экран;
	int matrix::operator() (int n, int m); // Обращения к отдельному элементу матрицы (перегрузка скобок);
	int fill_element(); // Метод замены выбранного пользователем элемента;
	matrix matrix :: operator + (const matrix &other); // Перегрузка оператора + (нахождение суммы матриц);
	matrix matrix :: operator - (const matrix &other); // Перегрузка оператора - (нахождение разности матриц);
	bool matrix :: operator > (const matrix &other); // Перегрузка оператора > (для сравнения размера матриц);
	bool matrix::compare(const matrix &other); // Метод сравнения (используется при вычислении произведения матриц);
	matrix matrix :: operator * (const matrix &other); // Перегрузка оператора * (нахождение произведения матриц);
	matrix matrix::transp(matrix &other);// Метод транспонирования матрицы;
};
void hat(); // для сокращения колличества строк;
void SetColor(int text, int background);
void GotoXY(int X, int Y);


void main()
{
	int x1;
	for_control;
	hat();
	string menu[] = { "Создать матрицу, заполнить рандомно и вывести на экран",
		"Конструктор копирования",
		"Обращение к отдельному элементу матрицы и замена его значения",
		"Сумма и разность матриц",
		"Произведение матриц",
		"Транспонирование",
		"Выход" }, pointer = ">";
	do
	{
		system("CLS");
		hat1;

		printf("\t\t\t%s%s\n", pointer.c_str(), menu[0].c_str());
		SetColor(LightGreen, Black);
		for (int i = 1; i < 7; i++)
			printf("\t\t\t%s\n", menu[i].c_str());
		for_control;

		while (code != 13)
		{
			code = _getch();
			if (code == 80)
			{
				if (check == 7)
					check = 1;
				else
					check++;
			}
			else if (code == 72)
			{
				if (check == 1)
					check = 7;
				else
					check--;
			}
			system("CLS");
			hat1;
			for (short i = 0; i < 7; i++)
			{
				if (i + 1 == check)
				{
					SetColor(White, Black);
					printf("\t\t\t%s%s\n", pointer.c_str(), menu[i].c_str());
				}
				else
				{
					SetColor(LightGreen, Black);
					printf("\t\t\t%s\n", menu[i].c_str());
				}
			}
			SetColor(LightGreen, Black);
		}

		switch (check)
		{
		case 1:
		{
			do {

				system("CLS"); SetColor(White, Black);
				///////////////////////////////////
				adequacy;
				matrix a(n, m);
				a.fill();
				a.show();
				//////////////////////////////////
				exit;
			} while (x != 27);
		}
		break;
		case 2:
		{
			do {

				system("CLS"); SetColor(White, Black);
				///////////////////////////////////				
				adequacy;
				matrix a(n, m);
				a.fill();
				a.show();
				SetColor(LightGreen, Black); cout << "Копируем в новую матрицу" << endl; SetColor(White, Black);
				matrix b(a);
				b.show();
				//////////////////////////////////
				exit;
			} while (x != 27);
		}
		break;
		case 3:
		{
			do {

				system("CLS"); SetColor(White, Black);
				///////////////////////////////////
				adequacy;
				matrix a(n, m);
				a.fill();
				a.show();
				a.fill_element();
				a.show();
				//////////////////////////////////
				exit;
			} while (x != 27);
		}
		break;
		case 4:
		{
			do {

				system("CLS"); SetColor(White, Black);
				///////////////////////////////////
				adequacy;
				matrix a(n, m);
				SetColor(LightGreen, Black); cout << "Вводим вторую матрицу" << endl; SetColor(White, Black);
				int m1, n1; cin >> n1 >> m1;
				matrix b(n1, m1);
				bool result = a > b;
				if (result == true)
				{
					a.fill(); b.fill();
					a.show(); cout << endl << endl; b.show();
					matrix c = a + b;
					SetColor(LightGreen, Black); cout << "Сумма заданных матриц" << endl; SetColor(White, Black);
					c.show();
					matrix k = a - b;
					SetColor(LightGreen, Black); cout << "Разность заданных матриц" << endl; SetColor(White, Black);
					k.show();
				}
				else
				{
					SetColor(LightRed, Black); cout << "Для вычисления суммы и разности матриц, они должны быть равны!!" << endl; SetColor(White, Black);
				}
				//////////////////////////////////
				exit;
			} while (x != 27);
		}
		break;
		case 5:
		{
			do {

				system("CLS"); SetColor(White, Black);
				///////////////////////////////////
				adequacy;
				matrix a(n, m);
				SetColor(LightGreen, Black); cout << "Вводим вторую матрицу" << endl; SetColor(White, Black);
				int m1, n1; cin >> n1 >> m1;
				matrix b(n1, m1);
				bool result = a.compare(b);
				try {
					if (result == true)
					{
						a.fill(); b.fill();
						a.show(); cout << endl << endl; b.show();
						matrix c = a * b;
						SetColor(LightGreen, Black); cout << "Произведение заданных матриц" << endl; SetColor(White, Black);
						c.show();
					}
					else
					{
						throw  "Умножать матрицы можно тогда и только тогда, когда количество столбцов первой матрицы равно количеству строк второй матрицы";
					}
				}
				catch (char *s) {
					SetColor(LightRed, Black); cout <<s << endl; SetColor(White, Black);
				}
				//////////////////////////////////
				exit;
			} while (x != 27);
		}
		break;
		case 6:
		{
			do {

				system("CLS"); SetColor(White, Black);
				///////////////////////////////////
				adequacy;
				matrix a(n, m);
				a.fill();
				a.show();
				cout << endl << endl;
				matrix c = a.transp(a);
				SetColor(LightGreen, Black); cout << "Транспонированная матрица" << endl; SetColor(White, Black);
				c.show();
				//////////////////////////////////
				exit;
			} while (x != 27);
		}
		break;
		case 7:
		{
			system("CLS");
			x1 = 0;
			exit_progr;
		}
		break;
		}
	} while (x1 != 0);
}




void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
void hat()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); /*setlocale(LC_ALL, "Rus");*/ system("color 0"); SetColor(White, Black); srand(time(NULL));
}
matrix::matrix()
{
	rows = 0;
	cols = 0;
	arr = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int[cols];
	}
}
matrix::matrix(int n, int m)
{
	rows = n; cols = m;
	arr = new int*[rows];
	try {
		if (!arr)
			throw "Память под массив не выделилась";
	}
	
	catch (char *s)
	{
		cout << endl << s << endl;
	}

	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int[cols];
	}
}
matrix::matrix(const matrix &other)
{

	rows = other.rows;
	cols = other.cols;
	arr = new int*[rows];
	try {
		if (!arr)
			throw "Память под массив не выделилась";
	}

	catch (char *s)
	{
		cout << endl << s << endl;
	}
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int[cols];
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arr[i][j] = other.arr[i][j];
		}
	}
}
matrix::~matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
void matrix::fill()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arr[i][j] = rand() % 10;
		}
	}
}
void matrix::show()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << setw(5) << arr[i][j];
		}
		cout << endl;
	}
}
int matrix::operator() (int n, int m)
{
	if (n > rows || m > cols)
	{
		SetColor(LightRed, Black); cout << "Нет элемента с данным индексом " << endl; SetColor(White, Black);
	}
	else
	{
		return arr[n][m];
	}
}
int matrix::fill_element()
{
	int n, m;
	SetColor(LightGreen, Black); cout << "Введите адрес нужного элемента" << endl; SetColor(White, Black);
	SetColor(LightGreen, Black); cout << "Введите строку" << endl; cin >> n; SetColor(White, Black);
	SetColor(LightGreen, Black); cout << "Введите столбец" << endl; cin >> m; SetColor(White, Black);
	if (n > rows || m > cols)
	{
		SetColor(LightRed, Black); cout << "Нет элемента с данным индексом " << endl;
	}
	else
	{
		SetColor(LightGreen, Black); cout << "Ваш элемент : " << arr[n][m] << endl; SetColor(White, Black);
		SetColor(LightGreen, Black); cout << "Введите новое значение элемента" << endl; SetColor(White, Black);
		cin >> arr[n][m];
		return arr[n][m];
	}
}
matrix matrix :: operator + (const matrix &other)
{
	matrix temp;
	temp.rows = this->rows;
	temp.cols = this->cols;
	temp.arr = new int*[temp.rows];
	for (int i = 0; i < temp.rows; ++i)
	{
		temp.arr[i] = new int[temp.cols];
	}
	for (int i = 0; i < temp.rows; ++i)
	{
		for (int j = 0; j < temp.cols; ++j)

		{
			temp.arr[i][j] = this->arr[i][j] + other.arr[i][j];
		}
	}
	return temp;
}
matrix matrix :: operator - (const matrix &other)
{
	matrix temp;
	temp.rows = this->rows;
	temp.cols = this->cols;
	temp.arr = new int*[temp.rows];
	for (int i = 0; i < temp.rows; ++i)
	{
		temp.arr[i] = new int[temp.cols];
	}
	for (int i = 0; i < temp.rows; ++i)
	{
		for (int j = 0; j < temp.cols; ++j)

		{
			temp.arr[i][j] = this->arr[i][j] - other.arr[i][j];
		}
	}
	return temp;
}
bool matrix :: operator > (const matrix &other)
{
	if (this->rows == other.rows && this->cols == other.cols)
	{
		SetColor(LightGreen, Black); cout << "Матрицы равны" << endl; SetColor(White, Black);
		return true;
	}
	else
	{
		SetColor(LightRed, Black); cout << "Матрицы не равны" << endl; SetColor(White, Black);
		return false;
	}
}

matrix matrix::transp(matrix &other)
{
	matrix c = matrix(other.cols, other.rows);

	for (int i = 0; i < other.rows; ++i)
	{
		for (int j = 0; j < other.cols; ++j)
		{
			c.arr[j][i] = other.arr[i][j];
		}
	}
	return c;
};

bool matrix::compare(const matrix &other)
{
	if (this->cols == other.rows)
	{
		return true;
	}
	else
	{
		return false;
	}
}
matrix matrix :: operator * (const matrix &other)
{
	matrix temp;
	temp.rows = this->rows;
	temp.cols = other.cols;
	temp.arr = new int*[temp.rows];
	for (int i = 0; i < temp.rows; ++i)
	{
		temp.arr[i] = new int[temp.cols];
	}
	for (int i = 0; i <temp.rows; i++)
	{
		for (int j = 0; j < temp.cols; j++)
		{
			temp.arr[i][j] = 0;
			for (int z = 0; z < this->cols; z++)
			{
				temp.arr[i][j] += (this->arr[i][z] * other.arr[z][j]);
			}
		}
	}
	return temp;
}
