#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include "kiss_sdl.h"
#include "LexicalManager.h"


typedef struct main_menu
{
	
	bool created = false;
	
	kiss_array gui_objects;
	
	kiss_window window;
	kiss_label label_version;
	kiss_label label_title;
	kiss_label label_subtitle;
	kiss_button button_playGame;
	kiss_button button_options;
	kiss_button button_about;
	kiss_button button_quit;

} main_menu;


class RenderingManager
{

public:
	kiss_array objects;
	
	enum MenuState {NONE = 0, MAINMENU = 1, SELECTGAME = 2, OPTIONS = 3, ABOUT = 4};
	MenuState menuState = NONE;
	
	main_menu mainMenu;
	
	int draw = 1;
	
	int InitializeKISS ();
	
	int CreateMainMenu ();
	int CreateAboutMenu ();
	
	void Update ();
	void Stop ();

private:
	SDL_Renderer *m_renderer;
	LexicalManager m_lexicalManager;
	
	void m_DrawMainMenu ();
	void m_DrawAboutMenu ();
	
	const int m_buttonPadding = 18;
};

#endif /* end of include guard: RENDERINGMANAGER_H */
