#include "XMLManager.h"

int XMLManager::ReadFromFileToDoc (const char *filePath, pugi::xml_document &doc)
{
	
	pugi::xml_parse_result result = doc.load_file (filePath);
	
	if (result)
		return 0;
	else
		return 1;
}