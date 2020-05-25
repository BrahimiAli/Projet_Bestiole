//
// Created by user on 10/05/2020.
//
#include "Multiple.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include <stdlib.h>

Multiple::Multiple(){
    //à la construction, on choisit un comportement de façon aléatoire
    int comportementAlea = Rand_int(1,nbComportementsPossibles-1)();
    switch(comportementAlea){
        case ComportementsPossibles::gregaire:
            comportement = new Gregaire;
            break;
        case ComportementsPossibles::peureuse:
            comportement = new Peureuse;
            break;
        case ComportementsPossibles::prevoyante:
            comportement = new Prevoyante;
            break;
        case ComportementsPossibles::kamikaze:
            comportement = new Kamikaze;
            break;

    }
}

Multiple::Multiple(const Multiple& m){
    this->comportement = m.comportement->dupliquer();
}

Multiple::~Multiple(){
    delete this->comportement;
}

std::tuple<int,int,double,double> Multiple::executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation){
    double testChange = Rand_double(0,1)();
    //avant d'exécuter le comportement, on regarde si l'on en change ou non
    if(testChange<=Config::getInstance()->probaChgtMulti){
        int comportementAlea = Rand_int(0,nbComportementsPossibles-1)();
        switch(comportementAlea){
            case ComportementsPossibles::gregaire:
                delete comportement;
                comportement = new Gregaire;
                break;
            case ComportementsPossibles::peureuse:
                delete comportement;
                comportement = new Peureuse;
                break;
            case ComportementsPossibles::prevoyante:
                delete comportement;
                comportement = new Prevoyante;
                break;
            case ComportementsPossibles::kamikaze:
                delete comportement;
                comportement = new Kamikaze;
                break;

        }
    }
    //on va exécuter la stratégie du comportement actuel
    return comportement->executerStrat(voisins,x,y,vitesse,orientation);
}

Multiple* Multiple::dupliquer() const{
    return new Multiple(*this);
}

std::string Multiple::getName(){
    return "Multiple";
}