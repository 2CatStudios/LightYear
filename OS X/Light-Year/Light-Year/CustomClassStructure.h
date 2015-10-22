//
//  CustomClassStructure.h
//  Light-Year
//
//  Created by Michael Bethke on 10/19/15.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#ifndef CustomClassStructure_h
#define CustomClassStructure_h

#include <stdio.h>
#include <list>

class SimepleString {

public:
	char* name;
	char* contents;

private:
	char* uuid;
};


class CustomClass {

public:
	char* name;

	std::list<SimepleString*> simpleStrings;

private:
	char* uuid;
};

#endif /* CustomClassStructure_h */