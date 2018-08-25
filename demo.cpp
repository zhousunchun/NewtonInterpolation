#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include "newtoninterp.h"
#include "newtoninterp.cpp"

using namespace std;
using namespace splab;
typedef double Type;

int main()
{
    std::cout<<"newton interpolation"<<std::endl;
    std::vector<Type> x;
    std::vector<Type> y;
    x.push_back(0); x.push_back(30); x.push_back(45); x.push_back(60); x.push_back(90);
    y.push_back(0); y.push_back(0.5); y.push_back(sqrt(2.0)/2); y.push_back(sqrt(3.0)/2); y.push_back(1);
    double D2R = 3.1415926/180.f;
    
    splab::NewtonInterp<Type> poly(x,y);
   
    poly.calcCoefs();
    cout << setiosflags(ios::fixed) << setprecision(4);
    std::cout<<"The true and interpolated values:" << std::endl;
    std::cout << sin(10*D2R) << " " << poly.evaluate(10) << endl;
    std::cout << sin(20*D2R) << " " << poly.evaluate(20) << endl;
    std::cout << sin(50*D2R) << " " << poly.evaluate(50) << endl << endl;
    return 0;
}
