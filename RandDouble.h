#ifndef RANDDOUBLE_H
#define RANDDOUBLE_H

#include <functional>
#include <random>
#include <chrono>
#include <vector>
#include <map>
#include <algorithm>

class Rand_double
{
public:
    Rand_double();
    // Tirage uniforme d'un double entre low et high avec le générateur de nombres pseudo-aléatoires mt19937
    Rand_double(double low, double high);

    double operator()();

private:
    std::function<double()> r;
};

#endif
