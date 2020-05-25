#include "RandInt.h"

Rand_int::Rand_int(){

}
// Tirage uniforme d'un ENTIER entre low et high avec le générateur de nombres pseudo-aléatoires mt19937
Rand_int::Rand_int(int low, int high)
        :r(std::bind(std::uniform_int_distribution<>(low,high),std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count()))){}

int Rand_int::operator()(){
   return r();
 }
