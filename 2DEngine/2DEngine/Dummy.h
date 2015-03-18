#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleDummy : public Module
{
	bool Init()
	{
		LOG("%s","Dummy Init!");
		return true;
	}

	bool CleanUp()
	{
		LOG("%s","Dummy CleanUp!");
		return true;
	}
};