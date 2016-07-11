#include "LocalizationManager.h"


int LocalizationManager::LoadApplicationText ()
{
	
	XMLManager xml;
	pugi::xml_document doc;
	
	/*if (xml.ReadFromFileToVector (doc, (io.PathUpLevels (io.GetApplicationPath (), 2) + ("/resources/" + desiredLanguage + ".localized")).c_str ()) == 0)
	{
		
		pugi::xml_node text = doc.child ("Localization").child ("Strings");
		
		for (pugi::xml_node locText = text.first_child (); locText; locText = locText.next_sibling ())
		{

			for (pugi::xml_attribute attr = locText.first_attribute (); attr; attr = attr.next_attribute ())
			{

				m_applicationLocalization.insert (std::map<int, char *>::value_type (attr.as_int (), locText.child_value ()));
			}
		}
	} else return 1;*/
	
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