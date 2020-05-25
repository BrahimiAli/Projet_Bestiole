SYSTEM = Aquarium.o Milieu.o Configuration.o FabriqueEspeceA.o RandInt.o RandDouble.o
DECORATEUR = Bestiole.o EspeceA.o Decorateur.o Accessoire.o Oreille.o Oeuil.o Nageoire.o Camouflage.o Carapace.o
COMPORTEMENT = BestioleSimple.o Gregaire.o Kamikaze.o Multiple.o Peureuse.o Prevoyante.o


main : main.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR)
	g++ -Wall -std=c++11 -o main main.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR) -I . -lX11 -lpthread


%.o : %.cpp %.h
	g++ -Wall -std=c++11  -c $< -I .

clean:
	rm *.o; rm main

testDeco: testDecorateur.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR)
	g++ -Wall -std=c++11 -o test testDecorateur.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR) -I . -lX11 -lpthread

testClonage: testClonage.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR)
	g++ -Wall -std=c++11 -o test testClonage.cpp $(SYSTEM) $(COMPORTEMENT) $(DECORATEUR) -I . -lX11 -lpthread
