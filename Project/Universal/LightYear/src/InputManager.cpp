#include "InputManager.h"

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