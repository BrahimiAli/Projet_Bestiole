//
// Created by ali on 18/05/2020.
//

#ifndef BESTIOLES_GR3_RANDOM_UTILS_H
#define BESTIOLES_GR3_RANDOM_UTILS_H

#include <functional>
#include <random>
#include <chrono>
#include <vector>
#include <map>
#include <algorithm>

#include "RandDouble.h"
#include "RandInt.h"

template <typename T>
// Pour tirer n élément dans une liste/vector, en respectant les poids dans weight si sum(weight) = 1
// Aucune garantie si sum(weight) != 1
// Méthode qui va être utilisée pour initialiser la population
std::vector<T> utils_init(std::vector<T> list,std::vector<double> weight,int number)
{
    // Vérification des arguments
    if(list.size() != weight.size() && number > 0 )
        throw std::invalid_argument("Size error");
    std::vector<T>  randomlist;
    for(int i=0;i<number;++i)
    {
        randomlist.push_back(random_weighted(list,weight));
    }
    return randomlist;
};

template <typename T>

// Pour titer un élément au hasard dans une liste, en respectant les poids dans weight si sum(weight) = 1
// Aucune garantie si sum(weight) != 1
// Méthode qui va être utilisée pour ajouter au hasard une bestiole au cours de la simulation
T random_weighted(std::vector<T> list,std::vector<double> weight)
{
    // Vérification des arguments
    if(list.size() != weight.size())
        throw std::invalid_argument("Size error");


    // On doit avoir sum(weight) = 1 !!!!
    int n = 1000; //precision max 10e-3
    std::vector<T> randomlist;

    //On commence par remplir randomlist avec n*weight_x pour chaque x dans list
    for(unsigned int i=0;i<list.size();i++)
    {
        if(weight[i]>0)
        {
            for(int j=0;j<n*weight[i];++j)
            {
                randomlist.push_back(list[i]);
            }
        }
    }
    Rand_int rd(0,randomlist.size());
    return randomlist[rd()];
};

#endif //BESTIOLES_GR3_RANDOM_UTILS_H
