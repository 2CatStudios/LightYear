#include "FileManager.h"

std::string FileManager::GetApplicationPath ()
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


std::string FileManager::GetResourcesPath ()
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


std::string FileManager::GetPreferencesPath ()
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