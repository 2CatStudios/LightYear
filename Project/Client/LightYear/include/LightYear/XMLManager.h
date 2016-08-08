#ifndef XMLManager_H
#define XMLManager_H

#include <string>
#include "pugixml.hpp"


class XMLManager
{
	
public:
	int ReadFromFileToDoc (const std::string filePath, pugi::xml_document &doc);

private:
	
};

#endif //XMLManager_H