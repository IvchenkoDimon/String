#include <iostream>
#include <string>
using namespace std;

class Human
{
	string name;
	unsigned int age;
public:
	const string& get_name() const
	{
		return this->name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_name(string& name)
	{
		this->name = name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(string name, unsigned int age) :name(name), age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		cout << name << " " << age << " ���\n";
	}
};

class Student :public Human
{
	string specialty;
	unsigned int year;		// ��� ��������.
	int karma;			// ������������.
public:
	const string& get_specialty() const
	{
		return this->specialty;
	}
	unsigned int get_year() const
	{
		return year;
	}
	int get_karma() const
	{
		return this->karma;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	unsigned int set_year(unsigned int year)
	{
		return this->year = year;
	}
	int set_karma(int karma)
	{
		return this->karma = karma;
	}
	//				Constructors:
	Student
	(
		const string& name, unsigned int age,
		const string& specialty, unsigned int year = 1, int karma = 0
	):Human(name, age)
	{
		this->specialty = specialty;
		this->year = year;
		this->karma = karma;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//			Methods:
	void info()
	{
		Human::info();
		cout << "C������������: " << specialty << " " << year <<  "-� ����, ������������ " << karma << "!" << endl;
	}
};

class Teacher :public Human
{
	string specialty;
	int evil;
	unsigned int xp;
public:
	const string& get_specialty() const
	{
		return this->specialty;
	}
	unsigned int get_xp() const
	{
		return this->xp;
	}
	int get_evil() const
	{
		return this->evil;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	unsigned int set_xp(unsigned int xp)
	{
		return this->xp = xp;
	}
	int set_evil(int evil)
	{
		return this->evil = evil;
	}
	//				Constructors:
	Teacher
	(
		const string& name, unsigned int age, const string& specialty, unsigned int xp = 0, int evil = 0
	) :Human(name, age)
	{
		this->specialty = specialty;
		this->xp = xp;
		this->evil = evil;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()
	{
		Human::info();
		cout << "�������������: " << specialty << " , ���� ������������: " << xp << " ���, " << "������� ������: " << evil << "%." << endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string get_diploma_theme() const
	{
		return this->diploma_theme;
	}
	const string& set_diolma_theme(const string& diploma_theme)
	{
		return this->diploma_theme = diploma_theme;
	}
	//				Constructors:
	Graduate
	(
		const string& name, unsigned int age,
		const string& specialty, unsigned int year, int karma,
		const string& diploma_thema
	) :Student(name, age, specialty, year, karma)
	{
		this->diploma_theme = diploma_thema;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//			Methods:
	void info()
	{
		Student::info();
		cout << "���� ���������� �������: " << diploma_theme << endl;
	}
};




void main()
{
	setlocale(LC_ALL, "");
	Human h("�������", 20);
	h.info();
	
	Student durko("����� �������", 20, "���");
	durko.info();
	
	Teacher pablo("Pablo Escobar", 40, "��������������� ����������", 25, 50);
	pablo.info();

	Graduate tony("Antonio Montana", 22, "��������������� ����������", 5, 90, "������ � ���������� ��������������.");
	tony.info();
}