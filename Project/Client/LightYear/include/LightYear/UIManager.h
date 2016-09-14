#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Global.h"
#include "LocalizationManager.h"

#include <string>


SDL_Color lightYear_black = {25, 33, 39, 255};
int button_padding = 12;
int label_padding = 15;

kiss_font font_title, font_subtitle;
int font_title_size = 168;
int font_subtitle_size = 36;
kiss_image background, horizontal_bar;


class Menu
{

public:
	friend struct menu_main;
	friend struct menu_selectgame;
	friend struct menu_options;
	friend struct menu_about;
	
	bool created = false;
	
	kiss_array *gui_objects_array ();
	kiss_window window;
	
	virtual void Create (LocalizationManager &localizationManager, int &draw);
	
private:
	kiss_array m_gui_objects;
	
	void m_hideMenu ();
};


typedef struct menu_main : Menu
{
	
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
	
	void Create (LocalizationManager &localizationManager, int &draw);

} menu_main;


typedef struct menu_selectgame : Menu
{
	
	kiss_button button_back;
	
	kiss_label label_title;
	
	void Create (LocalizationManager &localizationManager, int &draw);

} menu_selectgame;


typedef struct menu_options : Menu
{
	
	kiss_button button_back;
	
	kiss_label label_title;
	
	void Create (LocalizationManager &localizationManager, int &draw);

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
	
	void Create (LocalizationManager &localizationManager, int &draw);

} menu_about;


class UIManager
{
public:
	enum MenuState {NONE = 0, MAINMENU = 1, SELECTGAME = 2, OPTIONS = 3, ABOUT = 4};
	MenuState menuState = MAINMENU;
	
	menu_main mainMenu;
	menu_selectgame selectgameMenu;
	menu_options optionsMenu;
	menu_about aboutMenu;
	
	kiss_array objects;
	
	int globe_slice_y_position = 0;
	kiss_image globe_slice;
	
	void DrawMainMenu ();
	void DrawSelectGameMenu ();
	void DrawOptionsMenu ();
	void DrawAboutMenu ();
	
	void RefreshWindows ();
	
	void CalculateAboutMenuPositionsY ();
	void CalculateMainMenuPositionsY ();
	
	int AddExternalAssets (kiss_array *a);

private:
	std::string m_appendAssetWithAt2X (const std::string original);
	
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
		EA_HORIZONTAL_BAR = 11,
		EA_BUTTON_NORMAL = 12,
		EA_BUTTON_PRELIGHT = 13,
		EA_BUTTON_ACTIVE = 14
	};
};

#endif /* end of include guard: UIMANAGER_H */
