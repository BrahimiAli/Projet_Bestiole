#include "RandDouble.h"

Rand_double::Rand_double(){

}
// Tirage uniforme d'un double entre low et high avec le générateur de nombres pseudo-aléatoires mt19937
Rand_double::Rand_double(double low, double high)
        :r(std::bind(std::uniform_real_distribution<>(low,high),std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count()))){}

double Rand_double::operator()(){
   return r();
 }
