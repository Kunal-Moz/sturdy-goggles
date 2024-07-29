#include <iostream>
#include <string>
#include <cmath>

int main(void) {
  int const e1 = 7, e2 = 6, e3 = 9 ;
  int const s1 = 2, s2 = 3, s3 = 2 ;
  int const b1 = 0, b2 = 2, b3 = 4, b4 = 6, b5 = 7, b6 = 7, b7 = 1, b8 = 1;
  std::string i1, i2, i3 ;
  std::string e,s,b;
  int sum = 0;
  
  std::cout << "Menu : " << std::endl;
  
  std::cout << "Lunch entries : " << std::endl;
  std::cout << "e1 : Veggie burger            : $7 " << std::endl;
  std::cout << "e2 : Falafel wrap             : $6 " << std::endl;
  std::cout << "e3 : Salami sandwich          : $9" << std::endl;
  std::cout << "Side Options : " << std::endl;
  std::cout << "s1 : French Fries             : $2" << std::endl;
  std::cout << "s2 : Hummus with pita chips   : $3" << std::endl;
  std::cout << "s3 : Celery and carrots       : $2" << std::endl;
  std::cout << "Beverages : " << std::endl;
  std::cout << "b1 : Tap Water                : Free" << std::endl;
  std::cout << "b2 : Sparkiling Water         : $2" << std::endl;
  std::cout << "b3 : Domestic beer            : $4" << std::endl;
  std::cout << "b4 : Imported beer            : $6" << std::endl;
  std::cout << "b5 : Red Wine                 : $7" << std::endl;
  std::cout << "b6 : White wine               : $7" << std::endl;
  std::cout << "b7 : Coffee                   : $1" << std::endl;
  std::cout << "b8 : Tea                      : $1" << std::endl;
  
  std::cout << "Specials ::" << std::endl;
  std::cout << "Veggie burger + French Fries + Non-alcoholic drink --> $8" <<std::endl;
  std::cout << "Falafel + Hummus and pita chips + Tea/Coffee --> $7" <<std::endl;
  std::cout << "Salami Sandwich + Any side + Alcoholic drink --> $13" <<std::endl;
  
  std::cout << "Enter food option using appropriate code : " << std::endl;
  
  std::cin >> i1 ;
  if (i1 == "e1" || i1 == "e2" || i1 == "e3") {
  e = i1;
  //cout << "line1" << e << endl;
  }
else if (i1 == "s1" || i1 == "s2" || i1 == "s3"){
  s = i1;
  //cout << "line2" << s << endl;
  }
else if (i1 == "b1" || i1 == "b2" || i1 == "b3" || i1 == "b4" || i1 == "b5" || i1 == "b6" || i1 == "b7" || i1 == "b8"){
  b = i1;
  //cout << "line3" << b << endl;
  }
else {
  std::cout << "Invalid input, moving to next order" << std::endl;
  }

std::cin >> i2 ;
if (i2 == "e1" || i2 == "e2" || i2 == "e3") {
  e = i2;
  //cout << "line1" << e << endl;
  }
else if (i2 == "s1" || i2 == "s2" || i2 == "s3"){
  s = i2;
  //cout << "line2" << s << endl;
  }
else if (i2 == "b1" || i2 == "b2" || i2 == "b3" || i2 == "b4" || i2 == "b5" || i2 == "b6" || i2 == "b7" || i2 == "b8"){
  b = i2;
  //cout << "line3" << b << endl;
  }
else {
  std::cout << "Invalid input, moving to next order" << std::endl;
  }


std::cin >> i3 ;
if (i3 == "e1" || i3 == "e2" || i3 == "e3") {
  e = i3;
  //cout << "line1" << e << endl;
  }
else if (i3 == "s1" || i3 == "s2" || i3 == "s3"){
  s = i3;
  //cout << "line2" << s << endl;
  }
else if (i3 == "b1" || i3 == "b2" || i3 == "b3" || i3 == "b4" || i3 == "b5" || i3 == "b6" || i3 == "b7" || i3 == "b8"){
  b = i3;
  //cout << "line3" << b << endl;
  }
else {
  std::cout << "Invalid input, moving to bill generation" << std::endl;
  }

  
  if((e =="e1" && s=="s1") && (b=="b1" || b== "b2" || b=="b7" || b=="b8") ){
    sum += 8 ;
    std::cout << "Special offer : Veggie burger + French Fries + Non-alcoholic drink " << std::endl;
    std::cout << "Discounted bill !!!" << std::endl;
  }
  else if((e == "e2" && s == "s2") && (b=="b7" || b=="b8") ){
    sum += 7 ;
    std::cout << "Special offer : Falafel + Hummus and pita chips + Tea/Coffee " << std::endl;
    std::cout << "Discounted bill !!!" << std::endl;
  }
  else if((e =="e3") && (s=="s1" || s=="s2" || s=="s3") && (b=="b3" || b== "b4" || b=="b5" || b=="b6") ){
    sum += 13;
    std::cout << "Special offer : Salami Sandwich + Any side + Alcoholic drink " << std::endl;
    std::cout << "Discounted bill !!!" << std::endl;
  }
  else{
    if(e == "e1"){
      sum += 7;
      std::cout << "Veggie burger" << std::endl;
    }
    else if(e == "e2"){
      sum += 6;
      std::cout << "Falafel wrap" << std::endl;
    }
    else{
      sum += 9;
      std::cout << "Salami sandwich" << std::endl;
    }
    
    if(s == "s1"){
      sum += 2;
      std::cout << "French Fries" << std::endl;
    }
    else if(s == "s2"){
      sum += 3;
      std::cout << "Hummus with pita chip" << std::endl;
    }
    else{
      sum += 2;
      std::cout << "Celery and carrots" << std::endl;
    }
    
    if(b == "b1"){
      sum += 0;
      std::cout << " Tap Water" << std::endl;
    }
    else if(b == "b2"){
      sum += 2;
      std::cout << "Sparkling Water" << std::endl;
    }
    else if(b == "b3"){
      sum += 4;
      std::cout << "Domestic beer" << std::endl;
    }
    else if(b == "b4"){
      sum += 6;
      std::cout << "Imported beer" << std::endl;
    }
    else if(b == "b5"){
      sum += 7;
      std::cout << "Red Wine" << std::endl;
    }
    else if(b == "b6"){
      sum += 7;
      std::cout << "White wine" << std::endl;
    }
    else if(b == "b7"){
      sum += 1;
      std::cout << "Coffee" << std::endl;
    }
    else{
      sum += 1;
      std::cout << "Tea" << std::endl;
    }
    
  }
  
  
  
  std::cout << "Total bill : $" << sum << std::endl;

}

