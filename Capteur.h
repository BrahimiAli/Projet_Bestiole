#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "Decorateur.h"

class Capteur : public Decorateur {

  protected :
    double capaciteDetection;
    double angle;
    double distance;

  public :
    virtual bool jeTeVois(const Bestiole & autre) const override = 0;
};

#endif
