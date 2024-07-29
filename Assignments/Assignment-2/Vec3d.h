#ifndef VEC3D_H
#define VEC3D_H

#include <cmath>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>

// 3D vector class
class Vector3d{
public:
  Vector3d(double ix, double iy, double iz) :
    x_(ix),y_(iy),z_(iz){};

  inline double x() const { return x_;}
  inline double y() const { return y_;}
  inline double z() const { return z_;}
  double perp() const ;
  double perp2() const ;
  double r2() const ;
//  double px() const ;
//  double py() const ;
//  double pz() const ;
//  double p() const ;
  double r() const ;
  double phi() const ;
  double theta() const ;
  double cosTheta() const ;

//  std::string PrintPtEtaPhiM() const ;
//  std::string PrintPxPyPz() const ;
  std::string PrintXYZ() const ;
  std::string Print() const ;
  
  
  Vector3d operator+( const Vector3d & right) const ;
  Vector3d operator-( const Vector3d & right) const ;
  double operator*(const Vector3d & right) ;

  
protected :
  double x_;
  double y_;
  double z_;

};


void testVector3ds();

#endif

