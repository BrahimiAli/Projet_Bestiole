//
// Created by ali on 13/05/2020.
//
#include "FabriqueEspeceA.h"
#include <cmath>
#include <utility>

FabriqueEspeceA::FabriqueEspeceA(void)
{
	vitesse = Rand_double(0,Config::getInstance()->maxVitesse);
    maxAge  = Rand_int(1,Config::getInstance()->maxAge); //choix AgeMin = 1
    alpha   = Rand_double(Config::getInstance()->alphaMin*M_PI/180,Config::getInstance()->alphaMax*M_PI/180);
    deltaY  = Rand_double(Config::getInstance()->deltaYmin,Config::getInstance()->deltaYmax);
    gammaY  = Rand_double(Config::getInstance()->gammaYmin,Config::getInstance()->gammaYmax);
    deltaO  = Rand_double(Config::getInstance()->deltaOmin,Config::getInstance()->deltaOmax);
    gammaO  = Rand_double(Config::getInstance()->gammaOmin,Config::getInstance()->gammaOmax);
    nu      = Rand_double(1,Config::getInstance()->nuMax);
    omega   = Rand_double(1,Config::getInstance()->omegaMax);
    eta     = Rand_double(1,Config::getInstance()->etaMax);
    psi     = Rand_double(Config::getInstance()->psiMin,Config::getInstance()->psiMax);
    x       = Rand_int(0,Config::getInstance()->width);
    y       = Rand_int(0,Config::getInstance()->height);
    orientation = Rand_double(0,2*M_PI);
}

EspeceA* FabriqueEspeceA::fabriquerEspeceA(Comportement* c,unsigned char _color[3])
{
    EspeceA* ptr = new BestioleSimple(x(),y(),maxAge(),vitesse(),orientation(),c->dupliquer(),_color);
    Rand_double rd(0,1);
    if(rd()<= Config::getInstance()->probaYeux)
        ptr = new Oeuil(ptr,gammaY(),deltaY(),alpha());
    if(rd()<= Config::getInstance()->probaOreilles)
        ptr = new Oreille(ptr,gammaO(),deltaO());
    if(rd()<= Config::getInstance()->probaNageoires)
        ptr = new Nageoire(ptr,nu());
    if(rd()<= Config::getInstance()->probaCarapace)
        ptr = new Carapace(ptr,omega(),eta());
    if(rd()<= Config::getInstance()->probaCamouflage)
        ptr = new Camouflage(ptr,psi());
    return ptr;
};

/*EspeceA* FabriqueEspeceA::clonerEspeceA(BestioleSimple* b)
{
    EspeceA* ptr = nullptr;
    return ptr;
};*/