//
// Created by user on 06/05/2020.
//

#ifndef BESTIOLES_GR3_COMPORTEMENT_H
#define BESTIOLES_GR3_COMPORTEMENT_H

#include "Bestiole.h"
#include "Configuration.h"
#include <tuple>
#include <list>
#include "RandomUtils.h"

class Comportement{
public:
    virtual std::tuple<int,int,double,double> executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation)=0;
    virtual Comportement* dupliquer() const = 0;
    virtual ~Comportement(){};
    virtual std::string getName()=0;
};

#endif //BESTIOLES_GR3_COMPORTEMENT_H
