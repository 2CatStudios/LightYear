#include "XMLManager.h"

int XMLManager::ReadFromFileToVector (pugi::xml_document &doc, const char *filePath)
{
	
	pugi::xml_parse_result result = doc.load_file (filePath);
	
	if (result)
	{
		
		return 0;
	}
	else
	{

		return 1;
	}
}