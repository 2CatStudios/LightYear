#include "RenderingManager.h"


int RenderingManager::InitializeKISS ()
{
	
	m_renderer = kiss_init (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_LIGHTYEAR).c_str (), &objects, 1024, 576);
	m_AddExternalAssets (&objects);
	
	return 0;
}


std::string RenderingManager::GetApplicationPath ()
{
	
	if (m_applicationPath.empty ())
	{
		
		std::string base_path = SDL_GetBasePath ();
		
		if (base_path.empty ())
			base_path = "./";
		
		m_applicationPath = base_path;
	}
	
	return m_applicationPath;
}


std::string RenderingManager::GetResourcesPath ()
{
	
	if (m_resourcesPath.empty ())
	{
		
		std::string fullPath = GetApplicationPath ();
		std::string appendedString = fullPath;
		
		if (fullPath != "./")
		{
			
			appendedString = appendedString.substr (0, appendedString.length () - 1);
			appendedString = appendedString.substr (0, appendedString.find_last_of (PATH_SEPARATOR) + 1);
			appendedString += "resources";
			appendedString += PATH_SEPARATOR;
		}
		
		m_resourcesPath = appendedString;
	}
	
	return m_resourcesPath;
}


std::string RenderingManager::GetPreferencesPath ()
{
	
	if (m_preferencesPath.empty ())
	{
		
		std::string base_path = SDL_GetPrefPath ("2Cat Studios", "LightYear IF");
		
		if (base_path.empty ())
			base_path = "./";
		
		m_preferencesPath = base_path;
	}
	
	return m_preferencesPath;
}


