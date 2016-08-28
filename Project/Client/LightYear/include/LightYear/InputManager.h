#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "kiss_sdl.h"
#include "RenderingManager.h"

#include <iostream>
#include <cmath>


class InputManager
{
	
public:
	RenderingManager *renderingManager;
	int GetInput (int &quit);
	
private:
	SDL_Event m_event;
	char *m_dropped_file_directory;
	
	void m_MainMenuWindowInput (int &quit);
	void m_SelectGameWindowInput ();
	void m_OptionsWindowInput ();
	void m_AboutWindowInput ();
	
	void m_mainmenu_window_menu_event (SDL_Event *e, int *draw);
	void m_mainmenu_button_playGame_event (kiss_button *button, SDL_Event *e, int *draw);
	void m_mainmenu_button_options_event (kiss_button *button, SDL_Event *e, int *draw);
	void m_mainmenu_button_about_event (kiss_button *button, SDL_Event *e, int *draw);
	void m_mainmenu_button_quit_event (kiss_button *button, SDL_Event *e, int *quit, int *draw);
	
	void m_selectgamemenu_window_menu_event (SDL_Event *e, int *draw);
	void m_selectgamemenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw);
	
	void m_optionsmenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw);
	
	void m_aboutmenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw);
	void m_aboutmenu_window_event (kiss_vscrollbar *vscrollbar, SDL_Event *e, int *draw);
	void m_aboutmenu_vscrollbar_event (kiss_vscrollbar *vscrollbar, SDL_Event *e, int *draw);
	
	int m_mainmenu_scroll_y = 0;
};


#endif /* end of include guard: INPUTMANAGER_H */
