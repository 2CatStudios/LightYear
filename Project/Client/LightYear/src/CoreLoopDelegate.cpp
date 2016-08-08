#include "CoreLoopDelegate.h"


int CoreLoopDelegate::Run ()
{
	
	//std::cout << std::endl << "GetApplicationPath () : " << renderingManager.GetApplicationPath () << std::endl;
	std::cout << std::endl << "GetResourcesPath () : " << renderingManager.GetResourcesPath () << std::endl;
	//std::cout << std::endl << "GetPreferencesPath () : " << renderingManager.GetPreferencesPath () << std::endl;
	
	
	if (localizationManager.LoadApplicationText (renderingManager.GetResourcesPath ()) != 0)
		return 1;
	
	if (renderingManager.InitializeKISS () != 0)
		return 1;
	
	renderingManager.menuState = RenderingManager::MAINMENU;
	renderingManager.Update ();
	
	inputManager.renderingManager = &renderingManager;
	
	if (Loop () != 0)
		return 1;
	
	return 0;
}


int CoreLoopDelegate::Loop ()
{
	
	while (quit == NO)
	{
		
		SDL_Delay (m_millisecondLoopDelay);
		inputManager.GetInput (quit);
		renderingManager.Update ();
	}
	
	renderingManager.Stop ();
	
	return 0;
}