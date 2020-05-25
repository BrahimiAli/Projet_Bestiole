//
// Created by user on 10/05/2020.
//

#ifndef BESTIOLES_GR3_BESTIOLESIMPLE_H
#define BESTIOLES_GR3_BESTIOLESIMPLE_H

#include "EspeceA.h"
#include "Comportement.h"

class BestioleSimple: public EspeceA {
    Comportement *comportement;
public:
    BestioleSimple(){};
    BestioleSimple(int _x,int _y, int _ageMax, double _vitesse, double _orientation,Comportement* c, unsigned char* _color);
    virtual ~BestioleSimple();
    BestioleSimple(const BestioleSimple& b);
    bool jeTeVois(const Bestiole&) const override;
    EspeceA* cloner() override;

    Comportement* getComportement() const override;
    double getCamouflage() const override;
    void draw(UImg& support) override;
    virtual void getDecorateurs(std::list<std::string> &decorateurs) override;


};


#endif //BESTIOLES_GR3_BESTIOLESIMPLE_H
