#include "InputManager.h"


int InputManager::GetInput (RenderingManager renderingManager, int &draw, int &quit)
{
	
	while (SDL_PollEvent(&m_event))
	{
		
		if (m_event.type == SDL_QUIT)
		{
			quit = 1;
			break;
		}

		kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager.gui_objects, 0), &m_event, &draw);
		button_playGame_event ((kiss_button*) kiss_array_data (&renderingManager.gui_objects, 4), &m_event, &draw);
		button_options_event ((kiss_button*) kiss_array_data (&renderingManager.gui_objects, 5), &m_event, &draw);
		button_about_event ((kiss_button*) kiss_array_data (&renderingManager.gui_objects, 6), &m_event, &draw);
		button_quit_event ((kiss_button*) kiss_array_data (&renderingManager.gui_objects, 7), &m_event, &quit, &draw);
	}
	
	return 0;
}


void InputManager::button_playGame_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	kiss_button_event (button, e, draw);
}


void InputManager::button_options_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	kiss_button_event (button, e, draw);
}


void InputManager::button_about_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	kiss_button_event (button, e, draw);
}


void InputManager::button_quit_event (kiss_button *button, SDL_Event *e, int *quit, int *draw)
{
	
	if (kiss_button_event(button, e, draw))
		*quit = 1;
}