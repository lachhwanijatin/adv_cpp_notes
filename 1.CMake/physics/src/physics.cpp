#include "physics.h"

namespace Physics{
    double calculateForce(double mass, double acceleration){ return mass*acceleration;}
    double calculateKineticEnergy(double mass, double velocity){ return 0.5*mass*velocity*velocity;}
    double calculatePotentialEnergy(double mass, double gravity, double height){ return mass*gravity*height;}
}