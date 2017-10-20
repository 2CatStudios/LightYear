#include "RenderingManager.h"

kiss_array *Menu::gui_objects_array ()
{
	
	if (created == false)
		Create (*renderingManager->localizationManager, renderingManager->draw);
	
	return &m_gui_objects;
}


void menu_main::Create (LocalizationManager &localizationManager, int &draw)
{
	
	if (created == false)
	{
	
		kiss_array_new (&m_gui_objects);
	
		kiss_window_new (&window, NULL, NO, YES, 0, 0, kiss_screen_width, kiss_screen_height);
		window.bg = lightYear_black;
		kiss_array_append (&m_gui_objects, GUI_WINDOW, &window); /* Index: 0 */
		
		kiss_label_new (
			&label_version,
			&window,
			const_cast<char*> (VERSION),
			window.rect.x + 4,
			window.rect.y + 0
				);
		label_version.textcolor = kiss_white;
		label_version.font = kiss_textfont;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_version); /* Index: 1 */
		
		kiss_label_new (
			&label_title,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_LIGHTYEAR).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_textwidth (font_title, const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_LIGHTYEAR).c_str ()), NULL) / 2)),
			window.rect.y + 10
				);
		label_title.textcolor = kiss_white;
		label_title.font = font_title;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_title); /* Index: 2 */
		
		kiss_label_new (
			&label_subtitle,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD).c_str ()), NULL) / 2)),
			label_title.rect.y + font_title.fontheight
				);
		label_subtitle.textcolor = kiss_white;
		label_subtitle.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_subtitle); /* Index: 3 */
		
		
		const int TOTAL_MENU_BUTTONS = 4;
		const int SCROLLVIEW_WIDTH = (kiss_normal.w + button_padding);
		const int SCROLLVIEW_HEIGHT = ((kiss_normal.h * TOTAL_MENU_BUTTONS) + button_padding * TOTAL_MENU_BUTTONS);
		
		scroll_view_starting_x = kiss_screen_width / 2 - SCROLLVIEW_WIDTH / 2;
		scroll_view_starting_y = label_subtitle.rect.y + font_subtitle_size + button_padding;
		
		kiss_window_new (&scroll_view, NULL, NO, NO, scroll_view_starting_x, scroll_view_starting_y, SCROLLVIEW_WIDTH, SCROLLVIEW_HEIGHT);
		scroll_view.bg = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_WINDOW, &scroll_view); /* Index: 4 */
		
		kiss_button_new (
			&button_playGame,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (MAINMENU, LocalizationManager::MM_PLAY).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			scroll_view.rect.y + button_padding / 2
				);
		button_playGame.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_playGame); /* Index: 5 */
		
		kiss_button_new (
			&button_options,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (MAINMENU, LocalizationManager::MM_OPTIONS).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			button_playGame.rect.y + button_playGame.rect.h + button_padding
				);
		button_options.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_options); /* Index: 6 */
		
		kiss_button_new (
			&button_about,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (MAINMENU, LocalizationManager::MM_ABOUT).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			button_options.rect.y + button_options.rect.h + button_padding
				);
		button_about.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_about); /* Index: 7 */
		
		kiss_button_new (
			&button_quit,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (MAINMENU, LocalizationManager::MM_QUIT).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_normal.w / 2)),
			button_about.rect.y + button_about.rect.h + button_padding
				);
		button_quit.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_quit); /* Index: 8 */
		
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
		kiss_array_append (&m_gui_objects, GUI_WINDOW, &window); /* Index: 0 */
		
		kiss_button_new (
			&button_back,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_RETURN).c_str ()),
			window.rect.x + button_padding,
			window.rect.y + button_padding
				);
		button_back.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_back); /* Index: 1 */
		
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
		kiss_array_append (&m_gui_objects, GUI_WINDOW, &window); /* Index: 0 */
		
		kiss_button_new (
			&button_back,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_RETURN).c_str ()),
			window.rect.x + button_padding,
			window.rect.y + button_padding
				);
		button_back.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_back); /* Index: 1 */
		
		
		kiss_label_new (
			&label_title,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (OPTIONS, LocalizationManager::O_OPTIONS).c_str ()),
			window.rect.x + ((window.rect.w / 2) - (kiss_textwidth (font_title, const_cast<char*> (localizationManager.GetLocalizedApplicationText (OPTIONS, LocalizationManager::O_OPTIONS).c_str ()), NULL) / 2)),
			window.rect.y + 10
				);
		label_title.textcolor = kiss_white;
		label_title.font = font_title;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_title); /* Index: 2 */
		
		created = true;
		draw = 1;
	}
}


