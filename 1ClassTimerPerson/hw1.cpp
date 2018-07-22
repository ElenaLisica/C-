
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
// hw1
class Drob {
private:
	int ch, zn;
public:
	Drob();
	void SetCH(int _ch);
	void SetZN(int _zn);
	int GetCH()	{ return ch;}
	int GetZN() { return zn;}
	Drob Add(int _ch, int _zn);
	Drob Minus(int _ch, int _zn);
	Drob Multiply(int _ch, int _zn);
	Drob Division(int _ch, int _zn);
	void Print();
};


void Drob:: Print()
{
	cout << ch << "/" << zn << endl;

}


Drob Drob:: Add(int _ch, int _zn)
{
	Drob C;
	C.ch = this->ch*_zn + this->zn*_ch;
	C.zn = this->zn*_zn;
	C.Print();
	return C;
}


Drob Drob:: Minus(int _ch, int _zn)
{
	Drob C;
	C.ch = this->ch*_zn - this->zn*_ch;
	C.zn = this->zn*_zn;
	C.Print();
	return C;
}


Drob Drob:: Multiply(int _ch, int _zn)
{
	Drob C;
	C.ch = this->ch*_ch;
	C.zn = this->zn*_zn;
	C.Print();
	return C;
}


Drob Drob:: Division(int _ch, int _zn)
{
	Drob C;
	C.ch = this->ch*_zn;
	C.zn = this->zn*_ch;
	C.Print();
	return C;
}


Drob::Drob()
{
	ch = 1;
	zn = 1;
}


void Drob::SetCH(int _ch)
{
		ch = _ch;
}


void Drob::SetZN(int _zn)
{
	zn = _zn;
}


class Time
{
private: int StartMin, StartSec, StartHour, EndMin, EndSec, EndHour;
public:
	int GetStartMin() { return StartMin; }
	int GetStartSec() { return StartSec; }
	int GetStartHour() { return StartHour; }
	int GetEndMin() { return EndMin; }
	int GetEndSec() { return EndSec; }
	int GetEndHour() { return EndHour; }

	Time() {
		StartMin = 0;
		StartSec = 0;
		StartHour = 0;
		EndMin = 0;
		EndSec = 0;
		EndHour = 0;
	}

	void SetStartMin(int min)
	{
		StartMin = min;
	}


	void SetStartSec(int sec)
	{
		StartSec = sec;
	}


	void SetStartHour(int h)
	{
		StartHour = h;
	}

	void SetEndMin(int min)
	{
		EndMin = min;
	}


	void SetEndSec(int sec)
	{
		EndSec = sec;
	}


	void SetEndHour(int h)
	{
		EndHour = h;
	}
	
};


void Show(int h, int m, int s)
{
	printf("%02i: %02i : %02i\n", h, m, s);
}



void main()
{
	setlocale(LC_ALL, "Russian");
	int answer;
	do
	{
		system("CLS");
		cout << " �������: " << endl << "1. �������� � �������" << endl << "2. ���������� � ������" << endl <<"3. �����";
		do
		{
			cout << endl << " ������� ����� �������. ";
			cin >> answer;
			if (answer != 1 && answer != 2 && answer != 3 )
				cout << endl << " ������� ���������� ����� �������" << endl;
		} while (answer != 1 && answer != 2 && answer != 3 );
		system("CLS");
		Drob A, B;
		switch (answer)
		{
		case 1:
			int c;
			cout << " ������� ��������� ������ �����" << endl;
			cin >> c;
			A.SetCH(c);
			do
			{
				cout << " ������� ����������� ������ �����" << endl;
				cin >> c;
			} while (!c);
			A.SetZN(c);
			cout << "������ �����:  ";
			A.Print();
			cout << " ������� ��������� ������ �����" << endl;
			cin >> c;
			B.SetCH(c);
			do
			{
				cout << " ������� ����������� ������ ����� " << endl;
				cin >> c;
			} while (!c);
			B.SetZN(c);
			cout << "������ �����:  ";
			B.Print();
			cout << "��������� �������� ������: ";
			A.Add(B.GetCH(), B.GetZN());

			cout << "��������� ��������� ������: ";
			A.Minus(B.GetCH(), B.GetZN());

			cout << "��������� ��������� ������: ";
			A.Multiply(B.GetCH(), B.GetZN());

			cout << "��������� ������� ������: ";
			A.Division(B.GetCH(), B.GetZN());
			system("pause");
			break;

		case 2:
			int x;
			Time Start, End, Prom;
			cout << " ����������";
			cout << " ������� �������� ����� �����������. ����: " << endl;
			cin >> x;
			End.SetEndHour(x);
			cout << endl << " ������:";
			cin >> x;
			End.SetEndMin(x);
			cout << endl << " �������:";
			cin >> x;
			End.SetEndSec(x);
			x = 3600 * End.GetEndHour() + 60 * End.GetEndMin() + End.GetEndSec();
			int ch, min, sec;
			ch = x / 3600;
			min = (x - 3600 * ch) / 60;
			sec = x - 3600 * ch - 60 * min;
			cout << ch << "  " << min << "  " << sec;
			do
			{
				system("cls");
				ch = x / 3600;
				min = (x - 3600 * ch) / 60;
				sec = (x - 3600 * ch - 60 * min);

				Show(ch, min, sec);
				Sleep(1);
				x = x - 1;
			} while (x >= 0 && !_kbhit());

			cout << " ������";
			cout << " ������� �������� ����� �������. ����: " << endl;
			cin >> x;
			End.SetEndHour(x);
			cout << endl << " ������:";
			cin >> x;
			End.SetEndMin(x);
			cout << endl << " �������:";
			cin >> x;
			End.SetEndSec(x);
			int end;
			end = 3600 * End.GetEndHour() + 60 * End.GetEndMin() + End.GetEndSec();
			x = 0;
			do
			{
				system("cls");
				ch = x / 3600;
				min = (x - 3600 * ch) / 60;
				sec = (x - 3600 * ch - 60 * min);
				Show(ch, min, sec);
				Sleep(1);
				x = x + 1;
			} while (x != end + 1 && !_kbhit());
			break;
		}
	}
	while ( answer !=3 );

	}













