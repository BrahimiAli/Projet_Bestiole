#include "Accessoire.h"

double Accessoire::getVitesse() const {
  return this->getBase()->getVitesse();
}

double Accessoire::getCamouflage() const {
  return this->getBase()->getCamouflage();
}
