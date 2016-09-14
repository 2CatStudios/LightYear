#include "UIManager.h"


//TODO: FIX THIS (cannot return NULL, this will cause crashes)
kiss_array *Menu::gui_objects_array ()
{
	
	if (created == false)
		//Create (*renderingManager->localizationManager, renderingManager->draw);
		return NULL;
	
	return &m_gui_objects;
}


void menu_main::Create (LocalizationManager &localizationManager, int &draw)
{
	
	if (created == false)
	{
	
		kiss_array_new (&m_gui_objects);
	
		kiss_window_new (&window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		window.bg = lightYear_black;
		kiss_array_append (&m_gui_objects, 0, &window);
		
		kiss_label_new (
			&label_version,
			&window,
			const_cast<char*> (VERSION),
			window.rect.x + 4,
			window.rect.y + 0
				);
		label_version.textcolor = kiss_white;
		label_version.font = kiss_textfont;
		kiss_array_append (&m_gui_objects, 1, &label_version);
		
		kiss_label_new (
			&label_title,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_LIGHTYEAR).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_textwidth (font_title, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_LIGHTYEAR).c_str ()), NULL) / 2)),
			window.rect.y + 10
				);
		label_title.textcolor = kiss_white;
		label_title.font = font_title;
		kiss_array_append (&m_gui_objects, 2, &label_title);
		
		kiss_label_new (
			&label_subtitle,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD).c_str ()), NULL) / 2)),
			label_title.rect.y + font_title.fontheight
				);
		label_subtitle.textcolor = kiss_white;
		label_subtitle.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 3, &label_subtitle);
		
		
		const int TOTAL_MENU_BUTTONS = 4;
		const int SCROLLVIEW_WIDTH = (kiss_normal.w + button_padding);
		const int SCROLLVIEW_HEIGHT = ((kiss_normal.h * TOTAL_MENU_BUTTONS) + button_padding * TOTAL_MENU_BUTTONS);
		
		scroll_view_starting_x = kiss_screen_width / 2 - SCROLLVIEW_WIDTH / 2;
		scroll_view_starting_y = label_subtitle.rect.y + font_subtitle_size + button_padding;
		
		kiss_window_new (&scroll_view, NULL, 0, 0, scroll_view_starting_x, scroll_view_starting_y, SCROLLVIEW_WIDTH, SCROLLVIEW_HEIGHT);
		scroll_view.bg = kiss_white;
		kiss_array_append (&m_gui_objects, 4, &scroll_view);
		
		kiss_button_new (
			&button_playGame,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_PLAY).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			scroll_view.rect.y + button_padding / 2
				);
		button_playGame.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 5, &button_playGame);
		
		kiss_button_new (
			&button_options,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_OPTIONS).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			button_playGame.rect.y + button_playGame.rect.h + button_padding
				);
		button_options.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 6, &button_options);
		
		kiss_button_new (
			&button_about,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_ABOUT).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			button_options.rect.y + button_options.rect.h + button_padding
				);
		button_about.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 7, &button_about);
		
		kiss_button_new (
			&button_quit,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_QUIT).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			button_about.rect.y + button_about.rect.h + button_padding
				);
		button_quit.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 8, &button_quit);
		
		created = true;
		draw = 1;
	}
}


void menu_selectgame::Create (LocalizationManager &localizationManager, int &draw)
{
	
	if (created == false)
	{
		
		kiss_array_new (&m_gui_objects);
		
		kiss_window_new (&window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		window.bg = lightYear_black;
		kiss_array_append (&m_gui_objects, 0, &window);
		
		kiss_button_new (
			&button_back,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_RETURN).c_str ()),
			window.rect.x + button_padding,
			window.rect.y + button_padding
				);
		button_back.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 1, &button_back);
		
		created = true;
		draw = 1;
	}
}


