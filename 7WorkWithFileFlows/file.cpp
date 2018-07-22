#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<io.h>

using namespace std;
char name[50];
FILE*f;

void create_file() {

	
	cout << "Введите  название нового файла" << endl;
	cin >> name;
	f = fopen(name, "w+");
	fclose(f);

}


void remove_file()
{
	cout << "Введите  название файла" << endl;
	cin >> name;
	if (remove(name) != 0)
		cout << "Ошибка! Отсутсвует файл с таким названием\n"; 
	else        cout << "Файл удален\n";
}


void rename_file(){
	cout << "Введите  название текущего файла" << endl;
	cin >> name;

	char new_name[50];
	cout << "Введите новое название файла" << endl;
	cin >> new_name;

	if (rename(name, new_name) != 0)
		cout << "Ошибка! Отсутсвует файл" << name;
	else        cout << "Файл переименован\n";

}



void new_path(){
	cout << "Введите  название текущего файла" << endl;
	cin >> name;

	char new_name[50];
	cout << "Введите новый путь с названием файла в виде     c:\\mp\\m" << endl;
	cin >> new_name;

	if (rename(name, new_name) != 0)
		cout << "Ошибка! Отсутсвует файл" << name;
	else        cout << "Файл перенесен\n";
}



void open_file(){
	cout << "Введите  название текущего файла" << endl;
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
	else printf("Невозможно открыть файл на чтение.\n");
	fclose(f);
}




void main() {
	setlocale(LC_ALL, "russian");
	int answer;
	do {
		cout << "Выбирите один из вариантов заданий :" << endl << "1.Создание нового файла в текущем каталоге" << endl <<
			"2.Удаление файла из текущего каталога" << endl << "3.Переименование файла в текущем каталоге" << endl << "4.Перемещение файла в указанный пользователем каталог" <<
			endl << "5.Вывод содержимого на экран" << endl<<"6.Выход"<<endl<<endl;

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