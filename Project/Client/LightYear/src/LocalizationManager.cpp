#include "LocalizationManager.h"


int LocalizationManager::LoadApplicationText (const std::string fileLocation, const std::string language)
{

	XMLManager xml;
	pugi::xml_document doc;
	std::string filePath = fileLocation + language + ".localized";
	pugi::xml_parse_result parse_result = xml.ReadFromFileToDoc (filePath, doc);
	
	/*If the desired language could not be found, default to English*/
	if (!parse_result)
	{
		
		std::cout << parse_result.description () << std::endl;
		std::cout << "Localization not found, trying English" << std::endl;
		
		doc.reset();
		parse_result = xml.ReadFromFileToDoc (fileLocation + "english-us.localized", doc);
	}
	
	if (parse_result)
	{
		
		pugi::xml_node localizationHeaders [5] = {
			doc.child ("Localization").child ("Meta"),
			doc.child ("Localization").child ("General"),
			doc.child ("Localization").child ("Windows").child ("MainMenu"),
			doc.child ("Localization").child ("Windows").child ("Options"),
			doc.child ("Localization").child ("Windows").child ("About")
		};
		
		
		int headerIndex = 0;
		while (headerIndex < ALL_HEADERS)
		{
			
			for (pugi::xml_node langString = localizationHeaders[headerIndex].first_child (); langString; langString = langString.next_sibling ())
			{
				
				for (pugi::xml_attribute attr = langString.first_attribute (); attr; attr = attr.next_attribute ())
				{
					
					m_PopulateApplicationLocalizationMap (headerIndex, attr.as_int (), langString.child_value ());
				}
			}
			
			headerIndex += 1;
		}
	} else {
		
		std::cout << "Unable to locate either " << language << " or english-us localization file!" << std::endl;
		
		return 1;
	}
	
	return 0;
}


void LocalizationManager::m_PopulateApplicationLocalizationMap (const unsigned int menu, const unsigned int index, const std::string string)
{
	
	std::map <int, std::string> *localizationMap;
	
	switch (menu)
	{
		
		case META:
			localizationMap = &m_metaLocalization;
			break;
			
		case GENERAL:
			localizationMap = &m_generalLocalization;
			break;
		
		case MAINMENU:
			localizationMap = &m_mainMenuLocalization;
			break;
			
		case OPTIONS:
			localizationMap = &m_optionsLocalization;
			break;
	
		case ABOUT:
			localizationMap = &m_aboutLocalization;
			break;
	}
	
	localizationMap->insert (std::map<int, std::string>::value_type (index, string));
}


std::string LocalizationManager::GetLocalizedApplicationText (const unsigned int menu, const unsigned int index)
{
	
	std::map <int, std::string> *localization;
	
	switch (menu)
	{
		
		case META:
			localization = &m_metaLocalization;
			break;
			
		case GENERAL:
			localization = &m_generalLocalization;
			break;
		
		case MAINMENU:
			localization = &m_mainMenuLocalization;
			break;
			
		case OPTIONS:
			localization = &m_optionsLocalization;
			break;
	
		case ABOUT:
			localization = &m_aboutLocalization;
			break;
	}
	
	m_localizationSearch = localization->find (index);
	
	if (m_localizationSearch != localization->end ())
	{
		
		return m_localizationSearch->second;
	} else {
		
		return ("Localization index " + std::to_string (index) + " invalid");
	}
}
