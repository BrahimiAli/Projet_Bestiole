#include "Aquarium.h"
#include "Milieu.h"
#include "Configuration.h"
#include "FabriqueEspeceA.h"
#include "Decorateur.h"
#include "DecoratorHeader.h"
#include <iostream>

std::list<Bestiole*> updateList(int testNb, std::list<Bestiole*> bestioles, FabriqueEspeceA fabrique) {

  unsigned char col[3] = {255, 0, 255};
  EspeceA* newBestiole = fabrique.fabriquerEspeceA(new Gregaire, col);

  switch(testNb) {
    case 0 : // Test le changement de vitesse de Nageoire
    {
      bestioles.front()->setVitesse(5);
      newBestiole->setVitesse(5);
      newBestiole = new Nageoire(newBestiole, 10);
      bestioles.back() = newBestiole;
      break;
    }
    case 1 : // Test le changement de vitesse de Carapace
    {
      bestioles.front()->setVitesse(5);
      newBestiole->setVitesse(5);
      newBestiole = new Carapace(newBestiole, 0, 10);
      bestioles.back() = newBestiole;
      break;
    }
    case 2 : // Test le changement de robustesse de Carapace
    {
      bestioles.front()->setVitesse(5);
      newBestiole->setVitesse(5);
      newBestiole = new Carapace(newBestiole, 1000000, 10);
      bestioles.back() = newBestiole;
      bestioles.back()->collisionBestiole(); // La probabilité de mort étant 1, la survie de cette bestiole prouve le fonctionnement
      break;
    }
    case 3: // Test la vision par l'oreille : trop loin
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole = new Oreille(newBestiole, 1, 15);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 4: // Test la vision par l'oreille : assez proche
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole = new Oreille(newBestiole, 1, 25);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 5: // Test la vision par l'Oeuil : trop loin et mauvais angle
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oeuil(newBestiole, 1, 15, 0);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 6: // Test la vision par l'oeuil : assez proche mais mauvais angle
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oeuil(newBestiole, 1, 25, 0);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 7: // Test la vision par l'oeuil : trop loin mais bon angle
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oeuil(newBestiole, 1, 15, 6);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      bool temp = newBestiole->jeTeVois(*bestioles.front());
      if (temp) {
        bestioles.front()->setX(42);
        cout << temp;
      }
      break;
    }
    case 8: // Test la vision par l'oeuil : assez proche et bon angle
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oeuil(newBestiole, 1, 25, 6);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 9: // Test la vision par l'oreille mais pas par l'oeuil
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oreille(new Oeuil(newBestiole, 1, 0, 0), 1, 25);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 10: // Test la vision par l'oeuil mais pas par l'oreille
    {
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oreille(new Oeuil(newBestiole, 1, 25, 6), 0, 0);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    case 11: // Test le camouflage
    {
      EspeceA* autreBestiole = fabrique.fabriquerEspeceA(new Gregaire, col);
      autreBestiole = new Camouflage(autreBestiole, 1);
      bestioles.front() = autreBestiole;
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oreille(newBestiole, 1, 25);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    }
  return bestioles;
}

bool resultatAttendu(int testNb, std::list<Bestiole*> listeBestioles) {
  switch(testNb) {
    case 0: {
      double v0 = listeBestioles.front()->getVitesse();
      double v1 = listeBestioles.back()->getVitesse();
      return (v1/v0 == 10);
    }
    case 1: {
      double v0 = listeBestioles.front()->getVitesse();
      double v1 = listeBestioles.back()->getVitesse();
      return (v1/v0 == 0.10);
    }
    case 2: {
      return (listeBestioles.back()->getAge() != Config::getInstance()->maxAge);
    }
    case 3: {
      return (!(listeBestioles.front()->getX()==42));
    }
    case 4: {
      return (listeBestioles.front()->getX()==42);
    }
    case 5: {
      return (!(listeBestioles.front()->getX()==42));
    }
    case 6: {
      return (!(listeBestioles.front()->getX()==42));
    }
    case 7: {
      return (!(listeBestioles.front()->getX()==42));
    }
    case 8: {
      return (listeBestioles.front()->getX()==42);
    }
    case 9: {
      return (listeBestioles.front()->getX()==42);
    }
    case 10: {
      return (listeBestioles.front()->getX()==42);
    }
    case 11: {
      return (!(listeBestioles.front()->getX()==42));
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  Config::filename = argv[1];
  Milieu* flotte = new Milieu(Config::getInstance()->width, Config::getInstance()->height);
  std::list<Bestiole*> listeBestioles;
  FabriqueEspeceA* fabrique = new FabriqueEspeceA();
  int nbTestsReussis = 0;
  int nbTestsTotal = 12; // TO UPDATE
  for (int i = 0; i < nbTestsTotal; i++) {
    cout << "Test numéro " << i << " : ";
    listeBestioles = flotte->getListeBestioles();
    listeBestioles = updateList(i, listeBestioles, *fabrique);
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
  delete flotte;
  delete fabrique;
}
