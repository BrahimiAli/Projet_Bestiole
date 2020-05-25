#ifndef ESPECEA_H
#define ESPECEA_H

#include "Bestiole.h"
#include "Configuration.h"
#include "Comportement.h"

class EspeceA: public Bestiole{

  public :
    EspeceA(){};
    EspeceA(int _x,int _y, int _ageMax, double _vitesse, double _orientation) ;
    EspeceA(const EspeceA& e);
    virtual ~EspeceA();
    EspeceA(Bestiole& b);
    virtual Bestiole* step(std::list<Bestiole*> toutesBestioles,UImg& support);
    virtual EspeceA* cloner() = 0;
    virtual bool jeTeVois(const Bestiole & autre) const;
    virtual void collisionBestiole(double probaMortCol);
    virtual void collisionBestiole();
    virtual void draw(UImg& support) override;



    //getters
    virtual double getVitesseCoeff() const;
    virtual double getCamouflage() const override;
    virtual double getVitesse() const;
    virtual void getDecorateurs(std::list<std::string> &decorateurs) = 0;
    virtual Comportement* getComportement() const = 0;
    virtual std::tuple<int, std::list<std::string>,int,int,double,double,std::string> getDescription() override;

    // setters
    // Si on n'utilise pas les setteurs, on risque de se retrouver à mettre à jour
    // les attributs du décorateur (qui sont inutiles car ils sont vides ) au lieu des attributs de la base.
    virtual void setX(int newX) override;
    virtual void setY(int newY) override;
    virtual void setVitesse(double newVitesse) override;
    virtual void setOrientation(double newOrientation) override;
    virtual void setAge(int newAge) override;
  protected :
    virtual void collisionMur() override;
    virtual std::list<Bestiole*> trouverVoisins(std::list<Bestiole*> toutesBestioles);

};

#endif
