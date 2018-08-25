#include <iostream>
using namespace std;

#include "interpolation.h"
#include "newtoninterp.h"

using namespace splab;

template <typename Type> NewtonInterp<Type>::NewtonInterp( const std::vector<Type> &xn,
                                  const std::vector<Type> &yn )
                    : Interpolation<Type>( xn, yn ), coefs(yn)
{
}

template<typename Type> splab::NewtonInterp<Type>::~NewtonInterp()
{
}

template<typename Type> void splab::NewtonInterp<Type>::calcCoefs()
{
    int N = xi.size();
 
    for(int j = 0; j<N-1; ++j)
    {
        for(int i= N-1; i> j; i--)
        {
            coefs[i] = (coefs[i] - coefs[i-1]) / (xi[i] - xi[i-j-1]);
        }
    }
}

template<typename Type> Type splab::NewtonInterp<Type>::evaluate(Type x)
{
    int N = xi.size();
    Type y = 0, tmp = 0;
    
    for(int i = N-1; i>=0; i--)
    {
        double mult = 1;
        for( int j = 0; j < i; j++)
            mult*=(x-xi[j]);
        mult *= coefs[i];
        y += mult;
    }
    return y;
}
template<typename Type> std::vector<Type> splab::NewtonInterp<Type>::getCoefs() const
{
    return coefs;
}



