#include <iostream>
#include "calculator.h"
#include "maths.h"

int main() {
    Calculator calc;
    
    double x = 15.0;
    double y = 3.0;

    std::cout << "Square of "<<x<<" is "<<MathFunctions::square(x) << std::endl;
    #ifdef ADVANCED_API
    std::cout << "Cube of "<<x<<" is "<<MathFunctions::cube(x) << std::endl;
    #endif
    std::cout << "--- Standard Operations ---\n";
    std::cout << x << " + " << y << " = " << calc.add(x, y) << "\n";
    std::cout << x << " - " << y << " = " << calc.subtract(x, y) << "\n";
    std::cout << x << " * " << y << " = " << calc.multiply(x, y) << "\n";
    std::cout << x << " / " << y << " = " << calc.divide(x, y) << "\n";

    std::cout << "\n--- Exception Handling ---\n";
    try {
        // Attempting to divide by zero to trigger the exception
        std::cout << "Attempting 15.0 / 0.0...\n";
        calc.divide(15.0, 0.0); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught Exception: " << e.what() << "\n";
    }

    return 0;
}