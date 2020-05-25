//
// Created by user on 07/05/2020.
//

#ifndef BESTIOLES_GR3_KAMIKAZE_H
#define BESTIOLES_GR3_KAMIKAZE_H

#include "Comportement.h"


class Kamikaze: public Comportement {
public:
    std::tuple<int,int,double,double> executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation);
    virtual Kamikaze* dupliquer() const override;
    virtual std::string getName() override;
};


#endif //BESTIOLES_GR3_KAMIKAZE_H
