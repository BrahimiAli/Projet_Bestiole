//
// Created by user on 10/05/2020.
//

#include "BestioleSimple.h"
#include "RandomUtils.h"
#define PI 3.14159265359

BestioleSimple::BestioleSimple(int _x,int _y, int _ageMax, double _vitesse, double _orientation,Comportement* c, unsigned char* _color) : EspeceA(_x,_y,_ageMax,_vitesse,_orientation)
{
    this->comportement = c;
    this->setColor(_color);
}

BestioleSimple::BestioleSimple(const BestioleSimple& b) : EspeceA(b)
{
    this->comportement = b.getComportement()->dupliquer();
    this->setColor(b.getColor());
}

BestioleSimple::~BestioleSimple(){
    delete this->comportement;
}
 //une bestiole simple n'a pas moyen de voir une autre bestiole, donc on renvoit false
bool BestioleSimple::jeTeVois(const Bestiole& b) const {
    return false;
}

Comportement* BestioleSimple::getComportement() const{
    return this->comportement;
}

EspeceA* BestioleSimple::cloner()
{
    EspeceA* ptr = new BestioleSimple(*this);
    double newOrientation= Rand_double(0,2*PI)();
    double distance = Rand_double(Config::getInstance()->distClonageMin,Config::getInstance()->distClonageMax)();
    ptr->setX(ptr->getX() + std::round (cos(newOrientation)*distance));
    ptr->setY(ptr->getY() - std::round (sin(newOrientation)*distance));
    return ptr;
}

void BestioleSimple::draw(UImg& support){
    double xt = (double) this->getX() - cos(this->getOrientation())*Config::getInstance()->rayon/2;
    double yt = (double) this->getY() + sin(this->getOrientation())*Config::getInstance()->rayon/2;
    support.draw_ellipse(xt, yt, Config::getInstance()->rayon*2, Config::getInstance()->rayon/2.5,-this->getOrientation()/M_PI*180.,this->getColor());
    support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon,getColor());
}

double BestioleSimple::getCamouflage() const {
    return 0;
}

//une fois arrivé à BestioleSimple, on a parcouru tous les décorateurs, on ne rajoute donc rien à la liste
void BestioleSimple::getDecorateurs(std::list<std::string> &decorateurs){
    return;
}