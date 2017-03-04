Main Source: https://isocpp.org/get-started
Compiler To Use: https://www.visualstudio.com/downloads/ (Visual Studio Community)


//Guessing Number Game
//covers stream I/O, local variable & flow control
#include <iostream>
using namespace std;

int main() {
int answer = 3;
int guess;
bool loop = true;

cout << "Welcome to guess my number game" << endl;
cout << "Enter your guess number: ";
cin >> guess;

while (loop == true)
{
  if (guess > answer) {
    cout << "Guessed number is too high. Try again" << endl;
  }

  if (guess < answer) {
    cout << "Guessed number is too low. Try again." << endl;
  }

  cout << "Enter your guess number: ";
  cin >> guess;
  if (guess == answer)
  {
    cout << "Congratulations! You got the right number." << endl;
    loop = false;
  }
}
return 0;
}



//covers functions and headers
//overload.cpp
#include "stdafx.h"

#include <iostream>
using namespace std;
#include "function.h"


int main()
{
	auto a = add(3, 4);
	cout << "3 + 4 is " << a;
	double b = add(1.2, 3.4);
	cout << endl;
	cout << "1.2 + 3.4 is " << b;

	cout << endl;
	auto c = add(1.1, 2.2, 3.3);
	cout << "1.1 + 2.2 + 3.3 is " << c;

	//impossible to overload on return type (do not have side effects)
	add(0, 0);
	add(0, 0, 0);
	cout << endl;

	//test boolean argument return bool type
	if (test(true))
	{
		cout << "true passes the test" << endl;
	}

	if (test(3.2))
	{
		cout << "3.2 passes the test" << endl;
	}

	//overload based on the number of arguments. below is illegal passing an int type argument.
	//if (test(3))
	//{
	//	cout << "3 passes the test" << endl;
	//}

	return 0;
}


//function.cpp
#include "stdafx.h"
//two functions with the same name but different numbers of parameters - overloading
double add(double x, double y)
{
	return x + y;
}

double add(double a, double b, double c)
{
	return a + b + c;
	//or return add(add(a,b),c);
}

bool test(bool x)
{
	return x;
}
bool test(double x)
{
	return x > 0;
}

//void means nothing "special trick to return generic type". 
//sample function that does not return anything.
void test(void)
{
	return;
}


//function.h
#pragma once
double add(double x, double y);
double add(double a, double b, double c);
bool test(bool x);
bool test(double x);
void test(void);
