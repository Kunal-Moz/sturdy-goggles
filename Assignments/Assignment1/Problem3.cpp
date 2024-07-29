#include <iostream>
int main(void){
  int x0 = 2;
  int x;
  long int y0 = 2;
  long int y;
  unsigned long int z0 = 2;
  unsigned long int z ;
  x = x0;
  y = y0;
  z = z0;
  for ( unsigned int i = 0; i < 10; i++) {
    std::cout << i <<"  " << x << "  " << y << "  " << z << "\n";
    x = x*x;
    y = y*y;
    z = z*z;
    
  }
  std::cout << std::endl;
  return 0;
}
