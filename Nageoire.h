#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "Accessoire.h"

class Nageoire : public Accessoire {

  private :
    double coefVitesse;
    Nageoire(){};
  public :
    virtual double getVitesseCoeff() const override;
    Nageoire(EspeceA* base, double val);
    double getVitesse() const override;
    virtual EspeceA* cloner();
    virtual void draw(UImg& support);

};

#endif
