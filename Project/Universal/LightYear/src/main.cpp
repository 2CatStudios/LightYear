#include "LoopController.h"


int main (int argc, char *argv[])
{
	
	LoopController loopController;
	
	if (loopController.CoreLoop () != 0)
	{
		
		return 1;
	}

	return 0;
}