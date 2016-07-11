#ifndef LOCALIZATIONMANAGER_H
#define LOCALIZATIONMANAGER_H

#include "XMLManager.h"
#include "pugixml.hpp"
#include <map>


class LocalizationManager
{
	
public:
	int LoadApplicationText ();
	char *GetLocalizedApplicationText (unsigned int textAtIndex);
	
private:
	std::map <int, char*> m_applicationLocalization;
	std::map <int, char*>::iterator m_localizationSearch;
	
	void m_AddApplicationLocalizedText (int localizedTextIndex, char *localizedText);
};

#endif /* end of include guard: LOCALIZATIONMANAGER_H */