void menu_options::Create (LocalizationManager &localizationManager, int &draw)
{
	
	if (created == false)
	{
		
		kiss_array_new (&m_gui_objects);
		
		kiss_window_new (&window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		window.bg = lightYear_black;
		kiss_array_append (&m_gui_objects, 0, &window);
		
		kiss_button_new (
			&button_back,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_RETURN).c_str ()),
			window.rect.x + button_padding,
			window.rect.y + button_padding
				);
		button_back.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 1, &button_back);
		
		
		kiss_label_new (
			&label_title,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::OPTIONS, LocalizationManager::O_OPTIONS).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_textwidth (font_title, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::OPTIONS, LocalizationManager::O_OPTIONS).c_str ()), NULL) / 2)),
			window.rect.y + 10
				);
		label_title.textcolor = kiss_white;
		label_title.font = font_title;
		kiss_array_append (&m_gui_objects, 2, &label_title);
		
		created = true;
		draw = 1;
	}
}


void menu_about::Create (LocalizationManager &localizationManager, int &draw)
{
	
	if (created == false)
	{
		
		kiss_array_new (&m_gui_objects);
		
		kiss_window_new (&window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		window.bg = lightYear_black;
		kiss_array_append (&m_gui_objects, 0, &window);
		
		kiss_button_new (
			&button_back,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_RETURN).c_str ()),
			window.rect.x + button_padding,
			window.rect.x + button_padding
				);
		button_back.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, 1, &button_back);
		
		
		int titleWidth = kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE).c_str ()), NULL);
		kiss_window_new (&scroll_view, NULL, 0, 0, (window.rect.w / 2) - (titleWidth / 2) - 10, 0, titleWidth + 20, 770);
		kiss_array_append (&m_gui_objects, 2, &scroll_view);
		
		kiss_vscrollbar_new (&scrollbar, &window, (window.rect.w / 2) + (titleWidth / 2) + 20, (window.rect.h / 2) - 175, 350);
		kiss_array_append (&m_gui_objects, 3, &scrollbar);
		
		
		kiss_label_new (
			&label_title,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_ABOUT).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_title, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_ABOUT).c_str ()), NULL) / 2)),
			scroll_view.rect.y + 10
				);
		label_title.textcolor = kiss_white;
		label_title.font = font_title;
		kiss_array_append (&m_gui_objects, 4, &label_title);

		kiss_label_new (
			&label_preamble_top,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (titleWidth / 2)),
			label_title.rect.y + font_title.fontheight
				);
		label_preamble_top.textcolor = kiss_white;
		label_preamble_top.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 5, &label_preamble_top);
		
		kiss_label_new (
			&label_preamble_bottom,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_HAS_BEEN_LOVINGLY_CREATED_BY).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_HAS_BEEN_LOVINGLY_CREATED_BY).c_str ()), NULL) / 2)),
			label_preamble_top.rect.y + font_subtitle.fontheight
				);
		label_preamble_bottom.textcolor = kiss_white;
		label_preamble_bottom.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 6, &label_preamble_bottom);
		
		kiss_label_new (
			&label_twocatstudios,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_2CATSTUDIOS).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_2CATSTUDIOS).c_str ()), NULL) / 2)),
			label_preamble_bottom.rect.y + font_subtitle.fontheight + label_padding
				);
		label_twocatstudios.textcolor = kiss_white;
		label_twocatstudios.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 7, &label_twocatstudios);
		
		
		kiss_label_new (
			&label_team_michaelb,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_MICHAEL_BETHKE_LEAD_DEVELOPER).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_MICHAEL_BETHKE_LEAD_DEVELOPER).c_str ()), NULL) / 2)),
			label_twocatstudios.rect.y + font_subtitle.fontheight + label_padding
				);
		label_team_michaelb.textcolor = kiss_white;
		label_team_michaelb.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 8, &label_team_michaelb);
		
		kiss_label_new (
			&label_team_janh,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT).c_str ()), NULL) / 2)),
			label_team_michaelb.rect.y + font_subtitle.fontheight
				);
		label_team_janh.textcolor = kiss_white;
		label_team_janh.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 9, &label_team_janh);
		
		
		kiss_label_new (
			&label_thanksto,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_WITH_THANKS_TO).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_WITH_THANKS_TO).c_str ()), NULL) / 2)),
			label_team_janh.rect.y + (font_subtitle.fontheight * 2)
				);
		label_thanksto.textcolor = kiss_white;
		label_thanksto.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 10, &label_thanksto);
		
		kiss_label_new (
			&label_supporters_bleikur,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_BLEIKUR_DESIGN_AND_FEEDBACK).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_BLEIKUR_DESIGN_AND_FEEDBACK).c_str ()), NULL) / 2)),
			label_thanksto.rect.y + font_subtitle.fontheight
				);
		label_supporters_bleikur.textcolor = kiss_white;
		label_supporters_bleikur.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 11, &label_supporters_bleikur);
		
		kiss_label_new (
			&label_supporters_tarvok,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_TARVO_KORROVITS_KISS_SDL).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_TARVO_KORROVITS_KISS_SDL).c_str ()), NULL) / 2)),
			label_supporters_bleikur.rect.y + font_subtitle.fontheight
				);
		label_supporters_tarvok.textcolor = kiss_white;
		label_supporters_tarvok.font = font_subtitle;
		kiss_array_append (&m_gui_objects, 12, &label_supporters_tarvok);
		
		created = true;
		draw = 1;
	}
}


