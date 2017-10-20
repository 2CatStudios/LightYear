#ifndef XMLManager_H
#define XMLManager_H

#include <string>
#include <map>

#include "Global.h"
#include "pugixml.hpp"


class XMLManager
{
	
public:
	pugi::xml_parse_result ReadFromFileToDoc (const std::string filePath, pugi::xml_document &doc);
	void CreateDocumentTree (pugi::xml_document &doc, std::map <int, std::string> *localizations);

private:
	void m_PopulateApplicationLocalizationMap (const unsigned int menu, const unsigned int index, const std::string string, std::map <int, std::string> *localizations);
};

#endif //XMLManager_H