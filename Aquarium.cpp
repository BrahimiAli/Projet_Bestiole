#include "Aquarium.h"


Aquarium::Aquarium() : CImgDisplay(), delay(Config::getInstance()->_delay)
{
    int screenWidth = 1280; //screen_width();
    int screenHeight = 1024; //screen_height();
    flotte = new Milieu(Config::getInstance()->width, Config::getInstance()->height);
    //Config::getInstance()->setSupport(flotte);
    assign(flotte->getSupportGraphique(), "Simulation d'ecosysteme");
    move(static_cast<int>((screenWidth-Config::getInstance()->width)/2), static_cast<int>((screenHeight-Config::getInstance()->height)/2));
}

void Aquarium::creerRapport(Milieu* milieu)
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    std::stringstream filename;
    filename << "Rapport_Simulation-";
    filename << (now->tm_year + 1900) << '_'
       << (now->tm_mon + 1) << '_'
       <<  now->tm_mday << '_'
       <<  now->tm_hour << '_'
       <<  now->tm_min  << '_'
       <<  now->tm_sec << ".txt";
    std::ofstream myfile;
    myfile.open(filename.str());
    milieu->genererRapport(myfile);
};

Aquarium::~Aquarium( void )
{
    creerRapport(flotte);
    delete flotte;
}

void Aquarium::run( void )
{
    while (!is_closed())
    {
      //std::cout << "iteration de la simulation" << endl;
      if (is_key()) {
         std::cout << "Vous avez presse la touche " << static_cast<unsigned char>(key());
         std::cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }
      if(button()&1){
          flotte->tuerBestiole(mouse_x(),mouse_y());
      }
      flotte->step();
      display(flotte->getSupportGraphique());
      wait(delay);
    }
}
