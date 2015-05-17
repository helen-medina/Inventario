INC=-I../headers
BIN=../bin/
all: processInventario
processInventario: main.o ProcessFile.o
	g++ -std=c++0x main.o ProcessFile.o -include global.h -o $(BIN)processInventario
ProcessFile.o: ProcessFile.cpp 
	g++ $(INC) -std=c++0x -g -c ProcessFile.cpp

	
main.o: main.cpp 
	g++ $(INC) -std=c++0x -g -c main.cpp


imprime:
	@echo "Fin"
clean: 
	 rm -rf *o processInventario
