//
// Created by user on 10/05/2020.
//

#ifndef BESTIOLES_GR3_PEUREUSE_H
#define BESTIOLES_GR3_PEUREUSE_H

#include "Comportement.h"


class Peureuse: public Comportement {
    bool enFuite = false;
    int tempsEnFuite = 0;
    double vitesseInit;
public:
    std::tuple<int,int,double,double> executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation);
    virtual Peureuse* dupliquer() const override;
    virtual std::string getName() override;
};


#endif //BESTIOLES_GR3_PEUREUSE_H