void Menu::Create (LocalizationManager &localizationManager, int &draw) {}


void UIManager::DrawMainMenu ()
{
	
	if (mainMenu.created == false)
		mainMenu.Create (*localizationManager, draw);
	
	mainMenu.window.visible = 1;
	kiss_window_draw (&mainMenu.window, m_renderer);
	kiss_label_draw (&mainMenu.label_version, m_renderer);
	kiss_label_draw (&mainMenu.label_title, m_renderer);
	kiss_label_draw (&mainMenu.label_subtitle, m_renderer);
	
	mainMenu.scroll_view.visible = 1;
	kiss_window_draw (&mainMenu.scroll_view, m_renderer);
	kiss_button_draw (&mainMenu.button_playGame, m_renderer);
	kiss_button_draw (&mainMenu.button_options, m_renderer);
	kiss_button_draw (&mainMenu.button_about, m_renderer);
	kiss_button_draw (&mainMenu.button_quit, m_renderer);
}


void UIManager::DrawSelectGameMenu ()
{
	
	if (selectgameMenu.created == false)
		selectgameMenu.Create (*localizationManager, draw);
	
	selectgameMenu.window.visible = 1;
	kiss_window_draw (&selectgameMenu.window, m_renderer);
	
	kiss_button_draw (&selectgameMenu.button_back, m_renderer);
}


void UIManager::DrawOptionsMenu ()
{
	
	if (optionsMenu.created == false)
		optionsMenu.Create (*localizationManager, draw);
	
	optionsMenu.window.visible = 1;
	kiss_window_draw (&optionsMenu.window, m_renderer);
	
	kiss_button_draw (&optionsMenu.button_back, m_renderer);
	kiss_label_draw (&optionsMenu.label_title, m_renderer);
}


void UIManager::DrawAboutMenu ()
{
	
	if (aboutMenu.created == false)
		aboutMenu.Create (*localizationManager, draw);
	
	aboutMenu.window.visible = 1;
	kiss_window_draw (&aboutMenu.window, m_renderer);
	
	kiss_button_draw (&aboutMenu.button_back, m_renderer);
	
	aboutMenu.scroll_view.visible = 1;
	kiss_window_draw (&aboutMenu.scroll_view, m_renderer);
	kiss_vscrollbar_draw (&aboutMenu.scrollbar, m_renderer);
	
	kiss_label_draw (&aboutMenu.label_title, m_renderer);
	kiss_label_draw (&aboutMenu.label_preamble_top, m_renderer);
	kiss_label_draw (&aboutMenu.label_preamble_bottom, m_renderer);
	
	kiss_label_draw (&aboutMenu.label_twocatstudios, m_renderer);
	kiss_renderimage (m_renderer, horizontal_bar, aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (284 / 2)), aboutMenu.label_twocatstudios.rect.y + font_subtitle.fontheight, NULL);
	kiss_label_draw (&aboutMenu.label_team_michaelb, m_renderer);
	kiss_label_draw (&aboutMenu.label_team_janh, m_renderer);
	
	kiss_label_draw (&aboutMenu.label_thanksto, m_renderer);
	kiss_renderimage (m_renderer, horizontal_bar, aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (284 / 2)), aboutMenu.label_thanksto.rect.y + font_subtitle.fontheight, NULL);
	kiss_label_draw (&aboutMenu.label_supporters_bleikur, m_renderer);
	kiss_label_draw (&aboutMenu.label_supporters_tarvok, m_renderer);
}


