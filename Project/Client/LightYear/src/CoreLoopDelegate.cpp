#include "CoreLoopDelegate.h"


int CoreLoopDelegate::Run ()
{
	
	//SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
	
	
	/*										Currently available translations:	english-us	or	dutch-nl	*/
	if (localizationManager.LoadApplicationText (fileManager.GetResourcesPath (), "english-us") != 0)
		return 1;
	
	renderingManager.localizationManager = &localizationManager;
	
	if (renderingManager.InitializeKISS () != 0)
		return 1;
	
	renderingManager.menuState = RenderingManager::MAINMENU;
	renderingManager.Update ();
	
	inputManager.renderingManager = &renderingManager;
	
	if (m_Loop () != 0)
		return 1;
	
	return 0;
}


void CoreLoopDelegate::m_DebugSDL2Paths ()
{
	
	std::cout << std::endl << "GetApplicationPath () : " << fileManager.GetApplicationPath () << std::endl;
	std::cout << std::endl << "GetResourcesPath () : " << fileManager.GetResourcesPath () << std::endl;
	std::cout << std::endl << "GetPreferencesPath () : " << fileManager.GetPreferencesPath () << std::endl;
}


int CoreLoopDelegate::m_Loop ()
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