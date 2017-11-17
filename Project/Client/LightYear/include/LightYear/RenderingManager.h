#ifndef RENDERINGMANAGER_H
#define RENDERINGMANAGER_H

#include "Global.h"
#include "kiss_sdl.h"
#include "LocalizationManager.h"

#include <iostream>
#include <string>


class RenderingManager;


class Menu
{

public:
	friend struct menu_main;
	friend struct menu_selectgame;
	friend struct menu_options;
	friend struct menu_about;
	
	bool created = false;
	virtual const std::string name () { return "Null"; }
	
	kiss_array *gui_objects_array ();
	kiss_window window;
	
	virtual int Create (LocalizationManager &localizationManager, int &draw);
	
private:
	kiss_array m_gui_objects;
	
	void m_hideMenu ();
};


typedef struct menu_main : Menu
{
	
	const std::string name () { return "Main Menu"; }
	
	kiss_label label_version;
	kiss_label label_title;
	kiss_label label_subtitle;
	
	kiss_window scroll_view;
	kiss_button button_playGame;
	kiss_button button_options;
	kiss_button button_about;
	kiss_button button_quit;
	
	float scroll_view_starting_x;
	float scroll_view_starting_y;
	
	int Create (LocalizationManager &localizationManager, int &draw);

} menu_main;


typedef struct menu_selectgame : Menu
{
	
	const std::string name () { return "Select Game Menu"; }
	
	kiss_button button_back;
	
	int Create (LocalizationManager &localizationManager, int &draw);

} menu_selectgame;


typedef struct menu_options : Menu
{
	
	const std::string name () { return "Options Menu"; }
	
	kiss_button button_back;
	
	kiss_label label_title;
	kiss_label label_test;
	
	int Create (LocalizationManager &localizationManager, int &draw);

} menu_options;


typedef struct menu_about : Menu
{
	
	const std::string name () { return "About Menu"; }
	
	kiss_button button_back;
	
	kiss_window scroll_view;
	kiss_vscrollbar scrollbar;
	
	kiss_label label_title;
	kiss_label label_preamble_top;
	kiss_label label_preamble_bottom;
	
	kiss_label label_twocatstudios;
	SDL_Rect rect_team;
	kiss_label label_team_michaelb;
	kiss_label label_team_janh;
	
	kiss_label label_thanksto;
	SDL_Rect rect_thirdparty;
	kiss_label label_supporters_bleikur;
	kiss_label label_supporters_tarvok;
	
	int Create (LocalizationManager &localizationManager, int &draw);

} menu_about;


class RenderingManager
{

public:
	LocalizationManager *localizationManager;
	
	kiss_array objects;
	
	enum MenuState {NONE = 0, MAINMENU = 1, SELECTGAME = 2, OPTIONS = 3, ABOUT = 4};
	MenuState menuState = NONE;
	
	menu_main mainMenu;
	menu_selectgame selectgameMenu;
	menu_options optionsMenu;
	menu_about aboutMenu;
	
	int draw = YES;
	
	int InitializeKISS ();
	
	bool IsRetinaDisplay (const bool force_recalculate);
	
	void CalculateAboutMenuPositionsY ();
	void CalculateMainMenuPositionsY ();
	
	void Update ();
	void Stop ();

private:
	SDL_Renderer *m_renderer;
	
	int m_retinaDisplay = -1;
	float m_dpi_difference = -1;
	
	int m_AddExternalAssets (kiss_array *a);
	std::string m_appendAssetWithAt2X (const std::string original);
	
	void m_DrawMenu (Menu &menu);
	
	
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
		EA_GLOBE_SLICE = 10,
		EA_BUTTON_NORMAL = 11,
		EA_BUTTON_PRELIGHT = 12,
		EA_BUTTON_ACTIVE = 13
	};
	
	int m_globe_slice_y_position = 0;
};


/*Static Global Variables*/
static RenderingManager *renderingManager;

static const char VERSION[7] = {"0.0.4d"};

static SDL_Color lightYear_black = {25, 33, 39, 255};

static int button_padding = 12;
static int label_padding = 15;

static int horizontalbar_width = 285;

static kiss_font font_title, font_subtitle;
static int font_title_size = 168;
static int font_subtitle_size = 36;
static kiss_image background, globe_slice, horizontal_bar;
/*-----------------------*/

#endif /* end of include guard: RENDERINGMANAGER_H */
