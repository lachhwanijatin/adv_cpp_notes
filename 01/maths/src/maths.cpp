#include "maths.h"

namespace MathFunctions
{
    double square(double x) { return x*x; }

    #ifdef ADVANCED_API
    // assume cube to be an advanced function that you want to selectively compile
    double cube(double x){ return x*x*x; }
    #endif
}