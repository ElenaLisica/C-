#pragma once
#include <iostream>
using namespace std;

typedef unsigned int uint;

template <typename T>
class Vector
{
private:
	T *data;
	uint count;
public:
	// Конструкторы
	Vector() : data(NULL), count(0) {}
	explicit Vector(uint initCount);
	Vector(const Vector& v);
	Vector(T array[], uint arraySize);
	// Деструктор
	~Vector() { Clear(); }

	// Очистка вектора
	void Clear();

	// Присваивание
	Vector& operator=(const Vector& v);

	// Работа с размером вектора
	uint GetCount() const { return count; }
	bool IsEmpty() const { return count == 0; }
	bool operator!() const { return IsEmpty(); }

	// Доступ к элементам
	//T& operator[](uint index);

	// Добавление и удаление элементов
	void Add(const T& item);
	void Insert(uint index, const T& item);
	void Remove(uint index);
	//show
	void Show(int index);
};

template <typename T>
Vector<T>::Vector(uint initCount)
{
	count = initCount;
	data = new T[count];
	
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v)
{
	count = v.count;
	data = new T[count];
	for (uint i = 0; i < count; i++)
	{
		data[i] = v.data[i];
	}
}

template <typename T>
Vector<T>::Vector(T array[], uint arraySize)
{
	count = arraySize;
	data = new T[count];
	for (uint i = 0; i < count; i++)
	{
		data[i] = array[i];
	}
}

template <typename T>
void Vector<T>::Clear()
{
	delete[] data;
	data = NULL;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (&v == this)
		return *this;

	count = v.count;
	data = new T[count];
	for (uint i = 0; i < count; i++)
	{
		data[i] = v.data[i];
	}

	return *this;
}


template <typename T>
void Vector<T>::Add(const T& item)
{
	T *tmp = new T[count + 1];

	for (uint i = 0; i < count; i++)
	{
		tmp[i] = data[i];
	}
	tmp[count] = item;
	count++;
	delete[] data;
	data = tmp;

}



template <typename T>
void Vector<T>::Show(int index)
{
	try {
		if (GetCount() < index)
			throw "\n Ошибка! В векторе меньше элементов чем Вы хотите увидеть!\n";
		else
			for (int i = 0; i < index; i++)
			{
				cout << data[i] << "  ";
			}

	}
	catch (char *s) {
		cout << s;
	}
}




template <typename T>
void Vector<T>::Insert(uint index, const T& item)
{
	T *tmp = new T[count + 1];

	for (uint i = 0; i < count + 1; i++)
	{
		if (i < index)
		{
			tmp[i] = data[i];
		}
		else if (i == index)
		{
			tmp[i] = item;
		}
		else
		{
			tmp[i] = data[i - 1];
		}
	}

	count++;
	delete[] data;
	data = tmp;
}

template <typename T>
void Vector<T>::Remove(uint index)
{
	T *tmp = new T[count - 1];

	for (uint i = 0; i < count - 1; i++)
	{
		if (i < index)
		{
			tmp[i] = data[i];
		}
		else if (i >= index)
		{
			tmp[i] = data[i + 1];
		}
	}

	count--;
	delete[] data;
	data = tmp;
}
void main() {

	setlocale(LC_ALL, "russian");
	Vector <int> v;
	
	for (int i = 0;i < 10;i++) {
		v.Add(i);
	}
	int answer;
	cout << "В массиве 10 элементов. Сколько хотите вывести на экран?  ";
	cin >> answer;
	v.Show(answer);
	
}

