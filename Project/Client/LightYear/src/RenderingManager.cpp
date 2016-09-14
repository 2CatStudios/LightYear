#include "RenderingManager.h"


int RenderingManager::InitializeKISS ()
{
	
	renderer = kiss_init (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_LIGHTYEAR).c_str (), &uiManager->objects, 1024, 576);
	uiManager->AddExternalAssets (&uiManager->objects);
	
	return 0;
}


std::string RenderingManager::GetApplicationPath ()
{
	
	if (m_applicationPath.empty ())
	{
		
		std::string base_path = SDL_GetBasePath ();
		
		if (base_path.empty ())
			base_path = "./";
		
		m_applicationPath = base_path;
	}
	
	return m_applicationPath;
}


std::string RenderingManager::GetResourcesPath ()
{
	
	if (m_resourcesPath.empty ())
	{
		
		std::string fullPath = GetApplicationPath ();
		std::string appendedString = fullPath;
		
		if (fullPath != "./")
		{
			
			appendedString.pop_back ();
			appendedString = appendedString.substr (0, appendedString.find_last_of (PATH_SEPARATOR) + 1);
			appendedString.append ("resources");
			appendedString += PATH_SEPARATOR;
		}
		
		m_resourcesPath = appendedString;
	}
	
	return m_resourcesPath;
}


std::string RenderingManager::GetPreferencesPath ()
{
	
	if (m_preferencesPath.empty ())
	{
		
		std::string base_path = SDL_GetPrefPath ("2Cat Studios", "LightYear IF");
		
		if (base_path.empty ())
			base_path = "./";
		
		m_preferencesPath = base_path;
	}
	
	return m_preferencesPath;
}


bool RenderingManager::IsRetinaDisplay ()
{
	
	if (m_retinaDisplay == -1)
	{
	
		float diagDPI = -1;
		float horiDPI = -1;
		float vertDPI = -1;
		
		if (SDL_GetDisplayDPI (0, &diagDPI, &horiDPI, &vertDPI) != 0)
		{
			
			std::cout << "Error: " << SDL_GetError () << std::endl;
			m_retinaDisplay = NO;
		}
		
		if (diagDPI - 109 > 0.001)
		{
			
			m_retinaDisplay = YES;
			m_dpi_difference = diagDPI - 109;
		} else if (diagDPI - 109 < 0.001 && diagDPI - 109 > -0.001)
		{
			
			m_retinaDisplay = NO;
		} else {
			
			std::cout << "Unknown DDPI, " << diagDPI << std::endl;
			m_retinaDisplay = NO;
		}
	}
	
	return m_retinaDisplay;
}


void RenderingManager::DrawMenu (kiss_array *elements)
{
	
	for (int i = 0; i < elements->length; i += 1)
	{
		
		
	}
}


void RenderingManager::Update ()
{
	
	if (draw == 0)
		return;
	
	SDL_RenderClear (renderer);
	uiManager->RefreshWindows ();
	
	switch (uiManager->menuState)
	{
		
		case UIManager::NONE:
			break;
		
		case UIManager::MAINMENU:
			
			uiManager->DrawMainMenu ();
			break;
		
		case UIManager::SELECTGAME:
			uiManager->DrawSelectGameMenu ();
			break;
		
		case UIManager::OPTIONS:
			uiManager->DrawOptionsMenu ();
			break;
		
		case UIManager::ABOUT:
			uiManager->DrawAboutMenu ();
			break;
		
		default:
			break;
	}
	
	kiss_renderimage (renderer, uiManager->globe_slice, 0, uiManager->globe_slice_y_position, NULL);
	
	SDL_RenderPresent (renderer);
	draw = 0;
}


void RenderingManager::Stop ()
{
	
	kiss_clean (&uiManager->objects);
}