#include "LocalizationManager.h"


int LocalizationManager::LoadApplicationText (const char *fileLocation)
{

	XMLManager xml;
	pugi::xml_document doc;
	
	//std::string filePath = RESDIR;
	//filePath += "english-us.localized";
	//std::cout << filePath << std::endl;
	
	//char *kiss_string_copy(char *dest, size_t size, char *str1, char *str2)
	
	if (xml.ReadFromFileToDoc (fileLocation, doc) == 0)
	{
		
		/*pugi::xml_node strings = doc.child ("Localization").child ("Strings");
		
		for (pugi::xml_node langString = strings.first_child (); langString; langString = langString.next_sibling ())
		{

			for (pugi::xml_attribute attr = langString.first_attribute (); attr; attr = attr.next_attribute ())
			{

				AddLocalizedString (attr.as_int (), langString.child_value ());
			}
		}*/
		
		std::cout << "file read!" << std::endl;
	} else {
		
		std::cout << "unable to read file" << std::endl;
		return 1;
	}
	
	return 0;
}


char *LocalizationManager::GetLocalizedApplicationText (unsigned int textAtIndex)
{
	
	char *errorText = "Error: ";
	
	if (m_applicationLocalization.empty ())
	{
		
		strcat (errorText, "Application localization empty");
		return errorText;
	}
	
	if (textAtIndex > m_applicationLocalization.size ())
	{
		
		strcat (errorText, "Index out of bounds");
		return errorText;
	}
	
	m_localizationSearch = m_applicationLocalization.find (textAtIndex);
	if (m_localizationSearch != m_applicationLocalization.end())
	{
		
		return m_localizationSearch->second;
	} else {
		
		strcat (errorText, "in localization at ");
		
		const char indexText = (char) textAtIndex;
		strcat (errorText, &indexText);
		
		return errorText;
	}
}