bool RenderingManager::IsRetinaDisplay ()
{
	
	if (m_retinaDisplay == -1)
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
	kiss_font_new (&m_font_title, const_cast<char*> (assets[EA_FONT_ANSON_REGULAR].c_str ()), a, m_font_title_size);
	kiss_font_new (&m_font_subtitle, const_cast<char*> (assets[EA_FONT_ANSON_REGULAR].c_str ()), a, m_font_subtitle_size);

	/*Custom 2X Assets*/
	if (IsRetinaDisplay () == true)
	{
		
		kiss_textfont_size *= 2;
		kiss_buttonfont_size *= 2;
		m_font_title_size *= 2;
		m_font_subtitle_size *= 2;
		m_buttonPadding *= 2;
		
		const int CUSTOM_2X_ASSET_STARTING_POSITION = 10;
		for (int index = CUSTOM_2X_ASSET_STARTING_POSITION; index < TOTAL_ASSETS; index += 1)
		{
			
			assets[index] = m_appendAssetWithAt2X (assets[index]);
		}
	}

	kiss_image_new (&kiss_vslider, const_cast<char*> (assets[EA_VSLIDER_HANDLE].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_up, const_cast<char*> (assets[EA_VSLIDER_UP].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_down, const_cast<char*> (assets[EA_VSLIDER_DOWN].c_str ()), a, m_renderer);
	kiss_image_new (&m_horizontal_bar, const_cast<char*> (assets[EA_HORIZONTAL_BAR].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_normal, const_cast<char*> (assets[EA_BUTTON_NORMAL].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_prelight, const_cast<char*> (assets[EA_BUTTON_PRELIGHT].c_str ()), a, m_renderer);
	kiss_image_new (&kiss_active, const_cast<char*> (assets[EA_BUTTON_ACTIVE].c_str ()), a, m_renderer);
	kiss_image_new (&m_globe_slice, const_cast<char*> (assets[EA_GLOBE_SLICE].c_str ()), a, m_renderer);
	m_globe_slice_y_position = 576 - m_globe_slice.h;
	
	return 0;
}


int RenderingManager::m_CreateMainMenu ()
{
	
	if (mainMenu.created == false)
	{
	
		kiss_array_new (&mainMenu.gui_objects);
	
		kiss_window_new (&mainMenu.window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		mainMenu.window.bg = lightYear_black;
		kiss_array_append (&mainMenu.gui_objects, 0, &mainMenu.window);
		
		kiss_label_new (
			&mainMenu.label_version,
			&mainMenu.window,
			const_cast<char*> (VERSION),
			mainMenu.window.rect.x + 4,
			mainMenu.window.rect.y + 0
				);
		mainMenu.label_version.textcolor = kiss_white;
		mainMenu.label_version.font = kiss_textfont;
		kiss_array_append (&mainMenu.gui_objects, 1, &mainMenu.label_version);
		
		kiss_label_new (
			&mainMenu.label_title,
			&mainMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_LIGHTYEAR).c_str ()),
			mainMenu.window.rect.x + ((mainMenu.window.rect.w / 2) - (kiss_textwidth (m_font_title, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_LIGHTYEAR).c_str ()), NULL) / 2)),
			mainMenu.window.rect.y + 10
				);
		mainMenu.label_title.textcolor = kiss_white;
		mainMenu.label_title.font = m_font_title;
		kiss_array_append (&mainMenu.gui_objects, 2, &mainMenu.label_title);
		
		kiss_label_new (
			&mainMenu.label_subtitle,
			&mainMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD).c_str ()),
			mainMenu.window.rect.x + ((mainMenu.window.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_A_HYBIRD_IF_ENGINE_LIGHTYEARS_AHEAD).c_str ()), NULL) / 2)),
			mainMenu.label_title.rect.y + m_font_title.fontheight
				);
		mainMenu.label_subtitle.textcolor = kiss_white;
		mainMenu.label_subtitle.font = m_font_subtitle;
		kiss_array_append (&mainMenu.gui_objects, 3, &mainMenu.label_subtitle);
		
		kiss_button_new (
			&mainMenu.button_playGame,
			&mainMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_PLAY).c_str ()),
			mainMenu.window.rect.x + ((mainMenu.window.rect.w / 2) - (kiss_normal.w / 2)),
			mainMenu.label_subtitle.rect.y + m_font_subtitle_size + m_buttonPadding
				);
		mainMenu.button_playGame.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 4, &mainMenu.button_playGame);
		
		kiss_button_new (
			&mainMenu.button_options,
			&mainMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_OPTIONS).c_str ()),
			mainMenu.window.rect.x + ((mainMenu.window.rect.w / 2) - (kiss_normal.w / 2)),
			mainMenu.button_playGame.rect.y + mainMenu.button_playGame.rect.h + m_buttonPadding
				);
		mainMenu.button_options.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 5, &mainMenu.button_options);
		
		kiss_button_new (
			&mainMenu.button_about,
			&mainMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_ABOUT).c_str ()),
			mainMenu.window.rect.x + ((mainMenu.window.rect.w / 2) - (kiss_normal.w / 2)),
			mainMenu.button_options.rect.y + mainMenu.button_options.rect.h + m_buttonPadding
				);
		mainMenu.button_about.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 6, &mainMenu.button_about);
		
		kiss_button_new (
			&mainMenu.button_quit,
			&mainMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::MAINMENU, LocalizationManager::MM_QUIT).c_str ()),
			mainMenu.window.rect.x + ((mainMenu.window.rect.w / 2) - (kiss_normal.w / 2)),
			mainMenu.button_about.rect.y + mainMenu.button_about.rect.h + m_buttonPadding
				);
		mainMenu.button_quit.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 7, &mainMenu.button_quit);
		
		mainMenu.created = true;
		draw = 1;
		return 0;
	} else {
		return 1;
	}
}


int RenderingManager::m_CreateSelectGameMenu ()
{
	
	if (selectgameMenu.created == false)
	{
		
		kiss_array_new (&selectgameMenu.gui_objects);
		
		kiss_window_new (&selectgameMenu.window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		selectgameMenu.window.bg = lightYear_black;
		kiss_array_append (&selectgameMenu.gui_objects, 0, &selectgameMenu.window);
		
		kiss_button_new (
			&selectgameMenu.button_back,
			&selectgameMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_RETURN).c_str ()),
			selectgameMenu.window.rect.x + m_buttonPadding,
			selectgameMenu.window.rect.y + m_buttonPadding
				);
		selectgameMenu.button_back.textcolor = kiss_white;
		kiss_array_append (&selectgameMenu.gui_objects, 1, &selectgameMenu.button_back);
		
		selectgameMenu.created = true;
		draw = 1;
		return 0;
	} else {
		return 1;
	}
}


