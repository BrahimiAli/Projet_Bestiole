#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "UImg.h"
#include "FabriqueEspeceA.h"
#include <iostream>
#include <map>
#include <list>

using namespace std;

class Color
{
public :
    unsigned char color[3];
    Color(){};
    Color(char r,char g,char b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    };
    Color(const Color& c)
    {
        color[0] = c.color[0];
        color[1] = c.color[1];
        color[2] = c.color[2];
    };
};

class Milieu {
private :
    static const T white[];
    int width, height;
    std::map<int,Bestiole *> bestioles;
    std::vector<Comportement *> listeComportements;
    std::map<Comportement*,Color> mapComportementCouleur;
    std::map<Comportement*, double> mapComportementPct;
    FabriqueEspeceA fabrique = FabriqueEspeceA();
    UImg supportGraphique;
public :
    Milieu(int _width, int _height);
    ~Milieu(void);
    void step(void);
    void nouvelleBestiole();
    void ajouterBestiole(Bestiole *b);
    void tuerBestiole(int id);
    void tuerBestiole(int x, int y);
    void genererRapport(std::ofstream &file);
    std::list<Bestiole *> getListeBestioles();
    UImg& getSupportGraphique();
};
#endif
