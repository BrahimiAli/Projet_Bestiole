//
// Created by user on 07/05/2020.
//

#include "Kamikaze.h"
#include <cmath>
#define BIG_NUMBER 9999999.

std::tuple<int,int,double,double> Kamikaze::executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation){
    double distanceMin = BIG_NUMBER;
    int xCible;
    int yCible;
    //on calcul le voisin le plus proche
    for (auto b : voisins){
        double distance = std::sqrt( (x-b->getX())*(x-b->getX()) + (y-b->getY())*(y-b->getY()) );
        if(distance<distanceMin){
            distanceMin = distance;
            xCible=b->getX();
            yCible=b->getY();
        }
    }
    //on vise ensuite la cible
    if(voisins.size()!=0) {
        xCible -= x;
        yCible -= y;
        orientation = -atan2(yCible, xCible);
    }
    //on avance vers la bestiole la plus proche
    x+=std::round (vitesse*cos(orientation));
    y-=std::round (vitesse*sin(orientation));
    return make_tuple(x,y,vitesse,orientation);
}

Kamikaze* Kamikaze::dupliquer() const{
    return new Kamikaze(*this);
}

std::string Kamikaze::getName(){
    return "Kamikaze";
}