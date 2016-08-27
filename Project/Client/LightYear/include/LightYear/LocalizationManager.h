#ifndef LOCALIZATIONMANAGER_H
#define LOCALIZATIONMANAGER_H

#include <iostream>
#include <string>
#include <map>

#include "kiss_sdl.h"
#include "XMLManager.h"


class LocalizationManager
{
	
public:
	int LoadApplicationText (const std::string fileLocation, const std::string language);
	std::string GetLocalizedApplicationText (unsigned int menu, unsigned int index);
	
	enum LocalizationMeta {
		M_LANGUAGE = 0,
		M_TRANSLATOR = 1,
		M_TRANSLATOR_CONTACT = 2,
		M_TRANSLATION_VERSION = 3,
		M_ENGINE_VERSION = 4,
		M_COMPLETE = 5
	};
	
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
	
	const int ALL_HEADERS = 5;
	enum LocalizationApplicationHeaders {
		META = 0,
		GENERAL = 1,
		MAINMENU = 2,
		OPTIONS = 3,
		ABOUT = 4
	};
	
private:
	
	std::map <int, std::string> m_metaLocalization;
	std::map <int, std::string> m_generalLocalization;
	std::map <int, std::string> m_mainMenuLocalization;
	std::map <int, std::string> m_optionsLocalization;
	std::map <int, std::string> m_aboutLocalization;
	
	std::map <int, std::string>::iterator m_localizationSearch;
	
	void m_PopulateApplicationLocalizationMap (const unsigned int menu, const unsigned int index, const std::string string);
	void m_AddApplicationLocalizedText (int localizedTextIndex, char *localizedText);
};

#endif /* end of include guard: LOCALIZATIONMANAGER_H */