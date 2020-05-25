#include "Nageoire.h"

Nageoire::Nageoire(EspeceA* base, double val) {
  this->name = "Nageoire";
  this->base = base;
  this->coefVitesse = val;
}


double Nageoire::getVitesse() const {
  return this->coefVitesse * this->getBase()->getVitesse();
}

EspeceA* Nageoire::cloner() {
  return new Nageoire(this->getBase()->cloner(), this->coefVitesse);
}

double Nageoire::getVitesseCoeff() const {
  return this->coefVitesse;
}

void Nageoire::draw(UImg& support) {
  this->getBase()->draw(support);

  double xt = (double) this->getX() - cos(this->getOrientation())*Config::getInstance()->rayon*1.5;
  double yt = (double) this->getY() + sin(this->getOrientation())*Config::getInstance()->rayon*1.5;
  int x0 = xt;
  int y0 = yt;
  int x1 = xt - cos(this->getOrientation()+M_PI/3)*Config::getInstance()->rayon*1.5;
  int x2 = xt - cos(this->getOrientation()-M_PI/3)*Config::getInstance()->rayon*1.5;
  int y1 = yt + sin(this->getOrientation()+M_PI/3)*Config::getInstance()->rayon*1.5;
  int y2 = yt + sin(this->getOrientation()-M_PI/3)*Config::getInstance()->rayon*1.5; // Dessine une petite nageoire a l'arriere du la bestiole
  support.draw_triangle(x0, y0, x1, y1, x2, y2, this->getColor());
}
