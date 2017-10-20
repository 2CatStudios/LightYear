#include "LocalizationManager.h"


int LocalizationManager::LoadApplicationText (const std::string fileLocation, const std::string language)
{

	XMLManager xml;
	pugi::xml_document doc;
	std::string filePath = fileLocation + language + ".localized";
	
	pugi::xml_parse_result parse_result = xml.ReadFromFileToDoc (filePath, doc);
	
	if (!parse_result)
	{
		
		std::cout << "PUGIXML ERROR: '" << parse_result.description () << "' - Trying english-us" << std::endl;
		
		doc.reset();
		parse_result = xml.ReadFromFileToDoc (fileLocation + "english-us.localized", doc);
	}
	
	if (parse_result)
	{
		
		xml.CreateDocumentTree (doc, *m_localizations);
	} else {
		
		std::cout << "Unable to locate either " << language << " or english-us localization file. This is a fatal error. Check application resources for desired localization." << std::endl;
		
		return 1;
	}
	
	return 0;
}


std::string LocalizationManager::GetLocalizedApplicationText (const unsigned int menu, const unsigned int index)
{
	
	std::map <int, std::string>::iterator m_localizationSearch = m_localizations[menu]->find (index);
	
	if (m_localizationSearch != m_localizations[menu]->end ())
	{
		
		return m_localizationSearch->second;
	} else {
		
		return ("Localization index " + std::to_string (index) + " invalid");
	}
}
