#include "Configuration.h"
string Config::filename = "base.cfg";
//Milieu* Config::support = nullptr;
Config::Config(string filename) {
        ifstream fin;
        fin.open(filename);
        string line;
        while (getline(fin, line)) {
            istringstream sin(line.substr(line.find("=") + 1));

            if (line.find("width") != string::npos)
                sin >> width;
            if (line.find("height") != string::npos)
                sin >> height;
            if (line.find("_delay") != string::npos)
                sin >> _delay;

            if (line.find("nMax") != string::npos)
                sin >> nMax;

            if (line.find("rayon") != string::npos)
                sin >> rayon;

                // pct
            else if (line.find("pctGregaire") != string::npos)
                sin >> pctGregaire;
            else if (line.find("pctKamikaze") != string::npos)
                sin >> pctKamikaze;
            else if (line.find("pctPrevoyante") != string::npos)
                sin >> pctPrevoyante;
            else if (line.find("pctPeureuse") != string::npos)
                sin >> pctPeureuse;
            else if (line.find("pctMulti") != string::npos)
                sin >> pctMulti;

                //proba
            else if (line.find("probaChgtMulti") != string::npos)
                sin >> probaChgtMulti;
            else if (line.find("probaCamouflage") != string::npos)
                sin >> probaCamouflage;
            else if (line.find("probaClonage") != string::npos)
                sin >> probaClonage;
            else if (line.find("probaMortCol") != string::npos)
                sin >> probaMortCol;
            else if (line.find("probaOreilles") != string::npos)
                sin >> probaOreilles;
            else if (line.find("probaYeux") != string::npos)
                sin >> probaYeux;
            else if (line.find("probaNageoires") != string::npos)
                sin >> probaNageoires;
            else if (line.find("probaCarapace") != string::npos)
                sin >> probaCarapace;
            else if (line.find("probaNouveau") != string::npos)
                sin >> probaNouveau;


                // age/vitesse
            else if (line.find("maxAge") != string::npos)
                sin >> maxAge;
            else if (line.find("maxVitesse") != string::npos)
                sin >> maxVitesse;

                // Yeux
            else if (line.find("alphaMax") != string::npos)
                sin >> alphaMax;
            else if (line.find("alphaMin") != string::npos)
                sin >> alphaMin;
            else if (line.find("deltaYmin") != string::npos)
                sin >> deltaYmin;
            else if (line.find("deltaYmax") != string::npos)
                sin >> deltaYmax;
            else if (line.find("gammaYmin") != string::npos)
                sin >> gammaYmin;
            else if (line.find("gammaYmax") != string::npos)
                sin >> gammaYmax;

                // Oreilles
            else if (line.find("deltaOmin") != string::npos)
                sin >> deltaOmin;
            else if (line.find("deltaOmax") != string::npos)
                sin >> deltaOmax;
            else if (line.find("gammaOmin") != string::npos)
                sin >> gammaOmin;
            else if (line.find("gammaOmax") != string::npos)
                sin >> gammaOmax;

                // Nageoires
            else if (line.find("nuMax") != string::npos)
                sin >> nuMax;

                //Carapace
            else if (line.find("omegaMax") != string::npos)
                sin >> omegaMax;
            else if (line.find("etaMax") != string::npos)
                sin >> etaMax;

                //Camouflage
            else if (line.find("psiMin") != string::npos)
                sin >> psiMin;
            else if (line.find("psiMax") != string::npos)
                sin >> psiMax;

                //Configuaration spécifique Peureuse
            else if (line.find("tempsFuiteMax") != string::npos)
                sin >> tempsFuiteMax;
            else if (line.find("coeffVitesse") != string::npos)
                sin >> coeffVitesse;
            else if (line.find("seuil") != string::npos)
                sin >> seuil;

                //Configuration clonage
            else if (line.find("distClonageMin") != string::npos)
                sin >> distClonageMin;
            else if (line.find("distClonageMax") != string::npos)
                sin >> distClonageMax;
        }
    };

Config* Config::instance = nullptr;

const Config* Config::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Config();
    }

    return instance;
};

void Config::destroyInstance() {
    // Pour détruire le pointeur static instance
    delete instance;
    instance = nullptr;
};
