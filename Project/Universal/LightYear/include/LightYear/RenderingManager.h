#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include "kiss_sdl.h"
#include <iostream>


typedef struct menu
{
	
	bool created = false;
	
	kiss_array gui_objects;
	kiss_window window;

} menu;


typedef struct menu_main : menu
{
	
	kiss_label label_version;
	kiss_label label_title;
	kiss_label label_subtitle;
	kiss_button button_playGame;
	kiss_button button_options;
	kiss_button button_about;
	kiss_button button_quit;

} menu_main;


typedef struct menu_options : menu
{

} menu_options;


typedef struct menu_about : menu
{
	
	kiss_label label_title;
	kiss_label label_preamble_top;
	kiss_label label_preamble_bottom;
	
	kiss_label label_twocatstudios;
	kiss_label label_team_michaelb;
	kiss_label label_team_janh;
	
	kiss_label label_thanksto;
	kiss_label label_supporters_bleikur;
	kiss_label label_supporters_tarvok;
	
	kiss_button button_back;

} menu_about;


class RenderingManager
{

public:
	kiss_array objects;
	
	enum MenuState {NONE = 0, MAINMENU = 1, SELECTGAME = 2, OPTIONS = 3, ABOUT = 4};
	MenuState menuState = NONE;
	
	menu_main mainMenu;
	//menu_options optionsMenu;
	menu_about aboutMenu;
	
	int draw = 1;
	
	int InitializeKISS ();
	
	int CreateMainMenu ();
	int CreateAboutMenu ();
	
	void Update ();
	void Stop ();

private:
	SDL_Renderer *m_renderer;
	
	void m_DrawMainMenu ();
	void m_DrawAboutMenu ();
	
	const int m_buttonPadding = 18;
	const int m_labelPadding = 15;
};

#endif /* end of include guard: RENDERINGMANAGER_H */
