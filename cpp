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
