#include "Oeuil.h"

Oeuil::Oeuil(EspeceA* base, double detec, double dist, double angle) {
  this->name = "Oeil";
  this->base = base;
  this->capaciteDetection = detec;
  this->angle = angle;
  this->distance = dist;
}


bool Oeuil::jeTeVois(const Bestiole & autre) const {
  bool jeVois = autre.getCamouflage() < this->capaciteDetection;
  bool distanceOk = this->plusProcheQue(autre, this->distance);
  bool dansArc = this->dansArcVue(autre, this->angle);
  return ( (jeVois && distanceOk && dansArc) || this->getBase()->jeTeVois(autre));
}

EspeceA* Oeuil::cloner()
{
    EspeceA* ptr = new Oeuil(this->getBase()->cloner(),this->capaciteDetection,this->distance,this->angle);
    return ptr;
}

void Oeuil::draw(UImg& support) {
  double angleMin = this->getOrientation() - this->angle/2;
  double angleMax = this->getOrientation() + this->angle/2;
  int x0 = this->getX() + this->distance * cos(angleMin);
  int y0 = this->getY() - this->distance * sin(angleMin);
  int x1 = this->getX() + this->distance * cos(angleMax);
  int y1 = this->getY() - this->distance * sin(angleMax);
  support.draw_line(this->getX(), this->getY(), x0, y0, this->getColor());
  support.draw_line(this->getX(), this->getY(), x1, y1, this->getColor()); // Dessine deux lignes représentant le cone de vision
  this->getBase()->draw(support);
}
