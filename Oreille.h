#ifndef OREILLE_H
#define OREILLE_H

#include "Capteur.h"

class Oreille : public Capteur {
    Oreille(){};
public :
    Oreille(EspeceA* base, double detec, double dist);
    bool jeTeVois(const Bestiole & autre) const override;
    virtual EspeceA* cloner();
    virtual void draw(UImg& support);

};

#endif
