//
// Created by user on 09/05/2020.
//

#ifndef BESTIOLES_GR3_PREVOYANTE_H
#define BESTIOLES_GR3_PREVOYANTE_H

#include "Comportement.h"


class Prevoyante: public Comportement {
public:
    std::tuple<int,int,double,double> executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation);
    virtual Prevoyante* dupliquer() const override;
    virtual std::string getName() override;
};


#endif //BESTIOLES_GR3_PEUREUSE_H
