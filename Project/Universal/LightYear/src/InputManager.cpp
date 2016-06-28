#include "InputManager.h"


void InputManager::Startup (RenderingManager *rendering_manager)
{
	
	renderingManager = rendering_manager;
}


int InputManager::GetInput (int &quit)
{
	
	while (SDL_PollEvent(&m_event))
	{
		
		if (m_event.type == SDL_QUIT)
		{
			quit = 1;
			break;
		}

		switch (renderingManager->menuState)
		{
		
			case RenderingManager::NONE:
				break;
		
			case RenderingManager::MAINMENU:
				m_MainMenuWindowInput (quit);
				break;
		
			case RenderingManager::SELECTGAME:
				break;
		
			case RenderingManager::OPTIONS:
				break;
		
			case RenderingManager::ABOUT:
				m_AboutWindowInput ();
				break;
		
			default:
				break;
		}
	}
	
	return 0;
}


void InputManager::m_MainMenuWindowInput (int &quit)
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 0), &m_event, &renderingManager->draw);
	m_mainmenu_button_playGame_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 4), &m_event, &renderingManager->draw);
	m_mainmenu_button_options_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 5), &m_event, &renderingManager->draw);
	m_mainmenu_button_about_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 6), &m_event, &renderingManager->draw);
	m_mainmenu_button_quit_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 7), &m_event, &quit, &renderingManager->draw);
}


void InputManager::m_AboutWindowInput ()
{
	
	
}


void InputManager::m_mainmenu_button_playGame_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	kiss_button_event (button, e, draw);
}


void InputManager::m_mainmenu_button_options_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	kiss_button_event (button, e, draw);
}


void InputManager::m_mainmenu_button_about_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		renderingManager->menuState = RenderingManager::ABOUT;
	}
}


void InputManager::m_mainmenu_button_quit_event (kiss_button *button, SDL_Event *e, int *quit, int *draw)
{
	
	if (kiss_button_event(button, e, draw))
		*quit = 1;
}