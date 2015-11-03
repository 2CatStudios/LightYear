//
//  ReceiveInput.cpp
//  Light-Year
//
//  Created by Michael Bethke on 2015-11-02.
//  Copyright © 2015 2Cat Studios. All rights reserved.
//

#include "ReceiveInput.h"

const char* newStringFromInput (const char* input)
{

	const char* story = "";

	if (std::strncmp (input, "go down", strlen (input)))
	{

		story = "Step after step, you descend the cramped spiral-stairway, hearing only your solid leather boots striking the hard granite steps, and seeing little more. If it weren't for the moss occasionally felt along the cold, dull stone walls, it would seem like you're somehow stuck in a loop of the same left turn, and after ten minutes of this, a break might be nice.";
	} else {

		story = "I do not understand.";
	}

	return story;
}