void menu_about::Create (LocalizationManager &localizationManager, int &draw)
{
	
	if (created == false)
	{
		
		kiss_array_new (&m_gui_objects);
		
		kiss_window_new (&window, NULL, NO, YES, 0, 0, kiss_screen_width, kiss_screen_height);
		window.bg = lightYear_black;
		kiss_array_append (&m_gui_objects, GUI_WINDOW, &window); /* Index: 0 */
		
		kiss_button_new (
			&button_back,
			&window,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (GENERAL, LocalizationManager::G_RETURN).c_str ()),
			window.rect.x + button_padding,
			window.rect.x + button_padding
				);
		button_back.textcolor = kiss_white;
		kiss_array_append (&m_gui_objects, GUI_BUTTON, &button_back); /* Index: 1 */
		
		
		int titleWidth = kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE).c_str ()), NULL);
		kiss_window_new (&scroll_view, NULL, NO, NO, (window.rect.w / 2) - (titleWidth / 2) - 10, 0, titleWidth + 20, 770);
		kiss_array_append (&m_gui_objects, GUI_WINDOW, &scroll_view); /* Index: 2 */
		
		kiss_vscrollbar_new (&scrollbar, &window, (window.rect.w / 2) + (titleWidth / 2) + 20, (window.rect.h / 2) - 175, 350);
		kiss_array_append (&m_gui_objects, GUI_VSCROLLBAR, &scrollbar); /* Index: 3 */
		
		/*HEADER*/
		kiss_label_new (
			&label_title,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_ABOUT).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_title, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_ABOUT).c_str ()), NULL) / 2)),
			scroll_view.rect.y + 10
				);
		label_title.textcolor = kiss_white;
		label_title.font = font_title;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_title); /* Index: 4 */

		kiss_label_new (
			&label_preamble_top,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (titleWidth / 2)),
			label_title.rect.y + font_title.fontheight
				);
		label_preamble_top.textcolor = kiss_white;
		label_preamble_top.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_preamble_top); /* Index: 5 */
		
		kiss_label_new (
			&label_preamble_bottom,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_HAS_BEEN_LOVINGLY_CREATED_BY).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_HAS_BEEN_LOVINGLY_CREATED_BY).c_str ()), NULL) / 2)),
			label_preamble_top.rect.y + font_subtitle.fontheight
				);
		label_preamble_bottom.textcolor = kiss_white;
		label_preamble_bottom.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_preamble_bottom); /* Index: 6 */
		
		
/*2Cat Studios*/
		kiss_label_new (
			&label_twocatstudios,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_2CATSTUDIOS).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_2CATSTUDIOS).c_str ()), NULL) / 2)),
			label_preamble_bottom.rect.y + font_subtitle.fontheight + label_padding
				);
		label_twocatstudios.textcolor = kiss_white;
		label_twocatstudios.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_twocatstudios); /* Index: 7 */
		
		rect_team.w = scroll_view.rect.x / 2;
		rect_team.h = 2;
		rect_team.x = scroll_view.rect.x + ((scroll_view.rect.w / 2) - (rect_team.w / 2));
		rect_team.y = label_twocatstudios.rect.y + font_subtitle.fontheight;
		kiss_array_append (&m_gui_objects, GUI_SOLIDRECT, &rect_team); /* Index: 8 */
		
		kiss_label_new (
			&label_team_michaelb,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_MICHAEL_BETHKE_LEAD_DEVELOPER).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_MICHAEL_BETHKE_LEAD_DEVELOPER).c_str ()), NULL) / 2)),
			label_twocatstudios.rect.y + font_subtitle.fontheight + label_padding
				);
		label_team_michaelb.textcolor = kiss_white;
		label_team_michaelb.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_team_michaelb); /* Index: 9 */
		
		kiss_label_new (
			&label_team_janh,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT).c_str ()), NULL) / 2)),
			label_team_michaelb.rect.y + font_subtitle.fontheight
				);
		label_team_janh.textcolor = kiss_white;
		label_team_janh.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_team_janh); /* Index: 10 */
		
