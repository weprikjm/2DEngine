#pragma once
//#include "lList.h"
#include "Globals.h"
#include "Module.h"
#include "Dummy.h"

class Application
{
public:

	lList<Module*> list_modules;

public:

	Application()
	{
		ModuleDummy* pDummy = new ModuleDummy();

		AddModule(pDummy);
	}

	bool Init() 
	{

		lList<Module*>* item = list_modules.start;

		while (item != NULL)
		{
			item->data->Init();
			item = item->next;
		}


		return true;  
	}

	int Update() { return UPDATE_STOP; }
	bool CleanUp() { return true; }

private:

	void AddModule(Module* mod)
	{
		list_modules.add(mod);
	}
};