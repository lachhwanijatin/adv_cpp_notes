#pragma once

namespace MathFunctions{
    double square(double x);

    #ifdef ADVANCED_API
    // assume cube to be an advanced function that you want to selectively compile
    double cube(double x);
    #endif
}