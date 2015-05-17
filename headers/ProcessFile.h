
//class ProcessFile

#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include <string>
#include "global.h"


class ProcessFile{
	
	
	public:

		ProcessFile();
		void writeLine ();
		void writeHead ();
		bool isFirstLine();
		bool processLine (string line);

		~ProcessFile()
		{
			/*mRow = NULL;
			delete mRow;*/
		};

	protected:
		bool mFirst;
		fields sInventario;			
		
};

#endif
