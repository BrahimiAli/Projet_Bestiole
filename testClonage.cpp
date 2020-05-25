#include "Aquarium.h"
#include "Milieu.h"
#include "Configuration.h"
#include "FabriqueEspeceA.h"
#include "Decorateur.h"
#include "DecoratorHeader.h"
#include <iostream>

std::list<EspeceA*> updateList(int testNb, std::list<EspeceA*> bestioles,FabriqueEspeceA* fabrique) {

  unsigned char col[3] = {255, 0, 255};
  EspeceA* newBestiole = fabrique->fabriquerEspeceA(new Gregaire,col);
  // Décoration de la bestiole
  newBestiole->setAge(10);
  bestioles.push_back(newBestiole);
  switch(testNb) {
    case 0 : // Test le changement de vitesse de Nageoire
      EspeceA* clone = newBestiole->cloner();
      bestioles.push_back(clone);
      break;
    }
  return bestioles;
}

bool resultatAttendu(int testNb, std::list<EspeceA*> listeBestioles) {
  switch(testNb) {
    case 0: {
      double v0 = listeBestioles.front()->getVitesse();
      double v1 = listeBestioles.back()->getVitesse();
      int age0 = listeBestioles.front()->getAge();
      int age1 = listeBestioles.back()->getAge();
      int ageMax0 = listeBestioles.front()->getAgeMax();
      int ageMax1 = listeBestioles.back()->getAgeMax();
      double camouflage0 = listeBestioles.front()->getCamouflage();
      double camouflage1 = listeBestioles.back()->getCamouflage();
      unsigned char* color0 = listeBestioles.front()->getColor();
      unsigned char* color1 = listeBestioles.back()->getColor();
      Comportement* c0 = listeBestioles.front()->getComportement();
      Comportement* c1 = listeBestioles.back()->getComportement();
      return (v1 == v0)&&(age0 == age1)&&(ageMax0 == ageMax1)&&(camouflage0 == camouflage1)&&(color0[0] == color1[0])&&(color0[1] == color1[1])&&(color0[2] == color1[2])&&(typeid(*c0).name()==typeid(*c1).name());
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::list<EspeceA*> listeBestioles;
  FabriqueEspeceA* fabrique = new FabriqueEspeceA();
  int nbTestsReussis = 0;
  int nbTestsTotal = 1; // TO UPDATE
  for (int i = 0; i < nbTestsTotal; i++) {
    cout << "Test numéro " << i << " : ";
    listeBestioles = updateList(i, listeBestioles,fabrique);
    if (resultatAttendu(i, listeBestioles)) {
      nbTestsReussis ++;
      cout << "OK" << endl;
    }
    else {
      cout << "Error" << endl;
      cout << "Erreur sur le test numéro " << i << endl;
    }
  }
  cout << "Tests réussis " << nbTestsReussis << " sur un total de " << nbTestsTotal << " tests" << endl;
  delete fabrique;
  for (auto e : listeBestioles)
    delete e;
}
