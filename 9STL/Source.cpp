
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
	Person person1("Николай", "Егерев", 3);
	Person person2("Руслан", "Мечев", 2);
	Person person3("Светлана", "Лама", 1);
	Person person4("Николай", "Бондарев", 5);
	Person person5("Антон", "Котов", 2);
	Person person6("Сергей", "Кононенко", 1);

	persons.push_back(person1);
	persons.push_back(person2);
	persons.push_back(person3);
	persons.push_back(person4);
	persons.push_back(person5);
	persons.push_back(person6);

	cout << "Список студентов" << endl << endl << endl;
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}


	std::sort(persons.begin(), persons.end(), Person::sortSurname);

	cout << endl << endl << "Сортировка по фамилии" << endl << endl << endl;
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}

	cout << endl << endl << "Сортировка по имени" << endl << endl << endl;
	std::sort(persons.begin(), persons.end(), Person::sortName);
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}

	cout << endl << endl << "Сортировка по курсу" << endl << endl << endl;
	std::sort(persons.begin(), persons.end(), Person::sortcourse);
	for (int i = 0; i < persons.size(); ++i)
	{
		persons[i].print();
	}

	return 0;
}