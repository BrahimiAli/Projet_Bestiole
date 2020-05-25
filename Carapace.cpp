#include "Carapace.h"

Carapace::Carapace(EspeceA* base, double collision, double vitesse) {
  this->name = "Carapace";
  this->base = base;
  this->coefVitesse = vitesse;
  this->coefCollision = collision;
}

double Carapace::getVitesse() const {
  return 1/this->coefVitesse * this->getBase()->getVitesse();
}

void Carapace::collisionBestiole() {
  this->getBase()->collisionBestiole(Config::getInstance()->probaMortCol/coefCollision);
}

EspeceA* Carapace::cloner() {
  return new Carapace(this->getBase()->cloner(), this->coefCollision, this->coefVitesse);
}


double Carapace::getVitesseCoeff() const {
  return this->coefVitesse;
}

void Carapace::draw(UImg& support) {
  this->getBase()->draw(support);
  unsigned char col[3];
  col[0] = 0;
  col[1] = 0;
  col[2] = 0;
  // col represente du noir
  support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon + 1, col, 1.0f, 0xFFFFFFFF);
  support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon + 2, col, 1.0f, 0xFFFFFFFF);
  support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon + 3, col, 1.0f, 0xFFFFFFFF); // Dessine un cercle noir autour de la besitole

}