int RenderingManager::m_CreateOptionsMenu ()
{
	
	if (optionsMenu.created == false)
	{
		
		kiss_array_new (&optionsMenu.gui_objects);
		
		kiss_window_new (&optionsMenu.window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		optionsMenu.window.bg = lightYear_black;
		kiss_array_append (&optionsMenu.gui_objects, 0, &optionsMenu.window);
		
		kiss_button_new (
			&optionsMenu.button_back,
			&optionsMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_RETURN).c_str ()),
			optionsMenu.window.rect.x + m_buttonPadding,
			optionsMenu.window.rect.y + m_buttonPadding
				);
		optionsMenu.button_back.textcolor = kiss_white;
		kiss_array_append (&optionsMenu.gui_objects, 1, &optionsMenu.button_back);
		
		
		kiss_label_new (
			&optionsMenu.label_title,
			&optionsMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::OPTIONS, LocalizationManager::O_OPTIONS).c_str ()),
			optionsMenu.window.rect.x + ((optionsMenu.window.rect.w / 2) - (kiss_textwidth (m_font_title, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::OPTIONS, LocalizationManager::O_OPTIONS).c_str ()), NULL) / 2)),
			optionsMenu.window.rect.y + 10
				);
		optionsMenu.label_title.textcolor = kiss_white;
		optionsMenu.label_title.font = m_font_title;
		kiss_array_append (&optionsMenu.gui_objects, 2, &optionsMenu.label_title);
		
		optionsMenu.created = true;
		draw = 1;
		return 0;
	} else {
		return 1;
	}
}


