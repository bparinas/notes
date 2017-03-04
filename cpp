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




// stringmanipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	string firstWord;
	string secondWord;

	cout << "Welcome to my which is longer game." << endl;
	cout << "User has to enter two words to play this game." << endl;
	cout << "Enter the first word: ";
	//cin >> firstWord;
	//phrases with spaces
	getline(cin, firstWord);
	cout << "Enter the second word: ";
	//cin >> secondWord;
	//phrases with spaces
	getline(cin, secondWord);

		if (firstWord.length() > secondWord.length())
		{
			cout << firstWord + " is longer." << endl;
		}
		if (firstWord.length() < secondWord.length())
		{
			cout << secondWord + " is longer." << endl;
		}
		if (firstWord.length() == secondWord.length())
		{
			cout << "They are the same length." << endl;
		}
	return 0;
}


//code covers vectors!
// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

//for sort and count
#include <algorithm>

using namespace std;

int main()
{
	//declare vector templete int
	vector<int> vInt;
	for (int i = 0; i < 10; i++)
	{
		//push item onto the end of the vector
		vInt.push_back(i);
	}

	//print content of vector vInt
	for (auto item : vInt)
	{
		cout << item << " ";
	}
	cout << endl;

	vector<string> vStr; //vector vStr scope will end after the return 0 bracket.
	cout << "Enter three words ";
	for (int i = 0; i < 3; i++) //int i scope after the for loop end bracket
	{
		string s;
		cin >> s;
		vStr.push_back(s);
	}

	for (auto item : vStr) //auto item scope after the for loop end bracket
	{
		cout << item << " ";
	}
	cout << endl;

	//type safety example:
	//string s = "CPP";
	//vStr.push_back(s);
	//vInt.push_back(s); //conversion error from std string to init

	cout << "int vector vi has " << vInt.size() << " elements";
	vInt[5] = 3;
	vInt[6] = -1;
	vInt[1] = 99;
	cout << endl;

	for (auto item : vInt)
	{
		cout << item << " ";
	}
	cout << endl;

	for (unsigned int i = 0; i < vInt.size(); i++)
	{
		cout << vInt[i] << " ";
	}
	cout << endl;

	for (auto i = begin(vInt); i != end(vInt); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	sort(begin(vStr), end(vStr));
	for (auto item : vStr)
	{
		cout << item << " ";
	}
	cout << endl;

	int threes = count(begin(vInt), end(vInt), 9);
	cout << "vector of ints has " << threes << " elements with value 9";
	cout << endl;

	int tees = count(begin(vStr[0]), end(vStr[0]), 't');
	cout << "first word has " << tees << " letter t's";

    return 0;
}