void UIManager::RefreshWindows ()
{
	
	mainMenu.window.visible = 0;
	selectgameMenu.window.visible = 0;
	optionsMenu.window.visible = 0;
	aboutMenu.window.visible = 0;
	aboutMenu.scroll_view.visible = 0;
}


//TODO: Make generic
void UIManager::CalculateAboutMenuPositionsY ()
{

	//TODO: DRY
	aboutMenu.label_title.rect.y = aboutMenu.scroll_view.rect.y + 10;
	aboutMenu.label_preamble_top.rect.y = aboutMenu.label_title.rect.y + font_title.fontheight;
	aboutMenu.label_preamble_bottom.rect.y = aboutMenu.label_preamble_top.rect.y + font_subtitle.fontheight;
	aboutMenu.label_twocatstudios.rect.y = aboutMenu.label_preamble_bottom.rect.y + font_subtitle.fontheight + label_padding;
	aboutMenu.label_team_michaelb.rect.y = aboutMenu.label_twocatstudios.rect.y + font_subtitle.fontheight + label_padding;
	aboutMenu.label_team_janh.rect.y = aboutMenu.label_team_michaelb.rect.y + font_subtitle.fontheight;
	aboutMenu.label_thanksto.rect.y = aboutMenu.label_team_janh.rect.y + (font_subtitle.fontheight * 2);
	aboutMenu.label_supporters_bleikur.rect.y = aboutMenu.label_thanksto.rect.y + font_subtitle.fontheight;
	aboutMenu.label_supporters_tarvok.rect.y = aboutMenu.label_supporters_bleikur.rect.y + font_subtitle.fontheight;
}


void UIManager::CalculateMainMenuPositionsY ()
{
	
	mainMenu.button_playGame.rect.y = mainMenu.scroll_view.rect.y + button_padding / 2;
	mainMenu.button_playGame.texty = mainMenu.button_playGame.rect.y + mainMenu.button_playGame.normalimg.h / 2 - mainMenu.button_playGame.font.fontheight / 2;
	
	mainMenu.button_options.rect.y = mainMenu.button_playGame.rect.y + mainMenu.button_playGame.rect.h + button_padding;
	mainMenu.button_options.texty = mainMenu.button_options.rect.y + mainMenu.button_options.normalimg.h / 2 - mainMenu.button_options.font.fontheight / 2;
	
	mainMenu.button_about.rect.y = mainMenu.button_options.rect.y + mainMenu.button_options.rect.h + button_padding;
	mainMenu.button_about.texty = mainMenu.button_about.rect.y + mainMenu.button_about.normalimg.h / 2 - mainMenu.button_about.font.fontheight / 2;
	
	mainMenu.button_quit.rect.y = mainMenu.button_about.rect.y + mainMenu.button_about.rect.h + button_padding;
	mainMenu.button_quit.texty = mainMenu.button_quit.rect.y + mainMenu.button_quit.normalimg.h / 2 - mainMenu.button_quit.font.fontheight / 2;
}


std::string UIManager::m_appendAssetWithAt2X (const std::string original)
{
	
	std::string twoXVersion = original;
	twoXVersion.insert (original.find_last_of ('.'), "@2x");
	return twoXVersion;
}


