#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>

using namespace std;

class string_ {
private:
	char* s;
	int length;
public:
	string_();

	string_(char* str);

	string_(const string_& str);

	~string_();

	void SetString();

	void string_ :: operator ! ();

	const char*GetStr()const {
		return s;
	}

	void string_ :: operator ~ ();

	void string_ :: operator ==(const string_ & _str);

	void string_ :: operator > (string_ & _str);

	string_ operator+(const string_ & _str);

	string_ operator=(const string_ &str);

	void string_::sort(string_ _str[], int n);
};

void main() {
	setlocale(LC_ALL, "russian");
	string_ a, b,c;
	cout << "Введите первую строку" << endl;
	a.SetString();
	cout << "Введите вторую строку" << endl;
	b.SetString();
	
	cout << endl << "конкатенация строк" << endl;
	 c=a + b;
	 cout << c.GetStr()<<endl;



	cout <<endl<< "Сравнение строк" << endl;
	a == b;
	a > b;

	cout <<endl<< "Изменение регистра"<<endl;
	!a;
	!b;
	cout << a.GetStr() << endl;
	cout << b.GetStr() << endl;

	string_ *arr = new string_[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr->sort(arr, 3);

	cout <<endl<< "Реверс строки" << endl;
	~a;
	cout << endl;
	~b;
	


}


string_::string_() {
	s = NULL;
	length = 0;
}

string_::string_(char* str) {
	length = strlen(str);
	s = new char[length + 1];
}

string_::string_(const string_& str) {
	length = str.length;
	s = new char[length + 1];
	strcpy(s, str.s);
}
string_::~string_() {
	delete[]s;
}

void string_::SetString() {
	if (s != NULL)
		delete[]s;
	char a[256];
	cin.getline(a, 256);
	length = strlen(a) + 1;
	s = new char[length];
	strcpy(s, a);
}

void string_::string_ :: operator ! ()
{
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 97)
		{
			s[i] -= 32;
		}
		else if (s[i] <= 97)
		{
			s[i] += 32;
		}
}


void string_::string_ :: operator ~ ()
{
	int i = 0;
	if (s == NULL)
	{
		cout << "";
	}
	else
	{
		while (s[i] != 0)
		{
			i++;
		}
		while (i >= 0)
		{
			cout << s[i];
			i--;
		}
	}
}

void string_:: string_ :: operator ==(const string_ & _str)
{
	if (this->length != _str.length)
	{
		cout << " Строки разной длины" << endl;
	}
	else
	{
		cout << " Строки равной длины" << endl;
	}
}
void string_:: string_ :: operator > (string_ & _str)
{
	if (this->length > _str.length)
	{
		cout << " 1ая строка содержит больше символов на  " << this->length - _str.length << endl;

	}
	else
	{
		cout << " 2ая строка содержит больше символов на  " << _str.length - this->length << endl;
	}
}
string_ string_ ::operator+(const string_ & _str)
{
	string_ tmp;
	tmp.length = length + _str.length;
	tmp.s = new char[tmp.length + 1];
	strcpy(tmp.s, s);
	strcat(strcat(tmp.s, " "), _str.s);
	return tmp;
}

 string_ string_:: operator=(const string_ &str) {
	if (this == &str)
		return *this;
	if (length != str.length || length == 0) {
		delete[] s;
	}
	length = str.length;
	s = new char[length + 1];
	strcpy(s, str.s);
	return *this;
}

void string_:: string_::sort(string_ _str[], int n)
{
	string_ temp;
	for (int i = 0; i<n - 1; i++)
	{
		for (int j = n - 1; j>i; j--)
		{

			if (strcmp(_str[j].s, _str[j - 1].s)<0)
			{

				temp = _str[j].s;
				_str[j] = _str[j - 1];
				_str[j - 1] = temp;

			}
		}
	}
}