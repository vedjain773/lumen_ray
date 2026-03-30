#include "rand.h"
#include <random>

double get_random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

double get_random_double(double low, double high) {
    return low + (high-low)*get_random_double();
}
