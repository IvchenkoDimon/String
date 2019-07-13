#include <iostream>
using namespace std;

//#define CONSTRUCTOR_CHECK
class String;
String operator+(const String& left, const String& right);

class String
{
	int size;			//Размер строки.
	char* str;			//Адрес строки в динамической памяти.
public:
	const int get_size() const;
	const char* get_str()const;
	char* get_str();
	//			Constuctors:
	String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	//				Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	char& operator[](int i);
	const char& operator[](int i) const;
	String& operator+=(const String& other);
	//				Methods:
	void print();
};

const int String::get_size() const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constuctors:
String::String(int size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;

}
String::String(const char str[])
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}
//				Operators:
String& String::operator=(const String& other)
{
	// Проверяем, является ли тот объект этим объектом:
	if (this == &other)return *this;
	// Удаляем старое значение объекта:
	delete[] this->str;

	// Копируем значение другого объекта:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment: " << this << endl;
	return *this;
}
char& String::operator[](int i)
{
	return this->str[i];
}
const char& String::operator[](int i) const
{
	return this->str[i];
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
//				Methods:
void String::print()
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat = left.get_size() + right.get_size() - 1;
	// Вариант №1
	/*for (int i = 0; left.get_str()[i]; i++)
		*(cat.get_str() + i) = left.get_str()[i];
	for (int i = 0; right.get_str()[i]; i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
		// Вариант №2
	for (int i = 0; left[i]; i++)
		cat[i] = left[i];
	for (int i = 0; right[i]; i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}


void main()
{
	setlocale(LC_ALL, " ");
#ifdef CONSTRUCTOR_CHECK
	//String str1 = "Hello";
	cout << typeid("Hello").name() << endl;
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = str1;
	cout << str2 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
	cout << "\n------------------------------\n";
	str2 = str2;
	cout << str2 << endl;
	cout << "\n------------------------------\n";
#endif // CONSTRUCTOR_CHECK

	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1 + " " + str2; //MoveConstructor
	String str3;
	str3 = str1 + " " + str2; //MoveAssignment
	cout << str3 << endl;
	/*str1 += str2;
	cout << str1 << endl;*/

}