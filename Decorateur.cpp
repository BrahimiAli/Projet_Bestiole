#include "Decorateur.h"

bool Decorateur::jeTeVois(const Bestiole & autre) const {
  return this->getBase()->jeTeVois(autre);
}

void Decorateur::collisionBestiole()
{
    this->getBase()->collisionBestiole();
}

void Decorateur::setX(int newX) {
  this->getBase()->setX(newX);
}

void Decorateur::setY(int newY) {
  this->getBase()->setY(newY);
}

void Decorateur::setVitesse(double newVitesse) {
  this->getBase()->setVitesse(newVitesse);
}

void Decorateur::setOrientation(double newOrientation) {
  this->getBase()->setOrientation(newOrientation);
}

void Decorateur::setAge(int newAge) {
  this->getBase()->setAge(newAge);
}

void Decorateur::draw(UImg& support) {
  this->getBase()->draw(support);
}

double Decorateur::getVitesse() const {
  return this->getBase()->getVitesse();
}

double Decorateur::getCamouflage() const {
  return this->getBase()->getCamouflage();
}

EspeceA* Decorateur::getBase() const {
  return this->base;
}

unsigned char* Decorateur::getLightColor() const { // Renvoie une couleur entre le blanc/gris et al couleur de la bestiole
  unsigned char * col = (unsigned char*) this->color;
  col[0] = 3*col[0]/5 + 60;
  col[1] = 3*col[1]/5 + 60;
  col[2] = 3*col[2]/5 + 60;
  return col;
}

unsigned char * Decorateur::getColor() const {
  return this->getBase()->getColor();
}


Decorateur::~Decorateur() {
    delete base;
}


Comportement* Decorateur::getComportement() const
{
    return this->getBase()->getComportement();
}

std::string Decorateur::getName(){
    return this->name;
}

void Decorateur::getDecorateurs(std::list<std::string> &decorateurs){
    decorateurs.push_back(this->getName());
    this->getBase()->getDecorateurs(decorateurs);
}

int Decorateur::getIdentite() const {
  return this->getBase()->getIdentite();
}

int Decorateur::getX() const {
  return this->getBase()->getX();
}

int Decorateur::getY() const {
  return this->getBase()->getY();
}

double Decorateur::getOrientation() const {
  return this->getBase()->getOrientation();
}

int Decorateur::getAgeMax() const {
  return this->getBase()->getAgeMax();
}

int Decorateur::getAge() const {
  return this->getBase()->getAge();
}
