#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"
#include <iostream>
#include <list>
#include <tuple>

//
// Trois méthodes doivent êtres implémentées par toutes
// les espèces de bestioles : collisionMur()
//                            collisionBestiolle()
// Bestiole* step(std::list<Bestiole*> toutesBestioles) : Méthode Publique qui gère entièrement une étape de la simulation (gestion de
// fin de vie laisser à Milieu.step())
// du point de vue de la bestiole | Pq Bestiole* et non void ? Cas clonage la bestiole renvoie son clone à la fin de l'étape
// Pourquoi ne pas passer Milieu* au lieu d'une liste et laisser bestiole.step() appeler la méthode Milieu.ajouterBestiole(Bestiole*) si la bestiole veut se cloner
// + permet de ne pas stocker un ptr sur Milieu dans Config (car Milieu = support dans draw )
//
class Bestiole
{

protected :
    static int next;
    int identite;
    int age;
    int ageMax;
    int  x, y;
    double orientation;
    double vitesse;
    unsigned char color[3] = {0,0,0}; // Couleur Par défaut : Noir
    virtual void collisionMur()=0;
    Bestiole(){};
public :
    // Forme canonique :
    Bestiole(int _x,int _y, int _ageMax, double _vitesse, double _orientation);
    Bestiole(const Bestiole &b);                 // Constructeur de copies
    virtual ~Bestiole(void);                      // Destructeur
    double getDistanceA(const Bestiole* b) const;
    virtual void collisionBestiole() = 0;
    //virtual string toString() = 0; // permet de renvoyer l'identite & comportement & liste des accessoires
    // getter
    virtual int getIdentite() const;
    virtual int getX() const;
    virtual int getY() const;
    virtual double getOrientation() const;
    virtual double getVitesse() const;
    virtual int getAgeMax() const;
    virtual int getAge() const;
    virtual void setX(int newX) = 0;
    virtual void setY(int newY) = 0;
    virtual void setVitesse(double newVitesse) = 0;
    virtual void setOrientation(double newOrientation) = 0;
    virtual void setAge(int newAge) = 0;
    virtual unsigned char* getColor() const;
    virtual void setColor(unsigned char* _color);
    virtual Bestiole* step(std::list<Bestiole*> toutesBestioles,UImg& support) = 0;
    virtual void draw(UImg& support) = 0;
    friend bool operator==(const Bestiole& b1, const Bestiole& b2);
    virtual std::tuple<int,std::list<std::string>,int,int,double,double,std::string> getDescription() = 0;

    virtual double getCamouflage() const;

    bool plusProcheQue(const Bestiole & b, double rayon) const;

    bool dansArcVue(const Bestiole & b, double variance) const;
};


#endif
