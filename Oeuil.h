#ifndef OEIL_H
#define OEIL_H

#include "Capteur.h"

class Oeuil : public Capteur {
  public :
    Oeuil(EspeceA* base, double detec, double dist, double angle);
    bool jeTeVois(const Bestiole & autre) const override;
    EspeceA* cloner() override;
    virtual void draw(UImg& support);

};

#endif
