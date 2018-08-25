#ifndef NEWTONINTERP_H
#define NEWTONINTERP_H

#include "interpolation.h"

namespace splab
{
  template <typename Type> 
  class NewtonInterp : public Interpolation<Type>
  {
  public:
    using Interpolation<Type>::xi;
    using Interpolation<Type>::yi;
    NewtonInterp() {};
    NewtonInterp(const std::vector<Type> &xn, const std::vector<Type> &yn);
    ~NewtonInterp();
    
    void calcCoefs();
    Type evaluate(Type x);
    std::vector<Type> getCoefs() const;
  private:
    std::vector<Type> coefs;
  };
}
#endif