/*THIRD PARTY*/		
		kiss_label_new (
			&label_thanksto,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_WITH_THANKS_TO).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_WITH_THANKS_TO).c_str ()), NULL) / 2)),
			label_team_janh.rect.y + (font_subtitle.fontheight * 2)
				);
		label_thanksto.textcolor = kiss_white;
		label_thanksto.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_thanksto); /* Index: 11 */
		
		rect_thirdparty.w = scroll_view.rect.x / 2;
		rect_thirdparty.h = 2;
		rect_thirdparty.x = scroll_view.rect.x + ((scroll_view.rect.w / 2) - (rect_thirdparty.w / 2));
		rect_thirdparty.y = label_thanksto.rect.y + font_subtitle.fontheight;
		kiss_array_append (&m_gui_objects, GUI_SOLIDRECT, &rect_thirdparty); /* Index: 12 */
		
		kiss_label_new (
			&label_supporters_bleikur,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_BLEIKUR_DESIGN_AND_FEEDBACK).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_BLEIKUR_DESIGN_AND_FEEDBACK).c_str ()), NULL) / 2)),
			label_thanksto.rect.y + font_subtitle.fontheight
				);
		label_supporters_bleikur.textcolor = kiss_white;
		label_supporters_bleikur.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_supporters_bleikur); /* Index: 13 */
		
		kiss_label_new (
			&label_supporters_tarvok,
			&scroll_view,
			const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_TARVO_KORROVITS_KISS_SDL).c_str ()),
			scroll_view.rect.x + ((scroll_view.rect.w / 2) - (kiss_textwidth (font_subtitle, const_cast<char*> (localizationManager.GetLocalizedApplicationText (ABOUT, LocalizationManager::A_TARVO_KORROVITS_KISS_SDL).c_str ()), NULL) / 2)),
			label_supporters_bleikur.rect.y + font_subtitle.fontheight
				);
		label_supporters_tarvok.textcolor = kiss_white;
		label_supporters_tarvok.font = font_subtitle;
		kiss_array_append (&m_gui_objects, GUI_LABEL, &label_supporters_tarvok); /* Index: 14 */
		
		created = true;
		draw = 1;
	}
}


void Menu::Create (LocalizationManager &localizationManager, int &draw) {}


int RenderingManager::InitializeKISS ()
{
	
	m_renderer = kiss_init (localizationManager->GetLocalizedApplicationText (GENERAL, LocalizationManager::G_LIGHTYEAR).c_str (), &objects, 1024, 576);
	m_AddExternalAssets (&objects);
	
	renderingManager = this;
	
	return 0;
}


bool RenderingManager::IsRetinaDisplay (const bool force_recalculate = false)
{
	
	if (m_retinaDisplay == -1 || force_recalculate == true)
	{
	
		float diagDPI = -1;
		float horiDPI = -1;
		float vertDPI = -1;
		
		if (SDL_GetDisplayDPI (0, &diagDPI, &horiDPI, &vertDPI) != 0)
		{
			
			std::cout << "Error: " << SDL_GetError () << std::endl;
			m_retinaDisplay = NO;
		}
		
		if (diagDPI - 109 > 0.001)
		{
			
			m_retinaDisplay = YES;
			m_dpi_difference = diagDPI - 109;
		} else if (diagDPI - 109 < 0.001 && diagDPI - 109 > -0.001)
		{
			
			m_retinaDisplay = NO;
		} else {
			
			std::cout << "Unknown DDPI, " << diagDPI << std::endl;
			m_retinaDisplay = NO;
		}
	}
	
	return m_retinaDisplay;
}


std::string RenderingManager::m_appendAssetWithAt2X (const std::string original)
{
	
	std::string twoXVersion = original;
	twoXVersion.insert (original.find_last_of ('.'), "@2x");
	return twoXVersion;
}


