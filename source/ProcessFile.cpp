
#include <sstream>
#include <fstream> 
#include <iostream>
#include <string>
#include <stdexcept>
#include "ProcessFile.h"

using namespace std;

ProcessFile::ProcessFile()
{
	//write the head of the file
	 mFirst = 1;
	//Initialize inventore fields 
	
	sInventario.nivelAcceso = 100; //active by defaulta
	sInventario.categoria = "Mueble"; //cambiar*******************++++
	//string categoria;// tratamiento especial
	//string codeBarraFormato; codigo EAN
	sInventario.nivelAccesoFormato = sInventario.nivelAcceso;
	sInventario.upParameters = 0;//no update parameters
	sInventario.upImagesProduct = 0; //no update image
	sInventario.upImagesFormat = 0; //no update format
	sInventario.Price = 0;
	sInventario.available = 1;// product is available
	sInventario.largo = 0.0;
	sInventario.alto = 0.0;
	sInventario.ancho = 0.0;
	sInventario.unitLength = "Cm";
	sInventario.cantidad = 'U';
}
void ProcessFile::writeLine ()
{


	std::ofstream myfile;  
	myfile.open ("output.txt",ios::out | ios::app); 
	
	myfile << sInventario.codigo<< " ; " 
		<< sInventario.nivelAcceso << " ; "
		<< sInventario.nombre << " ; "
		<< sInventario.categoria << " ; "
		<< sInventario.DescriptionShort << " ; "
		<< sInventario.Description << " ; "
		<< sInventario.Price << " ; "
		<< sInventario.available << " ; "
		<< sInventario.nameFileImage << " ; "
		<< sInventario.SKU << " ; "
		<< sInventario.color << " ; "
		<< sInventario.codeBarraFormato << " ; "
		<< sInventario.largo << " ; "
		<< sInventario.ancho << " ; "
		<< sInventario.alto << " ; "
		<< sInventario.unitLength << " ; "
		<< sInventario.cantidad << " ; "
		<< sInventario.nivelAccesoFormato << " ; "
		<< sInventario.upParameters << " ; "
		<< sInventario.upImagesProduct << " ; "
		<< sInventario.upImagesFormat <<  std::endl;  

	myfile.close();
}
void ProcessFile::writeHead (){

	std::ofstream myfile;  
	myfile.open ("output.txt",ios::out | ios::app); 
	
	myfile << "CODIGO"<< " ; " 
		<< "NIVEL DE ACCESO" << " ; "
		<< "NOMBRE" << " ; "
		<< "CATEGORIA" << " ; "
		<< "DESCRIPCION CORTA" << " ; "
		<<  "DESCRIPCION" << " ; "
		<<  "IMPORTE"<< " ; "
		<<  "ACTIVO/EN VENTA"<< " ; "
		<<  "NOMBRE ARCHIVO IMAGEN "<< " ; "
		<<  "NOMBRE SKU"<< " ; "
		<< "COLOR" << " ; "
		<< "CODIGO DE BARRAS DE FORMATO" << " ; "
		<< "LONGITUD" << " ; "
		<< "ANCHO" << " ; "
		<< "ALTO" << " ; "
		<< "ABREVIACION DE UNIDAD DE MEDIDA DE LONGITUD" << " ; "
		<< "ABREVIACION DE UNIDAD DE MEDIDA DE CANTIDAD" << " ; "
		<< "NIVEL DE ACCESO DEL FORMATO" << " ; "
		<< "ACTUALIZAR PARÁMETROS" << " ; "
		<< "ACTUALIZAR GALERIA IMAGENES DE PRODUCTO" << " ; "
		<< "ACTUALIZAR GALERIA IMAGENES DE FORMATO" << std::endl;
		 

	myfile.close();

}

bool ProcessFile::processLine (string line){
	bool success = true;
	//fill the columns
	if (isFirstLine())
	{
		mFirst = 0;
		writeHead();
		
		
	}
	//fill the product's descriptions 


	try
	{


		std::cout << " Producto: \n " << std::endl;
		//Obtenemos los fields del producto
		sInventario.codigo =line.substr (0,12);
		sInventario.SKU = sInventario.codigo;
		std::cout << "codigo: " << sInventario.codigo << "  \n";
		sInventario.nombre =line.substr (13,30);
		std::cout << "nombre:  " << sInventario.nombre << "  \n";
		/*sInventario.descriptionIng =line.substr (43,30);
		std::cout << "Description Ingles:  " << sInventario.descriptionIng << "  \n";
		sInventario.descriptionFra =line.substr (73,30);
		std::cout << "Description Frances:  " << sInventario.descriptionFra << "  \n";*/
		sInventario.caracEspa =line.substr (115,30);
		std::cout << "caracteristicas:  " << sInventario.caracEspa << "  \n";
		/*sInventario.pesoBruto =line.substr (573,7);
		std::cout << "Peso bruto:  " << sInventario.pesoBruto << "  \n";
		sInventario.volumen =line.substr (587,7);
		std::cout << "volumen:  " << sInventario.volumen << "  \n";*/

		//tratamiento especial crear function diferente	
		/*sInventario.largo =atoi(line.substr (804,6).c_str());
		std::cout << "largo:  " << sInventario.largo << "  \n";
	
		sInventario.ancho =atoi(line.substr (810,6).c_str());
		std::cout << "ancho:  " << sInventario.ancho << "  \n";

		sInventario.alto =atoi(line.substr (816,6).c_str());
		std::cout << "alto:  " << sInventario.alto << "  \n";
		sInventario.s =line.substr (816,6);*/
		//extrae the measures
		sInventario.sdesc1 =line.substr (175,30);
		std::cout  << sInventario.sdesc1 << "  \n";	
		sscanf(sInventario.sdesc1.c_str(), "%*[^0-9]%d",&sInventario.largo);

		sInventario.sdesc2 =line.substr (205,30);
		std::cout << sInventario.sdesc2 << "  \n";
		sscanf(sInventario.sdesc2.c_str(), "%*[^0-9]%d",&sInventario.ancho);

		sInventario.sdesc3 =line.substr (235,30);
		std::cout  << sInventario.sdesc3 << "  \n";
		sscanf(sInventario.sdesc3.c_str(), "%*[^0-9]%d",&sInventario.alto);

		sInventario.codeBarraFormato =line.substr (840,13);
		std::cout << "codeBarraFormato,,,:  " << sInventario.codeBarraFormato << "  \n";

		std::cout  << sInventario.largo << "  \n";
		std::cout  << sInventario.ancho << "  \n";
		std::cout  << sInventario.alto << "  \n";
		
	}
	catch( out_of_range& exception )
	{
   		cout  << "Problemas leyendo el formato del fichero: " << exception.what() << endl;
		
			
		
	}
	catch(...)
	{
		cout << "Error general" << endl;
		success = false;
		
	}
	//comprobar esto correcto
	return success;

	
}

bool ProcessFile::isFirstLine(){
	return mFirst;
}




