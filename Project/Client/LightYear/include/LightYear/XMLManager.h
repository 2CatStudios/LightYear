#ifndef XMLManager_H
#define XMLManager_H

#include "pugixml.hpp"


class XMLManager
{
	
public:
	int ReadFromFileToDoc (const char *filePath, pugi::xml_document &doc);

private:
	
};

#endif //XMLManager_H