#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;







class Person {
public:
	char name[50];
	int age;
	char sex;
	char phone[50];
	Person();
	Person(char Pname[], int Page, char Psex, char Pphone[]);
	void Get();
	void Rname();
	void Rage();
	void Rsex();
	void Rphone();
	void Print();

};

class STRING {
public:
	char* S;
	STRING();
	STRING(int n);
	STRING(char* s);
	void Set();
	void Show_string();

};
void main()
{
	setlocale(LC_ALL, "Russian");
	int answer;
	do
	{
		system("CLS");
		cout << " Задания: " << endl << "1. Класс Person" << endl << "2. Класс Строка" << endl << "3. Выход";
		do
		{
			cout << endl << " Введите номер задания. ";
			cin >> answer;
			if (answer != 1 && answer != 2 && answer != 3)
				cout << endl << " Введите корректный номер задания" << endl;
		} while (answer != 1 && answer != 2 && answer != 3);
		system("CLS");
		Person First("Elena", 26, 'w', "0956220515");
		Person Second;
		STRING s;
		switch (answer)
		{
		case 1:
			cout << "Данные первого человека" << endl;
			
			First.Print();

		
			cout << "Введите данные второго человека" << endl;
			Second.Get();
			Second.Print();
			cout << "Данные второго человека" << endl;

			int answer;

			cout << endl << "Хотите изменить данные? введите номер действия" << endl << "1- Да" << endl << "2- Нет" << endl;
			cin >> answer;
			if (answer == 1) {
				cout << endl << endl << "Внести изменения " << endl << "1- Первого человека" << endl << "2- Второго человека" << endl << "Введите номер" << endl;
				cin >> answer;
				if (answer == 1) {
					cout << "Внести изменения " << endl << "1-имя" << endl << "2- пол" << endl << "3- возраст" << endl << "4- телефонный номер" << endl;
					cin >> answer;
					getchar();
					switch (answer) {
					case 1:
						First.Rname();
						break;

					case 2:

						First.Rsex();
						break;

					case 3:
						First.Rage();
						break;

					case 4:
						First.Rphone();
						break;
					default:
						break;
					}
				}
				else
				{
					cout << "Внести изменения " << endl << "1-имя" << endl << "2- пол" << endl << "3- возраст" << endl << "4- телефонный номер" << endl;
					cin >> answer;
					getchar();
					switch (answer) {
					case 1:
						Second.Rname();
						break;

					case 2:

						Second.Rsex();
						break;

					case 3:
						Second.Rage();
						break;

					case 4:
						Second.Rphone();
						break;
					default:
						break;
					}
				}

				system("CLS");

				cout << endl << "Данные после изменений" << endl;
				First.Print();
				Second.Print();

			}
			system("pause");
			break;

		case 2:
			getchar();
		
			s.Set();
			cout << "Строка:" << endl;
			s.Show_string();
			cout << endl;
			system("pause");
			break;
		}
	} while (answer != 3);

}




//function Person
Person::Person() {
	strcpy(this->name, "");
	this->age = 0;
	this->sex = ' ';
	strcpy(this->phone, "");
}

Person::Person(char Pname[], int Page, char Psex, char Pphone[]) {
	strcpy(this->name, Pname);
	this->age = Page;
	this->sex = Psex;
	strcpy(this->phone, Pphone);
}
void Person::Get() {
	char Pname[50];
	int Page;
	char Psex;
	char Pphone[50];

	getchar();

	cout << "Введите имя: ";
	cin.getline(Pname, 49);
	strcpy(this->name, Pname);

	cout << "Введите возраст: ";
	cin >> Page;
	this->age = Page;

	getchar();

	cout << "Введите пол: ";
	Psex = getchar();
	this->sex = Psex;

	getchar();

	cout << "Введите телефонный номер ";
	cin.getline(Pphone, 49);
	strcpy(this->phone, Pphone);
}


void Person::Rname() {
	char Pname[50];

	cout << "Введите имя: ";
	cin.getline(Pname, 49);
	strcpy(this->name, Pname);

}

void Person::Rage() {
	int Page;

	cout << "Введите возраст: ";
	cin >> Page;
	this->age = Page;

	getchar();

}

void Person::Rsex() {
	char Psex;

	cout << "Введите пол: ";
	Psex = getchar();
	this->sex = Psex;

	getchar();

}

void Person::Rphone() {
	char Pphone[50];

	cout << "Введите телефонный номер ";
	cin.getline(Pphone, 49);
	strcpy(this->phone, Pphone);

}


void Person::Print() {
	cout << "\nNAME - " << this->name;
	cout << "\nAGE - " << this->age;
	cout << "\nSEX - " << this->sex;
	cout << "\nPHONE - " << this->phone << endl;
}


//function String
STRING::STRING() {
		S=new char [80];
		}

STRING::STRING( int n) {
				 S= new char[n];
		}
STRING::STRING(char* s) {
			int n = strlen(s);
			S = new char[n+1];
		}

void STRING::Set() {
			cout << "Введите строку" << endl;
			char a[256];
			cin.getline(a,255);
			strcpy(this->S, a);
		}
void STRING::Show_string(){
			cout << this->S;

		}



