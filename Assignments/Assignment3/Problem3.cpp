#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  // Code to find factorial of a number.
 long int n;
 long int factorial(long int);
 double sterling_factorial(long int);
 double sterling(long int);
 
 cout << "Enter number to compute the factorial : " << endl;
 cin >> n;
 
 if( n > 20) {
   cout << "Big number can't compute using recursion" << endl;
   cout << "Factorial of " << n << " using Sterling Approximation : " << sterling_factorial(n) << std::endl;
   cout << "Logarithm of the factorial :" << sterling(n) << endl;
 }
 else if(n < 0) {
   cout << "Can't print factorial for negetive numbers" << endl;
 }
 else{
   cout << "Factorial of " << n << ": " << factorial(n) << endl;
 }
 
}


long int factorial(long int n ){
  if( n== 1 || n == 0){
    return n;
  }
  else{
    return n*factorial(n-1);
    cout << n*factorial(n-1) << endl;
  }
}

double sterling_factorial(long int n){
  double f;
  double pi=3.1415926535898, e = 2.71828182846;
  f = double(n);
  return sqrt(2.0*pi*f)*pow((f/e),f) ;
}

double sterling(long int n){
  return double(n)*log(double(n)) - double(n);
}
