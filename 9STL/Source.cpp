
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


class Person
{
private:
	std::string name;
	std::string surname;
	int course;
public:
	Person(std::string name, std::string surname, int course) : name{ name }, surname{ surname }, course{ course } {};
	void print() { std::cout << name << " " << surname << " " << course << std::endl; };
	static bool sortName(Person const &A, Person const &B) { return A.name < B.name; };
	static bool sortSurname(Person const &A, Person const &B) { return A.surname < B.surname; };
	static bool sortcourse(Person const &A, Person const &B) { return A.course < B.course; };
};

int main()
{
	setlocale(LC_ALL, "russian");
	std::vector<Person> persons;
	Person person1("�������", "������", 3);
	Person person2("������", "�����", 2);
	Person person3("��������", "����", 1);
	Person person4("�������", "��������", 5);
	Person person5("�����", "�����", 2);
	Person person6("������", "���������", 1);

	persons.push_back(person1);
	persons.push_back(person2);
	persons.push_back(person3);
	persons.push_back(person4);
	persons.push_back(person5);
	persons.push_back(person6);

	cout << "������ ���������" << endl << endl << endl;
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}


	std::sort(persons.begin(), persons.end(), Person::sortSurname);

	cout << endl << endl << "���������� �� �������" << endl << endl << endl;
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}

	cout << endl << endl << "���������� �� �����" << endl << endl << endl;
	std::sort(persons.begin(), persons.end(), Person::sortName);
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}

	cout << endl << endl << "���������� �� �����" << endl << endl << endl;
	std::sort(persons.begin(), persons.end(), Person::sortcourse);
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}

	return 0;
}