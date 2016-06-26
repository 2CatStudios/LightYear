#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "kiss_sdl.h"
#include "RenderingManager.h"


class InputManager
{
	
public:
	int GetInput (RenderingManager &renderingManager, int &quit);
	
	void button_playGame_event (kiss_button *button, SDL_Event *e, int *draw);
	void button_options_event (kiss_button *button, SDL_Event *e, int *draw);
	void button_about_event (kiss_button *button, SDL_Event *e, int *draw);
	void button_quit_event (kiss_button *button, SDL_Event *e, int *quit, int *draw);
	
private:
	SDL_Event m_event;
	
};


#endif /* end of include guard: INPUTMANAGER_H */
