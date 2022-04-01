/////////////////////////////////////////////////////////////////////////////
// Vector3D.h
// заголовний файл – визначення класу
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma once

class Vector3D
{
private:
	int X, Y, Z;
	
public:
	int GetX() const { return X; }
	int GetY() const { return Y; }
	int GetZ() const { return Z; }
	
	void SetX(int value) { X = value; }
	void SetY(int value) { Y = value; }
	void SetZ(int value) { Z = value; }
	
	

	void Init(int x, int y,int z);
	void Read();
	void Display() const;
	const char* toString() const;
	


	void Multiply(int N);
	
	double Length()const;
	
	const char* DovzinaVectorToNumeral() const;
	

};
//////////////////////////////////////////////////////////////////////////////
// Vector3D.cpp
// файл реалізації – реалізація методів класу
#include <iostream>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <sstream> // підключаємо бібліотеку, яка описує літерні потоки
using namespace std;

 void Vector3D::Display() const
{
	cout << endl;
	cout << " X = " << X << endl;
	cout << " Y = " << Y << endl;
	cout << " Z = " << Z << endl;
	
	
}
 
 void Vector3D::Init(int x, int y,int z)
 {
	 X = x;
	 Y = y;
	 Z = z;
 }
 void Vector3D::Read()
 {
	 int x, y, z;
	 cout << "Input vector value:" << endl;
	 cout << " X = "; cin >> x;
	 cout << " Y = "; cin >> y;
	 cout << " Z = "; cin >> z;
	 
	 Init(x, y,z);

 }
 const char* Vector3D::toString() const
 {
	 stringstream sout;                                              // створили об'єкт "літерний потік"
	 sout << X << " + i * " << Y << " + i * " << Z << endl;                                                          // направили в літерний потік
	 
		                                                               // виведення даних про об'єкт
	 return sout.str().c_str();                                       // str() перетворює літерний потік
	                                                                    // до літерного рядка
 }
 void Vector3D::Multiply(int N)
 { 
	 X *= N;
	 Y *= N;
	 Z *= N;
 }
 double Vector3D::Length()const
 {
	 double length;
	 length = sqrt(X * X + Y * Y + Z * Z);
	 return length;
 }
 
 

 const char* Vector3D::DovzinaVectorToNumeral() const
 {

	 const char* _centuries[11] = { "", "сто",
                                     "двисти", "триста",
                                     "чотириста", "пятсот",
                                           "шистот", "симсот",
                                         "висимсот", "девятсот",
                                                "тисяча aбо >" };
	 
	   const char* _decades[10] =                        { "", "",
	                                                     "двадцять", "тридцять",
	                                                       "сорок", "п’ятдесять",
	                                                 "шистдесять", "симдесять",
	                                                 "висимдесять", "дев’яносто" };
	      const char* _digits[20] = { "", "odyn",
											"два", "три",
											 "чотири", "п’ять",
												 "шисть", "сим",
												  "висим", "дев’ять",
												  "десять", "одинадцять",
													"дванадцять", "тринадцать",
													  "чотирнадцять", "п’ятнадцять",
														 "шистнадцять", "симнадцять",
							                        "висимнадцять", "дев’ятнадцять" };




	   if(Length() >=1000)
		   return _centuries[10];

	   
		  int length= floor(Length());
		   int cen= length/100;

		   length = length % 100;
		   int dec = length  / 10;
		   int dig;
		   if (dec == 0 || dec == 1)
			   dig = length % 20;
		   else
			   dig = length % 10;

	   char s[100] = "";
	   strcat_s(s, _centuries[cen]);
	   strcat_s(s, " ");
	   strcat_s(s, _decades[dec]);
	   strcat_s(s, " ");
	   strcat_s(s, _digits[dig]);
		   return s;
 }
 //////////////////////////////////////////////////////////////////////////////
// Source.cpp
// головний файл проекту – функція main
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

 using namespace std;
 int main()
 {
	 setlocale(LC_ALL, "ru");
	 Vector3D a;
	 a.Read();
	 a.Display();
	 
	 cout << "Довжина вектора a = " << a.Length() << endl << endl;
 	 char s[100];
	 strcpy_s(s, a.toString());
	 cout << s << endl << endl;
	 strcpy_s(s, a.DovzinaVectorToNumeral());
	 cout << s << endl << endl;
	 a.Multiply(5);
	 a.Display();
	 a.GetX();
	 a.GetY();
	 a.GetZ();
	 


	 Vector3D b;
	 b.Read();
	 b.Display();

	 b.GetX();
	 b.GetY();
	 b.GetZ();


	 cout << "Довжина вектора a = " << b.Length() << endl << endl;
	 
	 if (a.Length() < b.Length())
		 cout << "довжина вектора (а) менша за довжину вектору (b)" << endl;
	 if (a.Length() > b.Length())
		 cout << "довжина вектора (а) бильша за довжину вектору (b)" << endl;
	 if (a.Length() == b.Length())
		 cout << "довжина вектора (а) доривнює довжини вектору (b)" << endl;
	 
	 
	 cin.get();
	 return 0;
 }