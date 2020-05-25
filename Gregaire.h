//
// Created by user on 06/05/2020.
//

#ifndef BESTIOLES_GR3_GREGAIRE_H
#define BESTIOLES_GR3_GREGAIRE_H

#include "Comportement.h"

class Gregaire: public Comportement {
public:
    std::tuple<int,int,double,double> executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation) override;
    virtual Gregaire* dupliquer() const override;
    virtual std::string getName() override;
};


#endif //BESTIOLES_GR3_GREGAIRE_H
