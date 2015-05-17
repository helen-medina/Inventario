
#include <fstream>  // library that contains file input/output functions
#include <stdlib.h> 
#include <sstream>
#include <stdexcept>
#include "ProcessFile.h"

int main()
{
	ProcessFile pFile;
	std::string line;
	std::ifstream is ("ARTÍCULOS.TXT", std::ifstream::binary);
 	if (!is) {
		std::cout << "Failing opening the file" << std::endl;
	}
	else
	{

		//Get characteristics of every product
		while(getline(is, line)) 
		{
			if(!is.eof())
			{
				try
				{
    					if (pFile.processLine(line))
						pFile.writeLine();
					else
					{
						std::cout << "No se puede escribir el fichero si hay";
						std::cout << "un problema al leer el datafile" << std::endl;
					}
				}
				catch(...)
				{
					std::cout << "Exception processing file" << std::endl;
					
				}
			}
    		}
		is.close();
	}



	return 0;
}


