#include "Milieu.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

const T Milieu::white[] = {(T)255, (T)255, (T)255};


Milieu::Milieu( int _width, int _height ) : width(_width), height(_height)
{
    // On commence par créer une liste de couleurs (une par comportement) et la partie graphique de milieu
    supportGraphique = UImg( width, height, 1, 3 );
    Color purple  = Color(255,0,255);
    Color red    = Color(255,0,0);
    Color green  = Color(0,255,0);
    Color blue   = Color(0,0,255);
    Color yellow = Color(255,255,0);
    // Initialisation des comportements
    listeComportements = {new Gregaire,new Kamikaze, new Peureuse,new Prevoyante,new Multiple};
    // Chargmeent des pourcentages par Comportment
    std::vector<double> listeWeights = {Config::getInstance()->pctGregaire,Config::getInstance()->pctKamikaze,Config::getInstance()->pctPeureuse,Config::getInstance()->pctPrevoyante,Config::getInstance()->pctMulti};
    // On stocke les couleurs dans une liste
    std::vector<Color> couleurs = {blue,red,yellow,green,purple};
    for(unsigned int i=0;i<listeComportements.size();++i)
    {
        mapComportementCouleur[listeComportements[i]] = couleurs[i];
        mapComportementPct[listeComportements[i]] = listeWeights[i];
    }

    // initialisation de la population :
    int n = Config::getInstance()->nMax;
    // On utilise utils_init pour créer une liste de n comportements qui respecte les poids
    std::vector<Comportement*> _population = utils_init(listeComportements,listeWeights,n);
    for (auto element : _population)
    {
        Color _color = mapComportementCouleur[element];
        ajouterBestiole(fabrique.fabriquerEspeceA(element,_color.color));
    }
}

void Milieu::genererRapport(std::ofstream &file)
{
    int nbPeureuses=0;
    int nbGregaires=0;
    int nbKamikazes=0;
    int nbPrevoyantes=0;
    int nbMultiples=0;
    int nbYeux=0;
    int nbOreilles=0;
    int nbCarapaces=0;
    int nbCamouflages=0;
    int nbNageoires=0;
    double vitesseMoyenne=0;
    std::list<Bestiole*> listeBestioles = getListeBestioles();
    for(auto bestiole : listeBestioles) {
        auto tupleDescription = bestiole->getDescription();
        file<<"ID = "<<std::get<0>(tupleDescription)<<" X = "<<std::get<2>(tupleDescription)<<" Y = "<<std::get<3>(tupleDescription)
                <<" Vitesse = "<<std::get<4>(tupleDescription)<<" Orientation = "<<std::get<5>(tupleDescription)<<" Comportement = "
                <<std::get<6>(tupleDescription)<< std::endl;
        if(std::get<1>(tupleDescription).size()>0) {
            file << "   Décorateurs : " << std::endl;
        }
        for(auto deco:std::get<1>(tupleDescription)){
            file<<"     -"<<deco<<std::endl;
            //décompte décorateurs
            if(deco=="Oeil"){
                nbYeux+=1;
            }
            else if(deco=="Oreille"){
                nbOreilles+=1;
            }
            else if(deco=="Carapace"){
                nbCarapaces+=1;
            }
            else if(deco=="Camouflage"){
                nbCamouflages+=1;
            }
            else if(deco=="Nageoire"){
                nbNageoires+=1;
            }
        }
        if(std::get<6>(tupleDescription)=="Grégaire"){
            nbGregaires+=1;
        }
        else if(std::get<6>(tupleDescription)=="Kamikaze"){
            nbKamikazes+=1;
        }
        else if(std::get<6>(tupleDescription)=="Peureuse"){
            nbPeureuses+=1;
        }
        else if(std::get<6>(tupleDescription)=="Prévoyante"){
            nbPrevoyantes+=1;
        }
        else if(std::get<6>(tupleDescription)=="Multiple"){
            nbMultiples+=1;
        }
        vitesseMoyenne+=std::get<4>(tupleDescription);
        file<<std::endl;
    }
    vitesseMoyenne/=listeBestioles.size();
    file << "#########################################################################################################################" << std::endl;
    file<<"MOYENNES"<<std::endl;
    file << "Vitesse moyenne des bestioles : " << vitesseMoyenne << std::endl;
    file << "#########################################################################################################################" << std::endl;
    file<<"TOTAUX"<<std::endl;
    file << "Nombre total de bestioles : " << listeBestioles.size() << std::endl;
    file<<"Comportements : "<<std::endl;
    file << "-Nombre de bestioles grégaires : " <<nbGregaires<<std::endl;
    file << "-Nombre de bestioles kamikazes : " <<nbKamikazes<<std::endl;
    file << "-Nombre de bestioles peureuses : " <<nbPeureuses<<std::endl;
    file << "-Nombre de bestioles prévoyantes : " <<nbPrevoyantes<<std::endl;
    file << "-Nombre de bestioles multiples : " <<nbMultiples<<std::endl;
    file<<"Décorateurs : "<<std::endl;
    file << "-Nombre de bestioles avec des yeux : " <<nbYeux<<std::endl;
    file << "-Nombre de bestioles avec des oreilles : " <<nbOreilles<<std::endl;
    file << "-Nombre de bestioles avec du camouflage : " <<nbCamouflages<<std::endl;
    file << "-Nombre de bestioles avec une carapace : " <<nbCarapaces<<std::endl;
    file << "-Nombre de bestioles avec des nageoires : " <<nbNageoires<<std::endl;
    file.close();
};
CImg<T>& Milieu::getSupportGraphique()
{
    return supportGraphique;
}

