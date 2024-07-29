#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void){
 
  int size;
  cout << "Input number of coordinates" << endl;
  cin >> size;
  
  if(size <= 0){
    cout << "Can't be zero or negetive, Enter again" << endl;
    cin >> size;
  }
  
  float dmin = 10000;
  float distance(float,float,float,float);
 
  float dist;
  vector<float> X;
  vector<float> Y;
  
  float x1,x2,y1,y2;
 
  cout << "Enter the set of " << size <<  " coordinates :" << endl;
  cout << "Note : Press Enter after each entry" << endl;
  for (int i = 0; i < 2*size; i++){
    float input;
    cin >> input;
    if(i%2 == 0){
      X.push_back(input) ;
    }
    else{
      Y.push_back(input) ;
    }
  }
  cout << "All the coordinates" << endl;
  for(int i=0; i < size; i++ ) {
    cout << "(" << X[i] <<"," << Y[i] << ")" << endl;
  }
  
  for( int i=0; i < size; i++){
    for( int j=0; j < size; j++){
      if( i != j ){
        dist = distance(X[i],Y[i],X[j],Y[j]);
      
        if(dist <= dmin){
          dmin = dist;
          x1 = X[i];
          y1 = Y[i];
          x2 = X[j];
          y2 = Y[j];
        }
      }
    }
  }
  
  cout << "Pair with minimum pairwise distance : (" << x1 << "," << y1 <<") and (" << x2 <<"," << y2 << ")" << endl;
  
}


float distance(float xi, float yi, float xj, float yj){
  return sqrt(pow((xj-xi),2) + pow((yj-yi),2));
}

