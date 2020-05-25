#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Accessoire.h"

class Camouflage : public Accessoire {

  private :
    double valeurCamouflage;
    Camouflage(){};
  public :
    Camouflage(EspeceA* base, double val);
    virtual EspeceA* cloner();
    virtual double getCamouflage() const override;
    virtual void draw(UImg& support);
};

#endif