int RenderingManager::m_CreateAboutMenu ()
{
	
	if (aboutMenu.created == false)
	{
		
		kiss_array_new (&aboutMenu.gui_objects);
		
		kiss_window_new (&aboutMenu.window, NULL, 0, 1, 0, 0, kiss_screen_width, kiss_screen_height);
		aboutMenu.window.bg = lightYear_black;
		kiss_array_append (&aboutMenu.gui_objects, 0, &aboutMenu.window);
		
		kiss_button_new (
			&aboutMenu.button_back,
			&aboutMenu.window,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::GENERAL, LocalizationManager::G_RETURN).c_str ()),
			aboutMenu.window.rect.x + m_buttonPadding,
			aboutMenu.window.rect.x + m_buttonPadding
				);
		aboutMenu.button_back.textcolor = kiss_white;
		kiss_array_append (&aboutMenu.gui_objects, 1, &aboutMenu.button_back);
		
		
		int titleWidth = kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE).c_str ()), NULL);
		kiss_window_new (&aboutMenu.scroll_view, NULL, 0, 0, (aboutMenu.window.rect.w / 2) - (titleWidth / 2) - 10, 0, titleWidth + 20, 770);
		kiss_array_append (&aboutMenu.gui_objects, 2, &aboutMenu.scroll_view);
		
		kiss_vscrollbar_new (&aboutMenu.scrollbar, &aboutMenu.window, (aboutMenu.window.rect.w / 2) + (titleWidth / 2) + 20, (aboutMenu.window.rect.h / 2) - 175, 350);
		kiss_array_append (&aboutMenu.gui_objects, 3, &aboutMenu.scrollbar);
		
		
		kiss_label_new (
			&aboutMenu.label_title,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_ABOUT).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_title, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_ABOUT).c_str ()), NULL) / 2)),
			aboutMenu.scroll_view.rect.y + 10
				);
		aboutMenu.label_title.textcolor = kiss_white;
		aboutMenu.label_title.font = m_font_title;
		kiss_array_append (&aboutMenu.gui_objects, 4, &aboutMenu.label_title);

		kiss_label_new (
			&aboutMenu.label_preamble_top,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_THE_LIGHTYEAR_INTERACTIVE_FICTION_ENGINE).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (titleWidth / 2)),
			aboutMenu.label_title.rect.y + m_font_title.fontheight
				);
		aboutMenu.label_preamble_top.textcolor = kiss_white;
		aboutMenu.label_preamble_top.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 5, &aboutMenu.label_preamble_top);
		
		kiss_label_new (
			&aboutMenu.label_preamble_bottom,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_HAS_BEEN_LOVINGLY_CREATED_BY).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_HAS_BEEN_LOVINGLY_CREATED_BY).c_str ()), NULL) / 2)),
			aboutMenu.label_preamble_top.rect.y + m_font_subtitle.fontheight
				);
		aboutMenu.label_preamble_bottom.textcolor = kiss_white;
		aboutMenu.label_preamble_bottom.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 6, &aboutMenu.label_preamble_bottom);
		
		kiss_label_new (
			&aboutMenu.label_twocatstudios,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_2CATSTUDIOS).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_2CATSTUDIOS).c_str ()), NULL) / 2)),
			aboutMenu.label_preamble_bottom.rect.y + m_font_subtitle.fontheight + m_labelPadding
				);
		aboutMenu.label_twocatstudios.textcolor = kiss_white;
		aboutMenu.label_twocatstudios.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 7, &aboutMenu.label_twocatstudios);
		
		
		kiss_label_new (
			&aboutMenu.label_team_michaelb,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_MICHAEL_BETHKE_LEAD_DEVELOPER).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_MICHAEL_BETHKE_LEAD_DEVELOPER).c_str ()), NULL) / 2)),
			aboutMenu.label_twocatstudios.rect.y + m_font_subtitle.fontheight + m_labelPadding
				);
		aboutMenu.label_team_michaelb.textcolor = kiss_white;
		aboutMenu.label_team_michaelb.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 8, &aboutMenu.label_team_michaelb);
		
		kiss_label_new (
			&aboutMenu.label_team_janh,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_JAN_HEEMSTRA_FEEDBACK_AND_SUPPORT).c_str ()), NULL) / 2)),
			aboutMenu.label_team_michaelb.rect.y + m_font_subtitle.fontheight
				);
		aboutMenu.label_team_janh.textcolor = kiss_white;
		aboutMenu.label_team_janh.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 9, &aboutMenu.label_team_janh);
		
		
		kiss_label_new (
			&aboutMenu.label_thanksto,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_WITH_THANKS_TO).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_WITH_THANKS_TO).c_str ()), NULL) / 2)),
			aboutMenu.label_team_janh.rect.y + (m_font_subtitle.fontheight * 2)
				);
		aboutMenu.label_thanksto.textcolor = kiss_white;
		aboutMenu.label_thanksto.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 10, &aboutMenu.label_thanksto);
		
		kiss_label_new (
			&aboutMenu.label_supporters_bleikur,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_BLEIKUR_DESIGN_AND_FEEDBACK).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_BLEIKUR_DESIGN_AND_FEEDBACK).c_str ()), NULL) / 2)),
			aboutMenu.label_thanksto.rect.y + m_font_subtitle.fontheight
				);
		aboutMenu.label_supporters_bleikur.textcolor = kiss_white;
		aboutMenu.label_supporters_bleikur.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 11, &aboutMenu.label_supporters_bleikur);
		
		kiss_label_new (
			&aboutMenu.label_supporters_tarvok,
			&aboutMenu.scroll_view,
			const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_TARVO_KORROVITS_KISS_SDL).c_str ()),
			aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (kiss_textwidth (m_font_subtitle, const_cast<char*> (localizationManager->GetLocalizedApplicationText (LocalizationManager::ABOUT, LocalizationManager::A_TARVO_KORROVITS_KISS_SDL).c_str ()), NULL) / 2)),
			aboutMenu.label_supporters_bleikur.rect.y + m_font_subtitle.fontheight
				);
		aboutMenu.label_supporters_tarvok.textcolor = kiss_white;
		aboutMenu.label_supporters_tarvok.font = m_font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 12, &aboutMenu.label_supporters_tarvok);
		
		aboutMenu.created = true;
		draw = 1;
		return 0;
	} else {
		return 1;
	}
}


//TODO: Make generic
void RenderingManager::CalculateAboutMenuPositionsY ()
{

	//TODO: DRY
	aboutMenu.label_title.rect.y = aboutMenu.scroll_view.rect.y + 10;
	aboutMenu.label_preamble_top.rect.y = aboutMenu.label_title.rect.y + m_font_title.fontheight;
	aboutMenu.label_preamble_bottom.rect.y = aboutMenu.label_preamble_top.rect.y + m_font_subtitle.fontheight;
	aboutMenu.label_twocatstudios.rect.y = aboutMenu.label_preamble_bottom.rect.y + m_font_subtitle.fontheight + m_labelPadding;
	aboutMenu.label_team_michaelb.rect.y = aboutMenu.label_twocatstudios.rect.y + m_font_subtitle.fontheight + m_labelPadding;
	aboutMenu.label_team_janh.rect.y = aboutMenu.label_team_michaelb.rect.y + m_font_subtitle.fontheight;
	aboutMenu.label_thanksto.rect.y = aboutMenu.label_team_janh.rect.y + (m_font_subtitle.fontheight * 2);
	aboutMenu.label_supporters_bleikur.rect.y = aboutMenu.label_thanksto.rect.y + m_font_subtitle.fontheight;
	aboutMenu.label_supporters_tarvok.rect.y = aboutMenu.label_supporters_bleikur.rect.y + m_font_subtitle.fontheight;
}


