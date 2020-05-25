//
// Created by user on 10/05/2020.
//

#include "Peureuse.h"
#include <cmath>
#define PI 3.14159265359

std::tuple<int,int,double,double> Peureuse::executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation){

    //si l'on est pas déjà en fuite, on regarde si le nombre de bestioles voisines est supérieur au seuil
    if(!enFuite){
        if(voisins.size()>((unsigned)Config::getInstance()->seuil)){ // On peut caster en unsigned puisque le seuil est positif
            enFuite = true;
            vitesseInit = vitesse;
            //on multiplie la vitesse si jamais il y a trop de bestioles voisines
            vitesse *= Config::getInstance()->coeffVitesse;
            orientation+=PI;
            tempsEnFuite += 1;
        }
    }
    //si l'on est en fuite, on regarde s'il est temps de s'arrêter ou non
    else{
        tempsEnFuite+=1;
        if(tempsEnFuite>Config::getInstance()->tempsFuiteMax){
            enFuite = false;
            vitesse = vitesseInit;
        }
    }
    x+=std::round (vitesse*cos(orientation));
    y-=std::round (vitesse*sin(orientation));
    while(orientation>2*PI){
        orientation-=2*PI;
    }
    while(orientation<0){
        orientation+=2*PI;
    }
    return make_tuple(x,y,vitesse,orientation);
}

Peureuse* Peureuse::dupliquer() const{
    return new Peureuse(*this);
}

std::string Peureuse::getName(){
    return "Peureuse";
}
