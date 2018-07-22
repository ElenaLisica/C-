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
		cout << " �������: " << endl << "1. ����� Person" << endl << "2. ����� ������" << endl << "3. �����";
		do
		{
			cout << endl << " ������� ����� �������. ";
			cin >> answer;
			if (answer != 1 && answer != 2 && answer != 3)
				cout << endl << " ������� ���������� ����� �������" << endl;
		} while (answer != 1 && answer != 2 && answer != 3);
		system("CLS");
		Person First("Elena", 26, 'w', "0956220515");
		Person Second;
		STRING s;
		switch (answer)
		{
		case 1:
			cout << "������ ������� ��������" << endl;
			
			First.Print();

		
			cout << "������� ������ ������� ��������" << endl;
			Second.Get();
			Second.Print();
			cout << "������ ������� ��������" << endl;

			int answer;

			cout << endl << "������ �������� ������? ������� ����� ��������" << endl << "1- ��" << endl << "2- ���" << endl;
			cin >> answer;
			if (answer == 1) {
				cout << endl << endl << "������ ��������� " << endl << "1- ������� ��������" << endl << "2- ������� ��������" << endl << "������� �����" << endl;
				cin >> answer;
				if (answer == 1) {
					cout << "������ ��������� " << endl << "1-���" << endl << "2- ���" << endl << "3- �������" << endl << "4- ���������� �����" << endl;
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
					cout << "������ ��������� " << endl << "1-���" << endl << "2- ���" << endl << "3- �������" << endl << "4- ���������� �����" << endl;
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

				cout << endl << "������ ����� ���������" << endl;
				First.Print();
				Second.Print();

			}
			system("pause");
			break;

		case 2:
			getchar();
		
			s.Set();
			cout << "������:" << endl;
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

	cout << "������� ���: ";
	cin.getline(Pname, 49);
	strcpy(this->name, Pname);

	cout << "������� �������: ";
	cin >> Page;
	this->age = Page;

	getchar();

	cout << "������� ���: ";
	Psex = getchar();
	this->sex = Psex;

	getchar();

	cout << "������� ���������� ����� ";
	cin.getline(Pphone, 49);
	strcpy(this->phone, Pphone);
}


void Person::Rname() {
	char Pname[50];

	cout << "������� ���: ";
	cin.getline(Pname, 49);
	strcpy(this->name, Pname);

}

void Person::Rage() {
	int Page;

	cout << "������� �������: ";
	cin >> Page;
	this->age = Page;

	getchar();

}

void Person::Rsex() {
	char Psex;

	cout << "������� ���: ";
	Psex = getchar();
	this->sex = Psex;

	getchar();

}

void Person::Rphone() {
	char Pphone[50];

	cout << "������� ���������� ����� ";
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
			cout << "������� ������" << endl;
			char a[256];
			cin.getline(a,255);
			strcpy(this->S, a);
		}
void STRING::Show_string(){
			cout << this->S;

		}



