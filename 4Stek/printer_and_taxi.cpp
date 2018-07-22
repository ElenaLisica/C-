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

//
////	//  Принтер

using namespace std;

class QueuePriority
{
	int * Wait;
	int * Pri;
	int MaxQueueLength;
	int QueueLength;
public:
	QueuePriority(int m);
	~QueuePriority();
	void Add(int c, int p);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
};
void QueuePriority::Show() {
	cout << "Кабинет  " << "Приоритет" << "\n\n";
	for (int i = 0;i<QueueLength;i++)
	{
		cout << Wait[i] << " - " << Pri[i] << "\n\n";
	}
	cout << "\n-----------------------------------\n";
}
QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
}
QueuePriority::QueuePriority(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = 0;
}
void QueuePriority::Clear()
{
	QueueLength = 0;
}
bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}
bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int QueuePriority::GetCount()
{
	return QueueLength;
}
void QueuePriority::Add(int c, int p)
{

	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}
int QueuePriority::Extract()
{

	if (!IsEmpty())
	{
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1;i<QueueLength;i++)
			if (max_pri<Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		for (int i = pos_max_pri;i<QueueLength - 1;i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		return temp1;
	}
	else return -1;
}



class taxi
{
	enum { EMPTY = -1, FULL = 20 };


public:


	int  people_now_taxi = 0, people_go = 0, time_pass, people_wait, free_place = 24, sad_people, avarage_people, taxi_time;
	taxi() {}

	void RANDOM1(int count) {
		this->people_wait = rand() % count + 1;
		cout << "pw" << this->people_wait;
	}

	void RANDOM2() {
		this->people_go = rand() % (this->people_now_taxi);
	}

};

void main()
{
	//Задача на принтер
	setlocale(LC_ALL, "russian");
	cout << "Задача на принтер"<<endl;
	srand(time(0));
	QueuePriority QUP(5);
	for (int i = 0;i<5;i++) {

		QUP.Add(rand() % 100, rand() % 11);
	}

	while (!QUP.IsEmpty()) {
		QUP.Show();
		QUP.Extract();
	}






	system("pause");
	system("CLS");

	// Маршрутка

	cout << "Задача на маршрутки" << endl << endl;
	srand(time(NULL));
	taxi T;
	int n, k = 0;
	
	cout << "Введите количество остановок " << endl;
	cin >> n;

	cout << "Введите среднее количество людей на остановке " << endl;
	cin >> T.avarage_people;

	cout << "Введите среднее время появления новых людей на остановке " << endl;
	cin >> T.time_pass;

	cout << "Введите средний интервал между маршрутками " << endl;
	cin >> T.taxi_time;


	for (int i = 1; i <= n; i++)
	{
		T.RANDOM1(T.avarage_people);


		if (T.time_pass >= T.taxi_time)
				T.people_wait = T.people_wait / (T.time_pass / T.taxi_time);
		
	

		/*else
		{
			T.people_wait = (T.people_wait)*(T.taxi_time / T.time_pass);
			cout << "2 people_wait" << T.people_wait<<endl;
		}*/

		if (i == 1)
				T.people_now_taxi = 0;
		
		else
		    	T.people_now_taxi = 24 - T.free_place;
		
		if (i != 1 && T.people_now_taxi != 0)
			T.RANDOM2();


		T.free_place += T.people_go;
		

		if (/*T.people_now_taxi != 0 && */T.people_now_taxi <24)
		{
			if (T.free_place < T.people_wait)
			{
				T.free_place = 0;
				T.sad_people = T.people_wait - T.free_place;
			}
			else
				T.free_place -= T.people_wait;
			
		}
		/*else
		{
			T.free_place = 0;
		}*/

		
		if (T.sad_people < 0)
		 	T.sad_people = 0;
			
			


		if (i == n)
		{
			T.people_go = T.people_now_taxi;
			T.free_place = 24;
			T.people_wait = 0;

		}
		cout << "Остановка " << i << " :" << endl << endl;
		cout << "Людей на остановке " << T.people_wait << endl;
		cout << "Вышло пассажиров из маршрутки " << T.people_go << endl;
		cout << "Свободных мест в маршрутке: " << T.free_place << endl;
		cout << "Осталось людей на остановке: " << T.sad_people << endl << endl << endl << endl;
		if (k < T.sad_people)
			k = T.sad_people;
	

	}

	if (k < 3)
		cout << "Ситуация c интервалом времени между маршрутками  не критическая";
	if (k > 2 && k < 8)
		cout << "Ситуация c интервалом времени между маршрутками  требует рассмотрения администрации";
	if (k > 7)
		cout << "Ситуация c интервалом времени между маршрутками   критическая";
	cout << endl << endl;

}