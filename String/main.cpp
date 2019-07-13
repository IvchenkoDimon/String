#include "String.h"

//#define CONSTRUCTOR_CHECK


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