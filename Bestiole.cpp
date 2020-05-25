#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include "RandomUtils.h"

int Bestiole::next = 0;

Bestiole::Bestiole(int _x,int _y, int _ageMax, double _vitesse, double _orientation)
{
    this->identite = ++next;
    this->age    = 0;
    this->ageMax = _ageMax;
    this->x = _x;
    this->y = _y;
    this->orientation = _orientation;
    this->vitesse = _vitesse;
}

double Bestiole::getDistanceA(const Bestiole* b) const
{
    return sqrt((this->getX()-b->getX())*(this->getX()-b->getX())+(this->getY()-b->getY())*(this->getY()-b->getY()));
}


Bestiole::Bestiole(const Bestiole & b)
{
    this->identite = ++next;
    this->ageMax = b.getAgeMax();
    this->age = b.getAge();
    this->x = b.getX();
    this->y = b.getY();
    this->orientation = b.getOrientation();
    this->vitesse = b.getVitesse();
}


Bestiole::~Bestiole( void )
{
    ///
}


void Bestiole::setColor(unsigned char* _color)
{
    for(int i=0;i<3;++i)
        this->color[i] = _color[i];
}

int Bestiole::getIdentite() const {
  return this->identite;
}
int Bestiole::getX() const {
  return this->x;
}
int Bestiole::getY() const {
  return this->y;
}
double Bestiole::getOrientation() const {
  return this->orientation;
}

int Bestiole::getAgeMax() const {
  return this->ageMax;
}
int Bestiole::getAge() const {
  return this->age;
}
unsigned char* Bestiole::getColor() const {
  return (unsigned char*) this->color;
}

bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.getIdentite() == b2.getIdentite() );

}

double Bestiole::getVitesse() const {
  return this->vitesse;
}

double Bestiole::getCamouflage() const {
  return 0.0;
}

bool Bestiole::plusProcheQue(const Bestiole & b, double distance) const {
  double dist;
  dist = b.getDistanceA(this);
  return ( dist <= distance );
}

double between0and2PI(double angle)
{

    double PI = 3.14159265358979323844;
    while (angle > 2.0*PI)
        angle -= 2.0*PI;
    while (angle < 0)
        angle += 2.0*PI;
    return angle;
}

bool Bestiole::dansArcVue(const Bestiole & b, double variance) const {
    double precision = 0.0001;
    double angle = between0and2PI(-atan2(b.getY()-this->getY(),b.getX()-this->getX()));
    double end = between0and2PI(this->getOrientation()+variance/2);
    double start = between0and2PI(this->getOrientation()-variance/2);
    if(std::abs(start - end) < precision)
        return false;
    if((end >= angle)&&(angle>=start))
        return true;
    if((end <= angle) && (angle <= start)) {
      return true;
    }
    return false;
}
