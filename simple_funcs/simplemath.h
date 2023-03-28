#ifndef _CUBIC_H
#define _CUBIC_H
#include <cmath>


class SimpleMaths{
public:
  template <typename T>
  static T findMax(T x, T y){
    return (x>y)? x : y;
  }

  static double cubic(double d){
	return pow(d,3);
	}

  private:
    float a;
};



#endif