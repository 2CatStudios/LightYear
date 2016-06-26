#include "CoreLoopDelegate.h"


int CoreLoopDelegate::Run ()
{
	
	if (renderingManager.InitializeKISS () != 0)
		return 1;
	
	if (renderingManager.CreateWindowMenu () != 0)
		return 1;
	
	if (Loop () != 0)
		return 1;
	
	return 0;
}


int CoreLoopDelegate::Loop ()
{
	
	while (quit == 0)
	{
		
		SDL_Delay (m_millisecondLoopDelay);
		inputManager.GetInput (renderingManager, renderingManager.draw, quit);
		renderingManager.Update ();
	}
	
	renderingManager.Stop ();
	
	return 0;
}