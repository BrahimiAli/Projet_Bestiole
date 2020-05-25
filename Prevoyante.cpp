//
// Created by user on 09/05/2020.
//

#include "Prevoyante.h"
#include <cmath>

#define PI 3.14159265359


std::tuple<int,int,double,double> Prevoyante::executerStrat(std::list<Bestiole*> voisins, int x, int y, double vitesse, double orientation){
    bool collision = false;
    int prochainX;
    int prochainY;
    double orientationInit = orientation;
    /* On va ici essayer de voir si une collision va se faire pour différentes orientations
     * On commence par tester des orientations séparées de 10 degrés*/
    for(int i=0; i<36; i++) {
        collision = false;
        orientation += i*10.*PI/180.;
        prochainX = x + std::round (vitesse*cos(orientation));
        prochainY = y - std::round (vitesse*sin(orientation));
        for (auto b : voisins) {
            double futureDistance = std::sqrt( (prochainX-b->getX())*(prochainX-b->getX()) + (prochainY-b->getY())*(prochainY-b->getY()) );
            //On regarde si dans cette direction, la distance entre les deux bestioles sera inférieure à 2 fois le rayon
            //Si c'est le cas, il va y avoir une collision, il faut trouver une autre direction
            if(futureDistance <= 2*Config::getInstance()->rayon){
                collision = true;
                break;
            }

        }
        //si l'on n'a pas de collision, on peut garder la direction actuelle;
        if(!collision){
            break;
        }
    }
    //si en sortant de la boucle, on a une collision dans toutes les directions,
    //alors on essaie d'affiner la recherche d'orientation au degré près
    if(collision) {
        for (int i = 0; i < 360; i++) {
            collision = false;
            orientation += i*PI/180.;
            prochainX = x + std::round (vitesse * cos(orientation));
            prochainY = y - std::round (vitesse * sin(orientation));
            for (auto b : voisins) {
                double futureDistance = std::sqrt((prochainX - b->getX()) * (prochainX - b->getX()) +
                                                  (prochainY - b->getY()) * (prochainY - b->getY()));
                //On regarde si dans cette direction, la distance entre les deux bestioles sera inférieure à 2 fois le rayon
                //Si c'est le cas, il va y avoir une collision, il faut trouver une autre direction
                if (futureDistance <= 2 * Config::getInstance()->rayon) {
                    collision = true;
                    break;
                }
            }
            //si l'on n'a pas de collision, on peut garder la direction actuelle;
            if (!collision) {
                break;
            }
        }
        //si en sortant de cette boucle, on a toujours une collision, on peut supposer qu'elle est inévitable
    }

    //si une collision est inévitable, on revient à l'orientation d'origine
    if(collision){
        orientation = orientationInit;
    }
    prochainX = x + std::round (vitesse * cos(orientation));
    prochainY = y - std::round (vitesse * sin(orientation));
    while(orientation>2*PI){
        orientation-=2*PI;
    }
    while(orientation<0){
        orientation+=2*PI;
    }
    return make_tuple(prochainX,prochainY,vitesse,orientation);

}

Prevoyante* Prevoyante::dupliquer() const{
    return new Prevoyante(*this);
}

std::string Prevoyante::getName(){
    return "Prévoyante";
}