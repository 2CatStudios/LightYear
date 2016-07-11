#ifndef XMLManager_H
#define XMLManager_H

#include "pugixml.hpp"


class XMLManager
{
	
public:
	int ReadFromFileToVector (pugi::xml_document& doc, const char* filePath);

private:
	
};

#endif //XMLManager_H