void RenderingManager::m_DrawMainMenu ()
{
	
	if (mainMenu.created == false)
		m_CreateMainMenu ();
	
	mainMenu.window.visible = 1;
	kiss_window_draw (&mainMenu.window, m_renderer);
	
	kiss_label_draw (&mainMenu.label_title, m_renderer);
	kiss_label_draw (&mainMenu.label_subtitle, m_renderer);
	kiss_button_draw (&mainMenu.button_playGame, m_renderer);
	kiss_button_draw (&mainMenu.button_options, m_renderer);
	kiss_button_draw (&mainMenu.button_about, m_renderer);
	kiss_button_draw (&mainMenu.button_quit, m_renderer);
	kiss_label_draw (&mainMenu.label_version, m_renderer);
}


void RenderingManager::m_DrawSelectGameMenu ()
{
	
	if (selectgameMenu.created == false)
		m_CreateSelectGameMenu ();
	
	selectgameMenu.window.visible = 1;
	kiss_window_draw (&selectgameMenu.window, m_renderer);
	
	kiss_button_draw (&selectgameMenu.button_back, m_renderer);
}


void RenderingManager::m_DrawOptionsMenu ()
{
	
	if (optionsMenu.created == false)
		m_CreateOptionsMenu ();
	
	optionsMenu.window.visible = 1;
	kiss_window_draw (&optionsMenu.window, m_renderer);
	
	kiss_button_draw (&optionsMenu.button_back, m_renderer);
	kiss_label_draw (&optionsMenu.label_title, m_renderer);
}


void RenderingManager::m_DrawAboutMenu ()
{
	
	if (aboutMenu.created == false)
		m_CreateAboutMenu ();
	
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
	kiss_renderimage (m_renderer, m_horizontal_bar, aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (284 / 2)), aboutMenu.label_twocatstudios.rect.y + m_font_subtitle.fontheight, NULL);
	kiss_label_draw (&aboutMenu.label_team_michaelb, m_renderer);
	kiss_label_draw (&aboutMenu.label_team_janh, m_renderer);
	
	kiss_label_draw (&aboutMenu.label_thanksto, m_renderer);
	kiss_renderimage (m_renderer, m_horizontal_bar, aboutMenu.scroll_view.rect.x + ((aboutMenu.scroll_view.rect.w / 2) - (284 / 2)), aboutMenu.label_thanksto.rect.y + m_font_subtitle.fontheight, NULL);
	kiss_label_draw (&aboutMenu.label_supporters_bleikur, m_renderer);
	kiss_label_draw (&aboutMenu.label_supporters_tarvok, m_renderer);
	
}


void RenderingManager::Update ()
{
	
	if (draw == 0)
		return;
	
	SDL_RenderClear (m_renderer);
	mainMenu.window.visible = 0;
	selectgameMenu.window.visible = 0;
	optionsMenu.window.visible = 0;
	aboutMenu.window.visible = 0;
	aboutMenu.scroll_view.visible = 0;
	
	switch (menuState)
	{
		
		case NONE:
			break;
		
		case MAINMENU:
			
			m_DrawMainMenu ();
			break;
		
		case SELECTGAME:
			m_DrawSelectGameMenu ();
			break;
		
		case OPTIONS:
			m_DrawOptionsMenu ();
			break;
		
		case ABOUT:
			m_DrawAboutMenu ();
			break;
		
		default:
			break;
	}
	
	kiss_renderimage (m_renderer, m_globe_slice, 0, m_globe_slice_y_position, NULL);
	
	SDL_RenderPresent (m_renderer);
	draw = 0;
}


void RenderingManager::Stop ()
{
	
	kiss_clean (&objects);
}