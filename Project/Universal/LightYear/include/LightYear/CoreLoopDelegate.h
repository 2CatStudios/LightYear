#ifndef CORELOOPDELEGATE_H
#define CORELOOPDELEGATE_H

#include "InputManager.h"
#include "RenderingManager.h"
#include "kiss_sdl.h"


class CoreLoopDelegate
{

public:
	int Run ();

private:
	InputManager m_inputManager;
	
	SDL_Renderer *m_renderer;
	SDL_Event m_event;
	
	int m_draw = 1;
	int m_quit = 0;
	int m_millisecondLoopDelay = 10;
	
	const int m_buttonPadding = 18;
	
	kiss_array m_objects;
	
	kiss_window m_window_menu;
	kiss_label m_label_title;
	kiss_label m_label_subtitle;
	kiss_button m_button_playGame;
	kiss_button m_button_options;
	kiss_button m_button_about;
	kiss_button m_button_quit;
	kiss_label m_label_version;
	
	int InitializeKISS ();
	int CreateWindowMenu ();
	void DrawWindowMenu ();
	int Loop ();
	
};

#endif /* end of include guard: CORELOOPDELEGATE_H */
