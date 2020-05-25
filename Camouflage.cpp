#include "Camouflage.h"
#include <iostream>

Camouflage::Camouflage(EspeceA* base, double val) {
  this->name = "Camouflage";
  this->base = base;
  this->valeurCamouflage = val;
}

double Camouflage::getCamouflage() const {
  return this->valeurCamouflage+this->getBase()->getCamouflage();
}

EspeceA* Camouflage::cloner() {
  return new Camouflage(this->getBase()->cloner(), this->valeurCamouflage);
}

void Camouflage::draw(UImg& support) {
  this->getBase()->draw(support);
  support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon - 3,getLightColor()); // Dessine un cerle gris au sein de la besitole
}
