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
		cout << name << " " << age << " лет\n";
	}
};

class Student :public Human
{
	string specialty;
	unsigned int year;		// год обучения.
	int karma;			// успеваемость.
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
		cout << "Cпециальность: " << specialty << " " << year <<  "-й курс, успеваемость " << karma << "!" << endl;
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
		cout << "Специальность: " << specialty << " , опыт преподавания: " << xp << " лет, " << "уровень злости: " << evil << "%." << endl;
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
		cout << "Тема дипломного проекта: " << diploma_theme << endl;
	}
};




void main()
{
	setlocale(LC_ALL, "");
	Human h("Василий", 20);
	h.info();
	
	Student durko("Дурко Василий", 20, "РПО");
	durko.info();
	
	Teacher pablo("Pablo Escobar", 40, "Распространение наркотиков", 25, 50);
	pablo.info();

	Graduate tony("Antonio Montana", 22, "Распространение наркотиков", 5, 90, "Работа с проблемной задолженностью.");
	tony.info();
}