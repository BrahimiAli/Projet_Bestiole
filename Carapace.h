#ifndef CARAPACE_H
#define CARAPACE_H

#include "Accessoire.h"

class Carapace : public Accessoire {

  private :
    double coefCollision;
    double coefVitesse;
    Carapace(){};
  public :
    virtual double getVitesseCoeff() const override;
    Carapace(EspeceA* base, double collision, double vitesse);
    virtual EspeceA* cloner();
    void collisionBestiole() override;
    double getVitesse() const override;
    virtual void draw(UImg& support);

};

#endif
