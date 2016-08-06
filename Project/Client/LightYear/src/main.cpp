#include "CoreLoopDelegate.h"


int main (int argc, char *argv[])
{
	
	CoreLoopDelegate coreLoopDelegate;
	if (!coreLoopDelegate.Run ()) return 1;
	
	return 0;
}