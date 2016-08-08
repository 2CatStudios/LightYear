#ifndef LOCALIZATIONMANAGER_H
#define LOCALIZATIONMANAGER_H

#include "XMLManager.h"
#include "kiss_sdl.h"
#include <iostream>
#include <string>
#include <map>


class LocalizationManager
{
	
public:
	int LoadApplicationText (const std::string fileLocation);
	char *GetLocalizedApplicationText (unsigned int textAtIndex);
	
	enum LocalizationGeneral {
		G_LIGHTYEAR = 0,
		G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD = 1,
		G_VERSION = 2,
		G_DEVELOPMENT_STUDIO = 3,
		G_RETURN = 4
	};
	
	enum LocalizationMainMenu {
		MM_PLAY = 0,
		MM_OPTIONS = 1,
		MM_ABOUT = 2,
		MM_QUIT = 3
	};
	
	enum LocalizationOptions {
		O_OPTIONS = 0
	};
	
	enum LocalizationAbout {
		A_ABOUT = 0,
		A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE = 1,
		A_HAS_BEEN_LOVINGLY_CREATED_BY = 2,
		A_2CATSTUDIOS = 3,
		A_MICHAEL_BETHKE_LEAD_DEVELOPER = 4,
		A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT = 5,
		A_WITH_THANKS_TO = 6,
		A_BLEIKUR_DESIGN_AND_FEEDBACK = 7,
		A_TARVO_KORROVITS_KISS_SDL = 8
	};
	
private:
	std::map <int, char*> m_applicationLocalization;
	std::map <int, char*>::iterator m_localizationSearch;
	
	void m_AddApplicationLocalizedText (int localizedTextIndex, char *localizedText);
};

#endif /* end of include guard: LOCALIZATIONMANAGER_H */