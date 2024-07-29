#include <iostream>
#include <cstdlib>
int main() {
  //coordinates
  float x1, x2, y1, y2;
  float mpx, mpy;
  float m, b ;
  float m_p, b_p;
	std::cout << "Enter coordinates : (x1 , y1) " << '\n';
  std::cin >> x1 >> y1;
  std::cout << "Enter coordinates : (x2 , y2) " << '\n';
  std::cin >> x2 >> y2;
  
  mpx = (x1 + x2)/2.0 ;
  mpy = (y1 + y2)/2.0 ;
  
  std::cout << "Midpoint: (" << mpx << "," << mpy << ")." << '\n';
  
  if((x2 - x1) == 0.0 ){
    std::cout << "Line perpendicular to X-axis!!" << '\n';
    std::cout << "Equation of line: x = "<< x1 << '\n';
    std::cout << "Equation of perpendicular line : y = 0.0" << '\n';
    }
  else{
    m = (y2 - y1)/(x2 - x1);
    b = y1 - m*x1 ;
    if(b < 0.0){
       std::cout << "Equation of line: y = "<< m << "x - " << abs(b) << '\n';
    }
    else{
       std::cout << "Equation of line: y = "<< m << "x + " << abs(b) << '\n';
    }
    m_p = -1.0/m ;
    b_p = y1 - m_p*x1;
    if(b < 0.0){
       std::cout << "Equation of Perpendicular line: y = "<< m_p << "x - " << abs(b_p) << '\n';
    }
    else{
       std::cout << "Equation of Perpendicular line: y = "<< m_p << "x + " << abs(b_p) << '\n';
    }
  }
  
  b = y1 - m*x1 ;
  
  
  
}
  
    