int RenderingManager::m_AddExternalAssets (kiss_array *a)
{
	
	//TODO: (re)Move me!
	const unsigned int TOTAL_ASSETS = 14;
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
		"button_normal.png",
		"button_prelight.png",
		"button_active.png"
	};
	
	
	//TODO: DRY
	/*Default Assets*/
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
		
		kiss_textfont_size *= m_dpi_difference;
		kiss_buttonfont_size *= m_dpi_difference;
		font_title_size *= m_dpi_difference;
		font_subtitle_size *= m_dpi_difference;
		button_padding *= m_dpi_difference;
		horizontalbar_width *= m_dpi_difference;
		
		const int CUSTOM_2X_ASSET_ARRAY_STARTING_POSITION = 10;
		for (int index = CUSTOM_2X_ASSET_ARRAY_STARTING_POSITION; index < TOTAL_ASSETS; index += 1)
		{
			
			assets[index] = m_appendAssetWithAt2X (assets[index]);
		}
	}

	kiss_image_new (&kiss_vslider, const_cast<char*> (assets[EA_VSLIDER_HANDLE].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_up, const_cast<char*> (assets[EA_VSLIDER_UP].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_down, const_cast<char*> (assets[EA_VSLIDER_DOWN].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_normal, const_cast<char*> (assets[EA_BUTTON_NORMAL].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_prelight, const_cast<char*> (assets[EA_BUTTON_PRELIGHT].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_active, const_cast<char*> (assets[EA_BUTTON_ACTIVE].c_str ()), a, m_renderer);
	kiss_image_new (&globe_slice, const_cast<char*> (assets[EA_GLOBE_SLICE].c_str ()), a, m_renderer);
	m_globe_slice_y_position = kiss_screen_height - globe_slice.h;
	
	return 0;
}


//TODO: Make generic
void RenderingManager::CalculateMainMenuPositionsY ()
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



//TODO: Make generic
void RenderingManager::CalculateAboutMenuPositionsY ()
{

	aboutMenu.label_title.rect.y = aboutMenu.scroll_view.rect.y + 10;
	aboutMenu.label_preamble_top.rect.y = aboutMenu.label_title.rect.y + font_title.fontheight;
	aboutMenu.label_preamble_bottom.rect.y = aboutMenu.label_preamble_top.rect.y + font_subtitle.fontheight;
	
	aboutMenu.label_twocatstudios.rect.y = aboutMenu.label_preamble_bottom.rect.y + font_subtitle.fontheight + label_padding;
	aboutMenu.rect_team.y = aboutMenu.label_twocatstudios.rect.y + font_subtitle.fontheight;
	aboutMenu.label_team_michaelb.rect.y = aboutMenu.label_twocatstudios.rect.y + font_subtitle.fontheight + label_padding;
	aboutMenu.label_team_janh.rect.y = aboutMenu.label_team_michaelb.rect.y + font_subtitle.fontheight;
	
	aboutMenu.label_thanksto.rect.y = aboutMenu.label_team_janh.rect.y + (font_subtitle.fontheight * 2);
	aboutMenu.rect_thirdparty.y = aboutMenu.label_thanksto.rect.y + font_subtitle.fontheight;
	aboutMenu.label_supporters_bleikur.rect.y = aboutMenu.label_thanksto.rect.y + font_subtitle.fontheight;
	aboutMenu.label_supporters_tarvok.rect.y = aboutMenu.label_supporters_bleikur.rect.y + font_subtitle.fontheight;
}


void RenderingManager::m_DrawMenu (Menu &menu)
{
	
	if (menu.created == false)
	{
		
		menu.Create (*localizationManager, draw);
		std::cout << "Create " << menu.name () << std::endl;
	}
	
	for (int index = 0; index < menu.gui_objects_array ()->length; index += 1)
	{
		
		switch (kiss_array_id (menu.gui_objects_array (), index))
		{
			
			case GUI_WINDOW:
			((kiss_window*) kiss_array_data (menu.gui_objects_array (), index))->visible = 1;
			kiss_window_draw ((kiss_window*) kiss_array_data (menu.gui_objects_array (), index), m_renderer);
			break;
				
			case GUI_LABEL:
			kiss_label_draw ((kiss_label*) kiss_array_data (menu.gui_objects_array (), index), m_renderer);
			break;
			
			case GUI_BUTTON:
			kiss_button_draw ((kiss_button*) kiss_array_data (menu.gui_objects_array (), index), m_renderer);
			break;
			
			case GUI_VSCROLLBAR:
			kiss_vscrollbar_draw ((kiss_vscrollbar*) kiss_array_data (menu.gui_objects_array (), index), m_renderer);
			break;
			
			case GUI_SOLIDRECT:
			kiss_fillrect (m_renderer, (SDL_Rect*) kiss_array_data (menu.gui_objects_array (), index), kiss_white);
			break;
		}
	}
}


void RenderingManager::Update ()
{
	
	if (draw == 0)
		return;
	
	SDL_RenderClear (m_renderer);
	/*mainMenu.window.visible = 0;
	mainMenu.scroll_view.visible = 0;
	selectgameMenu.window.visible = 0;
	optionsMenu.window.visible = 0;
	aboutMenu.window.visible = 0;
	aboutMenu.scroll_view.visible = 0;*/
	
	switch (menuState)
	{
		
		case NONE:
		break;
		
		case MAINMENU:
		m_DrawMenu (mainMenu);
		break;
		
		case SELECTGAME:
		m_DrawMenu (selectgameMenu);
		break;
		
		case OPTIONS:
		m_DrawMenu (optionsMenu);
		break;
		
		case ABOUT:
		m_DrawMenu (aboutMenu);
		break;
		
		default:
		break;
	}
	
	kiss_renderimage (m_renderer, globe_slice, 0, m_globe_slice_y_position, NULL);
	
	SDL_RenderPresent (m_renderer);
	draw = 0;
}


void RenderingManager::Stop ()
{

	kiss_clean (&objects);
}