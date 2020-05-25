#include "EspeceA.h"
#include <iostream>
#include <tuple>
#include "RandomUtils.h"

#define PI 3.14159265359

EspeceA::EspeceA(int _x,int _y, int _ageMax, double _vitesse, double _orientation) : Bestiole(_x,_y,_ageMax,_vitesse,_orientation){}

EspeceA::EspeceA(const EspeceA& e)  : Bestiole(e) {

}

EspeceA::EspeceA(Bestiole& b) {

}

EspeceA::~EspeceA() {

}

//getters
double EspeceA::getVitesseCoeff() const { // Utile pour mettre a jour la vitesse en prenant en compte les décorateurs
  return 1;
}

double EspeceA::getCamouflage() const {
    return 0.0;
}

double EspeceA::getVitesse() const {
    return this->vitesse;
}

//setters
void EspeceA::setX(int newX) {
    this->x = newX;
}
void EspeceA::setY(int newY) {
    this->y = newY;
}
void EspeceA::setVitesse(double newVitesse) {
    this->vitesse = newVitesse;
}
void EspeceA::setOrientation(double newOrientation) {
    this->orientation = newOrientation;
}
void EspeceA::setAge(int newAge) {
    this->age = newAge;
}

//fonction chargée de mettre à jour toutes les caractéristiques de la bestiole
Bestiole* EspeceA::step(std::list<Bestiole*> toutesBestioles,UImg& support) {
    //on trouve d'abord toutes les bestioles que l'on peut détecter
  std::list<Bestiole*> voisins = trouverVoisins(toutesBestioles);
  std::cout<< "ID = " << this->getIdentite() <<  ",AGE = " << this->getAge()  << ",X = " << this->getX() << ", Y = " << this->getY() << ", V = " << this->getVitesse() << ", O = " << this->getOrientation() << std::endl;

  //on appelle le comportement qui renvoit les nouvelles positions, vitesses et orientations calculées
  auto resultComportement = this->getComportement()->executerStrat(voisins,this->getX(),this->getY(),this->getVitesse(),this->getOrientation());
  this->setX(std::get<0>(resultComportement));
  this->setY(std::get<1>(resultComportement));
  this->setOrientation(std::get<3>(resultComportement));
  this->setAge(this->getAge()+1);

  //on prend en compte les collisions avec les murs
  this->collisionMur();

  //on parcourt toutes les bestioles pour vérifier si l'on est rentré en collision ou non
  for(auto b: toutesBestioles)
  {
      if(b->getIdentite()!=this->getIdentite() && this->getDistanceA(b)<2*Config::getInstance()->rayon)
      {
          this->collisionBestiole();
          //on appelle aussi la fonction de collision de l'autre bestiole
          b->collisionBestiole();
      }
  }

  //on vérifie si l'on peut se cloner
  if(this->getAge()<this->getAgeMax()){
      this->draw(support);
      Rand_double testClonage = Rand_double(0,1);
      if(testClonage()<=Config::getInstance()->probaClonage)
      {
          //si on peut se cloner, on renvoit le pointeur de la nouvelle bestiole pour que le milieu en prenne connaissance
          return this->cloner();
      }
      else
      {
          //sinon, on renvoit nullptr
          return nullptr;
      }
  }
  else
  {
      return nullptr;
  }
}



//méthode qui gère les collisions avec les murs
void EspeceA::collisionMur()
{
    if( this->getX()<0  || this->getX()>Config::getInstance()->width)
    {
        this->setOrientation(PI - this->getOrientation());
        if(this->getX()<0)
        {
            this->setX(-this->getX());
        }
        else
        {
            this->setX(2*Config::getInstance()->width-getX());
        }
    }
    else if(this->getY()<0 || this->getY()>Config::getInstance()->height)
    {
        this->setOrientation( - this->getOrientation());
        if(this->getY()<0)
        {
            this->setY(-this->getY());
        }
        else
        {
            this->setY(2*Config::getInstance()->height-this->getY());
        }
    }
    while(this->getOrientation()>2*PI){
        this->setOrientation(this->getOrientation()-2*PI);
    }
    while(this->getOrientation()<0){
        this->setOrientation(this->getOrientation()+2*PI);
    }
}

//méthode qui gère les collisions avec le bestioles
//on passe en paramère la probabilité de mourir d'une collision
void EspeceA::collisionBestiole(double probaMortCol)
{
    double testMort = Rand_double(0,1)();
    if(testMort<=probaMortCol)
    {
        //pour tuer la bestiole, on met son âge au maximum
        this->setAge(Config::getInstance()->maxAge);
    }
    else
    {
        //si la collision ne tue pas, on repart dans une direction aléatoire
        this->setOrientation(Rand_double(0,2*PI)());
    }
}

//probabilite de mort par défaut
void EspeceA::collisionBestiole(){
    return this->collisionBestiole(Config::getInstance()->probaMortCol);
}


//renvoit true si l'on peut voir la bestiole
//Par défaut, sans capteur, on renvoit false
bool EspeceA::jeTeVois(const Bestiole & autre) const {
    return false;
}

//renvoit la liste de toutes les bestioles détectées
std::list<Bestiole*> EspeceA::trouverVoisins(std::list<Bestiole*> toutesBestioles)
{
    std::list<Bestiole*> voisins;
    for (auto b : toutesBestioles)
    {
       if(this->getIdentite()!=b->getIdentite() && this->jeTeVois(*b))
        {
            voisins.push_back(b);
        }
    }
    return voisins;
}

//dessin de la bestiole
void EspeceA::draw(UImg& support) {
  double xt = (double) this->getX() + cos(this->getOrientation())*Config::getInstance()->rayon/2;
  double yt = (double) this->getY() - sin(this->getOrientation())*Config::getInstance()->rayon/2;
  support.draw_ellipse(this->getX(),this->getY(), Config::getInstance()->rayon*2, Config::getInstance()->rayon/2.5,-this->getOrientation()/M_PI*180.,this->getColor());
  support.draw_circle(xt,yt,Config::getInstance()->rayon,getColor());
}

//renvoie des informations utiles à la création d'un rapport
std::tuple<int, std::list<std::string>,int,int,double,double,std::string> EspeceA::getDescription(){
    std::list<std::string> decorateurs;
    getDecorateurs(decorateurs);
    return make_tuple(this->getIdentite(),decorateurs,this->getX(),this->getY(),this->getVitesse(),this->getOrientation(),this->getComportement()->getName());
}
