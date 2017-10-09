#ifndef FileManager_H
#define FileManager_H

#include <string>
#include "kiss_sdl.h"

#include "Global.h"

class FileManager
{
	
public:
	std::string GetApplicationPath ();
	std::string GetResourcesPath ();
	std::string GetPreferencesPath ();

private:
	std::string m_applicationPath;
	std::string m_resourcesPath;
	std::string m_preferencesPath;
};

#endif /* end of include guard: FileManager_H */
