#pragma once

namespace Physics{
#if defined(_WIN32) || defined(_WIN64)
    #ifdef PHYSICS_EXPORT
        #define PHYSICS_API __declspec(dllexport)
    #else
        #define PHYSICS_API __declspec(dllimport)
    #endif
#elif defined(__linux__) || defined(__APPLE__)
    #define PHYSICS_API __attribute__((visibility("default")))
#endif
    PHYSICS_API double calculateForce(double mass, double acceleration);
    PHYSICS_API double calculateKineticEnergy(double mass, double velocity);
    PHYSICS_API double calculatePotentialEnergy(double mass, double gravity, double height);
}