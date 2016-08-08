#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include <iostream>

#include <string>
#include "kiss_sdl.h"

#if defined (WIN32) || defined (_WIN32)
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

#define YES 1
#define NO 0


class Menu
{

public:
	bool created = false;
	
	kiss_array gui_objects;
	kiss_window window;
	
private: 
	void m_hideMenu ();

};


typedef struct menu_main : Menu
{
	
	kiss_label label_version;
	kiss_label label_title;
	kiss_label label_subtitle;
	kiss_button button_playGame;
	kiss_button button_options;
	kiss_button button_about;
	kiss_button button_quit;

} menu_main;


typedef struct menu_selectgame : Menu
{
	
	kiss_button button_back;
	
	kiss_label label_title;

} menu_selectgame;


typedef struct menu_options : Menu
{
	
	kiss_button button_back;
	
	kiss_label label_title;

} menu_options;


typedef struct menu_about : Menu
{
	
	kiss_button button_back;
	
	kiss_window scroll_view;
	kiss_vscrollbar scrollbar;
	
	kiss_label label_title;
	kiss_label label_preamble_top;
	kiss_label label_preamble_bottom;
	
	kiss_label label_twocatstudios;
	kiss_label label_team_michaelb;
	kiss_label label_team_janh;
	
	kiss_label label_thanksto;
	kiss_label label_supporters_bleikur;
	kiss_label label_supporters_tarvok;

} menu_about;


class RenderingManager
{

public:
	kiss_array objects;
	
	enum MenuState {NONE = 0, MAINMENU = 1, SELECTGAME = 2, OPTIONS = 3, ABOUT = 4};
	MenuState menuState = NONE;
	
	menu_main mainMenu;
	menu_selectgame selectgameMenu;
	menu_options optionsMenu;
	menu_about aboutMenu;
	
	int draw = 1;
	
	int InitializeKISS ();
	std::string GetApplicationPath ();
	std::string GetResourcesPath ();
	std::string GetPreferencesPath ();
	
	bool IsRetinaDisplay ();
	
	void CalculateAboutMenuPositionsY ();
	
	void Update ();
	void Stop ();

private:
	SDL_Renderer *m_renderer;
	
	std::string m_applicationPath;
	std::string m_resourcesPath;
	std::string m_preferencesPath;
	
	unsigned int m_retinaDisplay = -1;
	
	int m_AddExternalAssets (kiss_array *a, bool high_dpi);
	
	int m_CreateMainMenu ();
	int m_CreateSelectGameMenu ();
	int m_CreateOptionsMenu ();
	int m_CreateAboutMenu ();
	
	void m_DrawMainMenu ();
	void m_DrawSelectGameMenu ();
	void m_DrawOptionsMenu ();
	void m_DrawAboutMenu ();
	
	
	enum ExternalImageAssets {
		EA_KISS_BAR = 0,
		EA_VSLIDER_HANDLE = 1,
		EA_KISS_HSLIDER = 2,
		EA_VSLIDER_UP = 3,
		EA_VSLIDER_DOWN = 4,
		EA_KISS_LEFT = 5,
		EA_KISS_RIGHT = 6,
		EA_KISS_SELECTED = 7,
		EA_KISS_UNSELECTED = 8,
		EA_FONT_ANSON_REGULAR = 9,
		EA_BACKGROUND = 10,
		EA_GLOBE_SLICE = 11,
		EA_HORIZONTAL_BAR = 12,
		EA_BUTTON_NORMAL = 13,
		EA_BUTTON_PRELIGHT = 14,
		EA_BUTTON_ACTIVE = 15
	};
	
	
	int m_buttonPadding = 12;
	int m_labelPadding = 15;
	
	kiss_font m_font_title, m_font_subtitle;
	int m_font_title_size = 200; /*128;*/
	int m_font_subtitle_size = 48; /*24;*/
	kiss_image m_background, m_globe_slice, m_horizontal_bar;
};

#endif /* end of include guard: RENDERINGMANAGER_H */
