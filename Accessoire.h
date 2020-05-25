#ifndef ACCESSOIRE_H
#define ACCESSOIRE_H

#include "Decorateur.h"

class Accessoire : public Decorateur {

  public :
    virtual double getVitesse() const override;
    virtual double getCamouflage() const override;

};

#endif
