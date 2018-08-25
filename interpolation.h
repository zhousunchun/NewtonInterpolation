#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>

namespace splab
{
  template <typename Type>
  class Interpolation 
  {
  public:
    Interpolation(){}
    Interpolation(const std::vector<Type> &xn, const std::vector<Type> &yn) 
      : xi(xn),yi(yn)
      {}
      
      virtual ~Interpolation() {}
      virtual void calcCoefs() = 0;
      virtual Type evaluate(Type x) = 0;
  protected:
    std::vector<Type> xi;
    std::vector<Type> yi;
  };
}

#endif
