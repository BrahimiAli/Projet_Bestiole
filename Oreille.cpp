#include "Oreille.h"

Oreille::Oreille(EspeceA* base, double detec, double dist) {
  this->name = "Oreille";
  this->base = base;
  this->capaciteDetection = detec;
  this->angle = 0;
  this->distance = dist;
}


bool Oreille::jeTeVois(const Bestiole & autre) const {
  bool jeVois = autre.getCamouflage() < this->capaciteDetection;
  bool distanceOk = this->plusProcheQue(autre, this->distance);
  return ( (jeVois && distanceOk) || this->getBase()->jeTeVois(autre));
}

EspeceA* Oreille::cloner() {
  return new Oreille(this->getBase()->cloner(), this->capaciteDetection, this->distance);
}

void Oreille::draw(UImg& support) {
  support.draw_circle(this->getX(),this->getY(),this->distance,this->getColor(), 1.0f, 0xFFFFFFFF); // Dessine un cerle représentant le rayon d'écoute de la bestiole
  this->getBase()->draw(support);
}
