#ifndef RANDINT_H
#define RANDINT_H

#include <functional>
#include <random>
#include <chrono>
#include <vector>
#include <map>
#include <algorithm>

class Rand_int
{
public:
    Rand_int();
    // Tirage uniforme d'un ENTIER entre low et high avec le générateur de nombres pseudo-aléatoires mt19937
    Rand_int(int low, int high);
    int operator()();

private:
    std::function<int()> r;
};

#endif
