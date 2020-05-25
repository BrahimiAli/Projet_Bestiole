#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include "Milieu.h"
using namespace std;

class Config {
private:
    static Config* instance;
    Config(string filename);
    Config() : Config(filename){};
public:
    static string filename;
    static const Config* getInstance();
    static void destroyInstance();
    //static void setSupport(Milieu* m){instance->support = m;};

    //Configuration d'Aquarium
    int width;
    int height;
    int _delay; // temps d'attente entre deux steps en ms

    // Nombre initial de bestioles
    int nMax;
     
    // Taille Bestiole 
    int rayon;

    // Configuration population initiale
    double pctGregaire;
    double pctPeureuse;
    double pctKamikaze;
    double pctPrevoyante;
    double pctMulti;

    // Configuration des probabilités
    double probaNouveau;      // probabilité d'ajouter une bestion au cours de la simulation
    double probaMortCol;      // probabilité de mourir lors d'une collision
    double probaChgtMulti;    // probabilité de changer de comportement pour une bestion multi
    double probaClonage;      // probabilité de se cloner
    double probaYeux;         // probabilté d'avoir des yeux
    double probaOreilles;     // probabilité d'avoir des oreilles
    double probaNageoires;    // probabilité d'avoir des nageoires
    double probaCarapace;     // probabilité d'avoir une carapce
    double probaCamouflage;   // probabilité d'avoir camouflage


    // Configuration Vitesse et durée de vie
    double maxVitesse;
    int maxAge;

    //Configuration Yeux
    double alphaMin; // en degrees
    double alphaMax; // en degrees
    double deltaYmin; // distance yeux min
    double deltaYmax; // distance yeux max
    double gammaYmin;
    double gammaYmax;

    //Configuration Oreilles
    double deltaOmin; // distance Oreilles min
    double deltaOmax; // distance Oreilles max
    double gammaOmin;
    double gammaOmax;

    //Configuration Nageoires
    double nuMax;

    //Configuration Carapace
    double omegaMax;
    double etaMax;

    //Configuration Camouflage
    double psiMin;
    double psiMax;

    //Configuaration spécifique Peureuse
    int tempsFuiteMax;
    double coeffVitesse;
    int seuil;  // Nombre de voisins Max
    // 
    //static Milieu* support;

    //Configuration clonage
    double distClonageMin;
    double distClonageMax;

};

#endif