int UIManager::m_AddExternalAssets (kiss_array *a)
{
	
	//TODO: (re)Move me!
	const unsigned int TOTAL_ASSETS = 15;
	std::string assets[TOTAL_ASSETS] = {
		"kiss_bar.png",
		"vslider_handle.png",
		"kiss_hslider.png",
		"vslider_up.png",
		"vslider_down.png",
		"kiss_left.png",
		"kiss_right.png",
		"kiss_selected.png",
		"kiss_unselected.png",
		"font_anson_regular.ttf",
		"globe_slice.png",
		"horizontal_bar.png",
		"button_normal.png",
		"button_prelight.png",
		"button_active.png"
	};
	
	
	/*Default Assets*/
	//TODO: Replace eventually
	kiss_image_new(&kiss_bar, const_cast<char*> (assets[EA_KISS_BAR].c_str ()), a, m_renderer);
	kiss_image_new(&kiss_hslider, const_cast<char*> (assets[EA_KISS_HSLIDER].c_str ()), a, m_renderer);
	kiss_image_new(&kiss_left, const_cast<char*> (assets[EA_KISS_LEFT].c_str ()), a, m_renderer);
	kiss_image_new(&kiss_right, const_cast<char*> (assets[EA_KISS_RIGHT].c_str ()), a, m_renderer);
	kiss_image_new(&kiss_selected, const_cast<char*> (assets[EA_KISS_SELECTED].c_str ()), a, m_renderer);
	kiss_image_new(&kiss_unselected, const_cast<char*> (assets[EA_KISS_UNSELECTED].c_str ()), a, m_renderer);
	
	/*Custom 1X Assets*/
	kiss_font_new(&kiss_textfont, const_cast<char*> (assets[EA_FONT_ANSON_REGULAR].c_str ()), a, kiss_textfont_size);
	kiss_font_new(&kiss_buttonfont, const_cast<char*> (assets[EA_FONT_ANSON_REGULAR].c_str ()), a, kiss_buttonfont_size);
	kiss_font_new (&font_title, const_cast<char*> (assets[EA_FONT_ANSON_REGULAR].c_str ()), a, font_title_size);
	kiss_font_new (&font_subtitle, const_cast<char*> (assets[EA_FONT_ANSON_REGULAR].c_str ()), a, font_subtitle_size);

	/*Custom 2X Assets*/
	if (IsRetinaDisplay () == true)
	{
		
		const int DPI_DIFFERENCE = 
		
		kiss_textfont_size *= m_dpi_difference;
		kiss_buttonfont_size *= m_dpi_difference;
		font_title_size *= m_dpi_difference;
		font_subtitle_size *= m_dpi_difference;
		button_padding *= m_dpi_difference;
		
		const int CUSTOM_2X_ASSET_ARRAY_STARTING_POSITION = 10;
		for (int index = CUSTOM_2X_ASSET_ARRAY_STARTING_POSITION; index < TOTAL_ASSETS; index += 1)
		{
			
			assets[index] = m_appendAssetWithAt2X (assets[index]);
		}
	}

	kiss_image_new (&kiss_vslider, const_cast<char*> (assets[EA_VSLIDER_HANDLE].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_up, const_cast<char*> (assets[EA_VSLIDER_UP].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_down, const_cast<char*> (assets[EA_VSLIDER_DOWN].c_str ()), a, m_renderer);
	kiss_image_new (&horizontal_bar, const_cast<char*> (assets[EA_HORIZONTAL_BAR].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_normal, const_cast<char*> (assets[EA_BUTTON_NORMAL].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_prelight, const_cast<char*> (assets[EA_BUTTON_PRELIGHT].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_active, const_cast<char*> (assets[EA_BUTTON_ACTIVE].c_str ()), a, m_renderer);
	kiss_image_new (&globe_slice, const_cast<char*> (assets[EA_GLOBE_SLICE].c_str ()), a, m_renderer);
	m_globe_slice_y_position = kiss_screen_height - globe_slice.h;
	
	return 0;
}