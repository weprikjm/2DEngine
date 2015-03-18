#ifndef LOG_H
#define LOG_H

#include "main.h"

//#include <stdio.h>
//#include <wtypes.h>
//#include <assert.h>
//#include <string.h>

class Log
{
	//Atributs
	
	
	//Metodes
public:	
	Log(){}
	

	void LogPrint(LPCSTR formatstring, ...)
	{

		assert(formatstring != 0);									//Check			Com fer asserts dels arguments ...?
		int nSize = 0;
		static char buff[4096];
		static char finalString[4096];
		char buff[100];
		char finalString[200];

		memset(finalString, 0, sizeof(finalString));				//Reserva memoria i emplena amb 0s per a l'array
		memset(buff, 0, sizeof(buff));								



		va_list args;												//Serveix per recollir els arguments
		va_start(args, formatstring);
		nSize = vsnprintf_s(buff, _countof(buff), _TRUNCATE, formatstring, args);		//Retorna la mida del buff en bytes i posa els arguments de la funció al buff
		if (nSize < 0)
		{
			printf("Error");
		}

		Log::print("\n%s(%d)", __FILE__, __LINE__, "Es una prova genial");
		Log::print(": %s\n", "Es una prova genial");


		sprintf_s(finalString, 4096 ,"\n%s(%d) - Message: %s\n", file, line, buff);		//Formategem l'string final que ha de ser prou gran per contenir la totalitat de l'string

		sprintf_s(finalString, "%s(%d)\n - Message: %s\n", __FILE__, __LINE__, buff);		//Formategem l'string final que ha de ser prou gran per contenir la totalitat de l'string

		OutputDebugString(finalString);

		va_end(args);					//Obligatori

	}
	
	
	


	
	~Log(){}
};







#endif