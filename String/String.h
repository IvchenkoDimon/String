#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;			//������ ������.
	char* str;			//����� ������ � ������������ ������.
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


