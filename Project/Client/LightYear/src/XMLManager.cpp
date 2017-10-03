#include "XMLManager.h"

pugi::xml_parse_result XMLManager::ReadFromFileToDoc (const std::string filePath, pugi::xml_document &doc)
{
	
	pugi::xml_parse_result result = doc.load_file (filePath.c_str ());
	
	return result;
}