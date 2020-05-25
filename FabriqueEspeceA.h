//
// Created by ali on 13/05/2020.
//
#ifndef BESTIOLES_GR3_FABRIQUEESPECEA_H
#define BESTIOLES_GR3_FABRIQUEESPECEA_H

#include "Configuration.h"
#include "FabriqueBestiole.h"
#include "Comportement.h"
#include "Multiple.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "EspeceA.h"
#include "BestioleSimple.h"
#include "Oreille.h"
#include "Oeuil.h" //Oeil
#include "Nageoire.h"
#include "Carapace.h"
#include "Camouflage.h"
#include "RandomUtils.h"



class FabriqueEspeceA : public FabriqueBestiole{
private :
    std::vector<Comportement*> listComportement;
    std::vector<double> weight;
    //random generators
    Rand_double vitesse;
    Rand_int    maxAge;
    Rand_double alpha;
    Rand_double deltaY;
    Rand_double gammaY;
    Rand_double deltaO;
    Rand_double gammaO;
    Rand_double nu;
    Rand_double omega;
    Rand_double eta;
    Rand_double psi;
    Rand_int x;
    Rand_int y;
    Rand_double orientation;

public :
    FabriqueEspeceA();
    EspeceA* fabriquerEspeceA(Comportement* c,unsigned char _color[3]);
    //EspeceA* clonerEspeceA(BestioleSimple* b);
};
#endif
