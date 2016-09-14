#include "CoreLoopDelegate.h"


int CoreLoopDelegate::Run ()
{
	
	/*									Currently available translations:	english-us	or	dutch-nl	*/
	if (localizationManager.LoadApplicationText (renderingManager.GetResourcesPath (), "english-us") != 0)
		return 1;
	
	renderingManager.localizationManager = &localizationManager;
	
	if (renderingManager.InitializeKISS () != 0)
		return 1;

	renderingManager.Update ();
	
	inputManager.renderingManager = &renderingManager;
	
	if (m_Loop () != 0)
		return 1;
	
	return 0;
}


int CoreLoopDelegate::m_Loop ()
{
	
	while (quit == NO)
	{
		
		SDL_Delay (m_millisecond_loop_delay);
		inputManager.GetInput (quit);
		renderingManager.Update ();
	}
	
	renderingManager.Stop ();
	
	return 0;
}