#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<io.h>

using namespace std;
char name[50];
FILE*f;

void create_file() {

	
	cout << "�������  �������� ������ �����" << endl;
	cin >> name;
	f = fopen(name, "w+");
	fclose(f);

}


void remove_file()
{
	cout << "�������  �������� �����" << endl;
	cin >> name;
	if (remove(name) != 0)
		cout << "������! ���������� ���� � ����� ���������\n"; 
	else        cout << "���� ������\n";
}


void rename_file(){
	cout << "�������  �������� �������� �����" << endl;
	cin >> name;

	char new_name[50];
	cout << "������� ����� �������� �����" << endl;
	cin >> new_name;

	if (rename(name, new_name) != 0)
		cout << "������! ���������� ����" << name;
	else        cout << "���� ������������\n";

}



void new_path(){
	cout << "�������  �������� �������� �����" << endl;
	cin >> name;

	char new_name[50];
	cout << "������� ����� ���� � ��������� ����� � ����     c:\\mp\\m" << endl;
	cin >> new_name;

	if (rename(name, new_name) != 0)
		cout << "������! ���������� ����" << name;
	else        cout << "���� ���������\n";
}



void open_file(){
	cout << "�������  �������� �������� �����" << endl;
	cin >> name;
	
	char str_file[100];
	f = fopen(name, "r+");
	if (f != NULL)
	{
		int i = 0;
		char ch;
		while ((ch = getc(f)) != EOF)
			str_file[i++] = ch;
		str_file[i] = '\0';
		printf(str_file);
	}
	else printf("���������� ������� ���� �� ������.\n");
	fclose(f);
}




void main() {
	setlocale(LC_ALL, "russian");
	int answer;
	do {
		cout << "�������� ���� �� ��������� ������� :" << endl << "1.�������� ������ ����� � ������� ��������" << endl <<
			"2.�������� ����� �� �������� ��������" << endl << "3.�������������� ����� � ������� ��������" << endl << "4.����������� ����� � ��������� ������������� �������" <<
			endl << "5.����� ����������� �� �����" << endl<<"6.�����"<<endl<<endl;

		cin >> answer;

		switch (answer) {
		case 1:
			create_file();
			break;

		case 2:
			remove_file();
			break;


		case 3:
			rename_file();
			break;


		case 4:
			new_path();
			break;

		case 5:
			open_file();
			break;
		}
		system("pause");
		system("CLS");
		

	} while (answer != 6);


}