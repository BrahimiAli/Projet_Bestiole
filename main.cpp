#include "Aquarium.h"
#include "Milieu.h"
#include "Configuration.h"
#include "FabriqueEspeceA.h"
#include "Decorateur.h"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    freopen("log","w",stdout); // redirection des std::cout vers le fichier log
    // Config test
    Config::filename = argv[1];
    Aquarium aquarium = Aquarium();
    aquarium.run();
    fclose(stdout);
   return 0;
}
