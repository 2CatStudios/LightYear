//
//  UpdateString.cpp
//  Light-Year
//
//  Created by Michael Bethke on 2015-10-09.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#include "UpdateString.h"

/*const char* baseString = "%s's Hellos to you, World!";

const char* newStringFromInput(const char* stringInput)
{
	char* concatenedString = new char[strlen(baseString) + strlen(stringInput)];
	sprintf(concatenedString, baseString, stringInput);
	return concatenedString;
}*/

const char* buildVersion ()
{

	return engineBuildVersion();
}