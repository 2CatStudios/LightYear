#include "LocalizationManager.h"


int LocalizationManager::LoadApplicationText ()
{

	XMLManager xml;
	pugi::xml_document doc;
	
	std::string filePath = RESDIR;
	filePath += "english-us.localized";
	
	if (xml.ReadFromFileToDoc (filePath.c_str(), doc) == 0)
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
	

// Attempt Two
	
	//char *localizationFile = RESDIR;
	//strcat (localizationFile, "english-us.localized");

	/*if (xml.ReadFromFileToDoc ("/Users/michaelbethke/Documents/Development/Projects/LightYear/Project/Client/LightYear_Build/resources/english-us.localized", doc) == 0)
	{
		
		std::cout << "unable to load file" << std::endl;
		return 1;
	}*/
	
	/*pugi::xml_node tools = doc.child ("Profile").child ("Tools");
	
	for (pugi::xml_node tool: tools.children("Tool"))
	{
		
		std::cout << "Tool:";
		
		for (pugi::xml_attribute attr: tool.attributes())
		{
			std::cout << " " << attr.name() << "=" << attr.value();
		}
		
		for (pugi::xml_node child: tool.children())
		{
			std::cout << ", child " << child.name();
		}
		
		std::cout << std::endl;
	}*/

	
// Attempt One
	
	/*if (xml.ReadFromFileToVector (doc, localizationFile) == 0)
	{
		
		pugi::xml_node text = doc.child ("Localization").child ("Strings");
		
		for (pugi::xml_node locText = text.first_child (); locText; locText = locText.next_sibling ())
		{

			for (pugi::xml_attribute attr = locText.first_attribute (); attr; attr = attr.next_attribute ())
			{

				m_applicationLocalization.insert (std::map<int, char *>::value_type (attr.as_int (), locText.child_value ()));
			}
		}
	} else
		return 1;*/
	
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