#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include "Global.h"
#include "LocalizationManager.h"
#include "UIManager.h"
#include "kiss_sdl.h"

#include <iostream>
#include <string>


class RenderingManager
{

public:
	LocalizationManager *localizationManager;
	UIManager *uiManager;
	
	SDL_Renderer *renderer;
	
	int draw = YES;
	
	int InitializeKISS ();
	std::string GetApplicationPath ();
	std::string GetResourcesPath ();
	std::string GetPreferencesPath ();
	bool IsRetinaDisplay ();
	
	void DrawMenu (kiss_array *elements);
	
	void Update ();
	void Stop ();

private:
	std::string m_applicationPath;
	std::string m_resourcesPath;
	std::string m_preferencesPath;
	
	int m_retinaDisplay = -1;
	float m_dpi_difference = -1;
};

#endif /* end of include guard: RENDERINGMANAGER_H */
