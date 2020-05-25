//
// Created by user on 10/05/2020.
//

#ifndef BESTIOLES_GR3_MULTIPLE_H
#define BESTIOLES_GR3_MULTIPLE_H

#include "Comportement.h"


class Multiple: public Comportement {
    int nbComportementsPossibles = 4;
    enum ComportementsPossibles {
        gregaire,
        peureuse,
        prevoyante,
        kamikaze
    };
    Comportement* comportement;
public:
    Multiple();
    Multiple(const Multiple& m);
    ~Multiple();
    std::tuple<int,int,double,double> executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation);
    virtual Multiple* dupliquer() const override;
    virtual std::string getName() override;


};


#endif //BESTIOLES_GR3_MULTIPLE_H
