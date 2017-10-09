#include "CoreLoopDelegate.h"


int CoreLoopDelegate::Run ()
{
	
<<<<<<< HEAD
	/*									Currently available translations:	english-us	or	dutch-nl	*/
	if (localizationManager.LoadApplicationText (renderingManager.GetResourcesPath (), "english-us") != 0)
=======
	//SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
	
	
	/*										Currently available translations:	english-us	or	dutch-nl	*/
	if (localizationManager.LoadApplicationText (fileManager.GetResourcesPath (), "vietnamese-us") != 0)
>>>>>>> dry-ui
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


<<<<<<< HEAD
=======
void CoreLoopDelegate::m_DebugSDL2Paths ()
{
	
	std::cout << std::endl << "GetApplicationPath () : " << fileManager.GetApplicationPath () << std::endl;
	std::cout << std::endl << "GetResourcesPath () : " << fileManager.GetResourcesPath () << std::endl;
	std::cout << std::endl << "GetPreferencesPath () : " << fileManager.GetPreferencesPath () << std::endl;
}


>>>>>>> dry-ui
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