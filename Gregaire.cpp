//
// Created by user on 06/05/2020.
//

#include "Gregaire.h"
#include <cmath>
#include <array>
#define PI 3.14159265359

std::tuple<int, int,double,double> Gregaire::executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation){
    double orientMoyenne;
    //calcul de l'orientation moyenne des bestioles voisines
    if(voisins.size()!=0) {
        orientMoyenne = 0;
        for (auto b : voisins) {
            orientMoyenne += b->getOrientation();
        }
        orientMoyenne /= voisins.size();
    }
    //si l'on a détecté aucune autre bestiole, l'orientation reste la même
    else{
        orientMoyenne = orientation;
    }
    //calcul de na nouvelle position
    x+=std::round(vitesse*cos(orientMoyenne));
    y-=std::round(vitesse*sin(orientMoyenne));
    while(orientMoyenne>2*PI){
        orientMoyenne-=2*PI;
    }
    while(orientMoyenne>2*PI){
        orientMoyenne-=2*PI;
    }
    while(orientMoyenne<0){
        orientMoyenne+=2*PI;
    }
    return std::make_tuple(x, y, vitesse, orientMoyenne);

}

Gregaire* Gregaire::dupliquer() const{
    return new Gregaire(*this);
}

std::string Gregaire::getName(){
    return "Grégaire";
}