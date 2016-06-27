#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include "kiss_sdl.h"
#include "LexicalManager.h"


class RenderingManager
{

public:
	kiss_array objects;
	kiss_array menu_gui_objects;
	
	kiss_window window_menu;
	kiss_label label_version;
	kiss_label label_title;
	kiss_label label_subtitle;
	kiss_button button_playGame;
	kiss_button button_options;
	kiss_button button_about;
	kiss_button button_quit;
	
	int draw = 1;
	
	int InitializeKISS ();
	int CreateWindowMenu ();
	void DrawWindowMenu ();
	void Update ();
	void Stop ();

private:
	SDL_Renderer *m_renderer;
	LexicalManager m_lexicalManager;
	
	const int m_buttonPadding = 18;
};

#endif /* end of include guard: RENDERINGMANAGER_H */