Milieu::~Milieu(void)
{
    for (auto it = bestioles.begin(); it != bestioles.end();)
    {
        std::cout << "La bestiole n°" << it->second->getIdentite() << " age " << it->second->getAge() << '/' << it->second->getAgeMax() << " va être supprimée " << std::endl;
        delete it->second;
        bestioles.erase(it++);
    }

    for(auto e : listeComportements)
       delete e;
    listeComportements.clear();
    mapComportementPct.clear();
    mapComportementCouleur.clear();
    std::cout << "Liste des comportements a été supprimée " << std::endl;
}

std::list<Bestiole*> Milieu::getListeBestioles()
{
    //
    std::list<Bestiole*> _listeBestioles;
    // Mise à jour de la MAP et _listeBestioles
    for (auto it = bestioles.begin(); it != bestioles.end();)
    {
        if(it->second->getAge() >= it->second->getAgeMax())
        {
            delete it->second;
            bestioles.erase(it++);
        }
        else
        {
            _listeBestioles.push_back(it->second);
            (++it);
        }
    }

    return _listeBestioles;

}

void Milieu::step(void)
{
    // On commence par tester si on doit ajouter une bestiole
    nouvelleBestiole();
    // Puis on tue les bestioles qui ont "expiré"
    cimg_forXY(supportGraphique,width,height) supportGraphique.fillC(width,height,0,white[0],white[1],white[2]);
    list<Bestiole*> listeBestioles = getListeBestioles();
    list<Bestiole*> _listeBestioles = listeBestioles; // une copie pour y ajouter les clones
    for(auto bestiole : listeBestioles)
    {
        Bestiole* b = bestiole->step(_listeBestioles,supportGraphique);
        // Si bestiole B a "décidé" de se cloner
        if(b != nullptr)
        {
            //On ajoute le clone dans le dico et dans la copie _listeBestioles
            ajouterBestiole(b);
            _listeBestioles.push_back(b);
            // puis on demande à b d'effectuer son step
            b->step(_listeBestioles,supportGraphique);
        }
    }
    cout << endl;
}
void Milieu::nouvelleBestiole(void)
{
   Rand_double rd(0,1);
   if(rd() <= Config::Config::getInstance()->probaNouveau)
   {
       std::vector<double> listeWeights;
       std::vector<Comportement*> _listeComportements;
       for(auto element : mapComportementPct)
       {
           listeWeights.push_back(element.second);
           _listeComportements.push_back(element.first);
       }
       Comportement* c = random_weighted(_listeComportements,listeWeights);
       Color _color = mapComportementCouleur[c];
       ajouterBestiole(fabrique.fabriquerEspeceA(c,_color.color));
   }
}
void Milieu::ajouterBestiole(Bestiole* b)
{
    if(bestioles.find(b->getIdentite()) == bestioles.end())
    {
        bestioles[b->getIdentite()] = b;
        auto tupleDescription = b->getDescription();
        std::cout<<"ID = "<<std::get<0>(tupleDescription)<<" X = "<<std::get<2>(tupleDescription)<<" Y = "<<std::get<3>(tupleDescription)
            <<" Vitesse = "<<std::get<4>(tupleDescription)<<" Orientation = "<<std::get<5>(tupleDescription)<<" Comportement = "
            <<std::get<6>(tupleDescription)<< std::endl;
        if(std::get<1>(tupleDescription).size()>0) {
            std::cout << "  Décorateurs : " << std::endl;
            for(auto deco:std::get<1>(tupleDescription)){
                std::cout<<"     -"<<deco<<std::endl;
                }
            }
        }
    else
        throw std::invalid_argument("L'identifiant associé à Bestiole existe déjà");
}
void Milieu::tuerBestiole(int id)
{
    if (bestioles.find(id) != bestioles.end())
    {
        delete bestioles.find(id)->second;
        bestioles.erase(bestioles.find(id));
        std::cout << "La bestiole : " << id << " a été tuée " << std::endl;
    }
}

void Milieu::tuerBestiole(int x, int y){
    for(auto b: this->getListeBestioles()){
        double distance = std::sqrt( (x-b->getX())*(x-b->getX()) + (y-b->getY())*(y-b->getY()));
        if(distance<Config::getInstance()->rayon){
            this->tuerBestiole(b->getIdentite());
            break;
        }
    }
}
