#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include <cstdio>
#include <ctype.h>

using namespace std;

class matrix
{
public:
	int rows;
	int cols;
	int **arr;
	matrix();  
	matrix(int n, int m); 
	matrix(const matrix &other); 
	~matrix(); 
	void fill(); 
	void show(); 
	matrix matrix :: operator + (const matrix &other); 
	matrix matrix :: operator - (const matrix &other); 
	matrix matrix :: operator * (const matrix &other); 
	matrix matrix::transp(matrix &other);
	matrix& operator=(matrix &arrInt2) 
			{
			
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						arr[i][j] = arrInt2.arr[i][j];
					}
				}
				return *this;
			}

};



void main()
{
	setlocale(LC_ALL, "russian");
	cout << endl << "Матрица А:" << endl;
	matrix a(3, 3);
	a.fill();
	a.show();
	cout <<endl<< "Матрица В:" << endl;
	matrix b(3, 3);
	b.fill();
	b.show();
	matrix c(3, 3);
	c= a + b;
	cout << endl<<"А+В:" << endl; 
	c.show();
	c = a - b;
	cout <<endl<< "A-B:" << endl; 
	c.show();
	 c = a * b;
	 cout << endl << "A*B:" << endl;
	 c.show();
	 cout << endl << "Транспонированная матрица A:" << endl;
	 c = a.transp(a);
	 c.show();

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
















































//#include<iostream>
//#include<Windows.h>
//#include<stdlib.h>
//#include<time.h>
//#include<iomanip>
//
//using namespace std;
//
//class Matrix
//{
//private:
//	int mas[3][3] = { {}, {} };
//public:
//	void setmas();
//
//
//
//
//	Matrix  operator + (Matrix  & obj)
//	{
//
//		Matrix temp;
//
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				temp.mas[i][j] = mas[i][j] + obj.mas[i][j];
//			}
//		}
//
//		return temp;
//	}
//
//	Matrix  operator * (Matrix  & obj)
//	{
//		Matrix temp;
//
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//				temp.mas[i][j] = 0;
//
//		}
//
//
//
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				for (int k = 0; k < 3; k++)
//
//					temp.mas[i][j] += (mas[i][k]) * (obj.mas[k][j]);
//			}
//		}
//		return temp;
//	}
//
//
//
//	Matrix & operator -- ()
//	{
//		short temp;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = i; j < 3; j++)
//			{
//				temp = mas[i][j];
//				mas[i][j] = mas[j][i];
//				mas[j][i] = temp;
//			}
//		}
//		return *this;
//
//	}
//
//
//
//	void write()
//	{
//		cout << "Массив :" << endl;
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				cout << setw(5) << mas[i][j] << "  ";
//			}
//			cout << endl;
//		}
//	}
//
//
//	Matrix& operator=(Matrix &arrInt2) //перегрузка оператора присваивания
//	{
//	
//
//		
//
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//				mas[i][j] = arrInt2.mas[i][j];
//
//		}
//
//		return *this;
//	}
//
//};
//
//
//void Matrix::setmas()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			mas[i][j] = rand() % 16 - 10;
//	}
//	write();
//}
//
//
//
//
//void main()
//{
//	setlocale(LC_ALL, "rus");
//	Matrix a;
//	a.setmas();
//	Matrix b;
//	Matrix c;
//	b.setmas();
//	cout << "Сложение двух матриц:" << endl;
//	c = a + b;
//	c.write();
//	cout << endl << "транспонированная первая матрица: " << endl;
//	--a;
//	a.write();
//	cout << endl << "транспонированная вторая матрица: " << endl;
//	--b;
//	b.write();
//	cout << endl << "умножение двух матриц: " << endl;
//	c = a * b;
//	c.write();
//
//}