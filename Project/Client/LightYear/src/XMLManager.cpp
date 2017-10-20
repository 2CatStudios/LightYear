#include "XMLManager.h"


pugi::xml_parse_result XMLManager::ReadFromFileToDoc (const std::string filePath, pugi::xml_document &doc)
{
		
	return doc.load_file(filePath.c_str());
}


void XMLManager::CreateDocumentTree (pugi::xml_document &doc, std::map <int, std::string> *localizations)
{
	pugi::xml_node localizationHeaders [5] = {
		doc.child ("Localization").child ("Meta"),
		doc.child ("Localization").child ("General"),
		doc.child ("Localization").child ("Windows").child ("MainMenu"),
		doc.child ("Localization").child ("Windows").child ("Options"),
		doc.child ("Localization").child ("Windows").child ("About")
	};
	
	int headerIndex = 0;
	while (headerIndex < LOCALIZATION_HEADERS_COUNT)
	{
		
		for (pugi::xml_node langString = localizationHeaders[headerIndex].first_child (); langString; langString = langString.next_sibling ())
		{
			
			for (pugi::xml_attribute attr = langString.first_attribute (); attr; attr = attr.next_attribute ())
			{
				
				m_PopulateApplicationLocalizationMap (headerIndex, attr.as_int (), langString.child_value (), localizations);
			}
		}
		
		headerIndex += 1;
	}
}


void XMLManager::m_PopulateApplicationLocalizationMap (const unsigned int menu, const unsigned int index, const std::string string, std::map <int, std::string> *localizations)
{
	
	std::map <int, std::string> *localizationMap;
	
	localizationMap = &localizations[menu];
	
	/*switch (menu)
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
	}*/
	
	localizationMap->insert (std::map<int, std::string>::value_type (index, string));
}