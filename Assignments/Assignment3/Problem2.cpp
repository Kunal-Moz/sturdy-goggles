#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  // Code to find factorial of a number.
 long int n;
 long int factorial(long int);
 
 cout << "Enter number to compute the factorial : " << endl;
 cin >> n;
 
 if( n > 20) {
   cout << "Big Number, can't store it" << endl;
 }
 else if(n < 0) {
   cout << "Can't print factorial for negetive numbers" << endl;
 }
 else{
   cout << "Factorial of " << n << ": " << factorial(n) << endl;
 }
 
}

// Recursive function to calculate the factorial
long int factorial(long int n ){
  if( n== 1 || n == 0){
    return n;
  }
  else{
    return n*factorial(n-1);
  }
}
