#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>
#include "Configuration.h"
#include "Milieu.h"
#include <list>
#include "Bestiole.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu *flotte;
   int delay;

public :
   Aquarium(void);
   ~Aquarium( void );

   void run( void );
   void creerRapport(Milieu* milieu);
   Milieu* getMilieu() {return this->flotte;};

};


#endif
