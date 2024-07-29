#include "Vec3d.h"


double Vector3d::r2() const {return x_*x_ + y_*y_ + z_*z_; }
double Vector3d::r() const {return sqrt(r2()) ;}
double Vector3d::perp() const { return sqrt(perp2()); }
double Vector3d::perp2() const { return x_*x_+y_*y_; }
double Vector3d::phi() const { return x_==0.0 && y_ == 0.0 ? 0.0 : atan2(y_,x_); }
double Vector3d::theta() const { return  x_ == 0.0 && y_ == 0.0 && z_ == 0.0 ? 0.0 : atan2(perp(),z_); }
double Vector3d::cosTheta() const {
  double mag = sqrt(x_*x_ + y_*y_ + z_*z_);
  return mag == 0. ? 1.0 : z_ / mag;
}
//double Vector3d::eta() const {
//  double costheta = cosTheta();
//  if (costheta*costheta < 1) return -0.5* log( (1.0-costheta)/(1.0+costheta) );
//  if (z_ == 0.) return 0;
//  if (z_ > 0.) return 10e10;
//  else        return -10e10;
//}

  
std::string Vector3d::PrintXYZ() const {
  std::stringstream ss;
  ss << "(x,y,z) = (" << x_ << ", " << y_ << ", " << z_ << ")";
  return std::move(ss.str());
};

std::string Vector3d::Print() const {
  std::stringstream ss;
  ss << PrintXYZ();
  return std::move(ss.str());
};
  
  
Vector3d Vector3d::operator+( const Vector3d & right) const { return std::move( Vector3d(x_+right.x_,y_+right.y_,z_+right.z_) ); }
Vector3d Vector3d::operator-( const Vector3d & right) const { return std::move( Vector3d(x_-right.x_,y_-right.y_,z_-right.z_) ); }
double Vector3d::operator*(const Vector3d & right) { return x_*right.x_ + y_*right.y_ + z_*right.z_; }



void testVector3ds()
{

  std::cout << "Testing four vectors:" << std::endl;
  Vector3d v1(1.0,0.0,0.0);
  Vector3d v2(0.0,1.0,0.0);
  Vector3d v3(0.0,0.0,1.0);

  std::cout << v1.Print() << std::endl;
  std::cout << v2.Print() << std::endl;
  std::cout << v3.Print() << std::endl;

  Vector3d s1 = v1 + v2;
  Vector3d s2 = v1 + v3;
  std::cout << s1.Print() << std::endl;
  std::cout << s2.Print() << std::endl;
  std::cout << v1.r2() << std::endl;
  std::cout << v1.r() << std::endl;
  
}

