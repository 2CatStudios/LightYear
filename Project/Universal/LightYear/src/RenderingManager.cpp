#include "RenderingManager.h"


int RenderingManager::InitializeKISS ()
{
	
	//kiss_array_new (&objects);
	m_renderer = kiss_init ("LightYear", &objects, 1024, 576);
	
	m_AddExternalAssets (&objects, m_IsRetinaDisplay ());
	
	return 0;
}


bool RenderingManager::m_IsRetinaDisplay ()
{

	/*
		iMac (non retina)
			DDPI: 1.4013e-45
			HDPI: 6.35875e-30
		->	VDPI: 1.79417e+19
		
		MacBook Pro (retina)
			DDPI: 1.4013e-45
			HDPI: 6.35875e-30
		->	VDPI: 8.24955e+13
	
	*/
	
	float *ddpi;
	float *hdpi;
	float *vdpi;
	
	SDL_GetDisplayDPI (0, ddpi, hdpi, vdpi);
	
	if ((*vdpi - 1.79417e+19) > 0.1)
	{
		
		//std::cout << "Is Retina" << std::endl;
		return true;
	} else {
		
		//std::cout << "Not Retina" << std::endl;
		return false;
	}
}


int RenderingManager::m_AddExternalAssets (kiss_array *a, bool highDPI)
{
	
	if (highDPI == true)
		std::cout << "Is Retina" << std::endl;
	else
		std::cout << "Not Retina" << std::endl;
	
	SDL_Renderer *renderer = (SDL_Renderer*) kiss_array_data (a, 1);
	
	/*Default Assets*/
	image_new(&kiss_bar, "kiss_bar.png", a, renderer);
	image_new(&kiss_vslider, "kiss_vslider.png", a, renderer);
	image_new(&kiss_hslider, "kiss_hslider.png", a, renderer);
	image_new(&kiss_up, "kiss_up.png", a, renderer);
	image_new(&kiss_down, "kiss_down.png", a, renderer);
	image_new(&kiss_left, "kiss_left.png", a, renderer);
	image_new(&kiss_right, "kiss_right.png", a, renderer);
	image_new(&kiss_selected, "kiss_selected.png", a, renderer);
	image_new(&kiss_unselected, "kiss_unselected.png", a, renderer);
	
	/*Custom Assets*/
	font_new(&kiss_textfont, "font_anson_regular.ttf", a, kiss_textfont_size);
	font_new(&kiss_buttonfont, "font_anson_regular.ttf", a, kiss_buttonfont_size);
	font_new (&font_title, "font_anson_regular.ttf", a, font_title_size);
	font_new (&font_subtitle, "font_anson_regular.ttf", a, font_subtitle_size);
	
	image_new (&background, "background.png", a, renderer);
	image_new (&horizontal_bar, "horizontal_bar.png", a, renderer);
	image_new (&kiss_normal, "button_normal.png", a, renderer);
	image_new (&kiss_prelight, "button_prelight.png", a, renderer);
	image_new (&kiss_active, "button_active.png", a, renderer);
	
	return 0;
}


int RenderingManager::CreateMainMenu ()
{
	
	if (mainMenu.created == false)
	{
	
		kiss_array_new (&mainMenu.gui_objects);
	
		kiss_window_new (&mainMenu.window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
		kiss_array_append (&mainMenu.gui_objects, 0, &mainMenu.window);
		
		kiss_label_new (&mainMenu.label_version, &mainMenu.window, "Version 0.0.0d2", 4, 0);
		mainMenu.label_version.textcolor = kiss_white;
		mainMenu.label_version.font = kiss_textfont;
		kiss_array_append (&mainMenu.gui_objects, 1, &mainMenu.label_version);
		
		kiss_label_new (&mainMenu.label_title, &mainMenu.window, "LightYear", (mainMenu.window.rect.w/2) - (kiss_textwidth (font_title, "LightYear", NULL) / 2), 10);
		mainMenu.label_title.textcolor = kiss_white;
		mainMenu.label_title.font = font_title;
		kiss_array_append (&mainMenu.gui_objects, 2, &mainMenu.label_title);
		
		kiss_label_new (&mainMenu.label_subtitle, &mainMenu.window, "A hybrid IF engine, lightyears ahead.", mainMenu.window.rect.w / 2 - (kiss_textwidth (font_subtitle, "A hybrid IF engine, lightyears ahead.", NULL) / 2), mainMenu.label_title.rect.y + font_title.fontheight);
		mainMenu.label_subtitle.textcolor = kiss_white;
		mainMenu.label_subtitle.font = font_subtitle;
		kiss_array_append (&mainMenu.gui_objects, 3, &mainMenu.label_subtitle);
		
		kiss_button_new (&mainMenu.button_playGame, &mainMenu.window, "Play Game", mainMenu.window.rect.w / 2 - kiss_normal.w / 2, mainMenu.label_subtitle.rect.y + kiss_buttonfont.fontheight + m_buttonPadding * 3);
		mainMenu.button_playGame.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 4, &mainMenu.button_playGame);
		
		kiss_button_new (&mainMenu.button_options, &mainMenu.window, "Options", mainMenu.window.rect.w / 2 - kiss_normal.w / 2, mainMenu.button_playGame.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
		mainMenu.button_options.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 5, &mainMenu.button_options);
		
		kiss_button_new (&mainMenu.button_about, &mainMenu.window, "About", mainMenu.window.rect.w / 2 - kiss_normal.w / 2, mainMenu.button_options.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
		mainMenu.button_about.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 6, &mainMenu.button_about);
		
		kiss_button_new (&mainMenu.button_quit, &mainMenu.window, "Quit", mainMenu.window.rect.w / 2 - kiss_normal.w / 2, mainMenu.button_about.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
		mainMenu.button_quit.textcolor = kiss_white;
		kiss_array_append (&mainMenu.gui_objects, 7, &mainMenu.button_quit);
		
		mainMenu.created = true;
		draw = 1;
	}

	return 0;
}


int RenderingManager::CreateOptionsMenu ()
{
	
	if (optionsMenu.created == false)
	{
		
		kiss_array_new (&optionsMenu.gui_objects);
		
		kiss_window_new (&optionsMenu.window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
		kiss_array_append (&optionsMenu.gui_objects, 0, &optionsMenu.window);
		
		kiss_button_new (&optionsMenu.button_back, &optionsMenu.window, "Return", m_buttonPadding, m_buttonPadding);
		optionsMenu.button_back.textcolor = kiss_white;
		kiss_array_append (&optionsMenu.gui_objects, 1, &optionsMenu.button_back);
		
		
		kiss_label_new (&optionsMenu.label_title, &optionsMenu.window, "Options", (optionsMenu.window.rect.w / 2) - (kiss_textwidth (font_title, "Options", NULL) / 2), 10);
		optionsMenu.label_title.textcolor = kiss_white;
		optionsMenu.label_title.font = font_title;
		kiss_array_append (&optionsMenu.gui_objects, 2, &optionsMenu.label_title);
		
		optionsMenu.created = true;
		draw = 1;
	}
}


int RenderingManager::CreateAboutMenu ()
{
	
	if (aboutMenu.created == false)
	{
		
		kiss_array_new (&aboutMenu.gui_objects);
		
		kiss_window_new (&aboutMenu.window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
		kiss_array_append (&aboutMenu.gui_objects, 0, &aboutMenu.window);
		
		kiss_button_new (&aboutMenu.button_back, &aboutMenu.window, "Return", m_buttonPadding, m_buttonPadding);
		aboutMenu.button_back.textcolor = kiss_white;
		kiss_array_append (&aboutMenu.gui_objects, 1, &aboutMenu.button_back);
		
		
		kiss_label_new (&aboutMenu.label_title, &aboutMenu.window, "About", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_title, "About", NULL) / 2), 10);
		aboutMenu.label_title.textcolor = kiss_white;
		aboutMenu.label_title.font = font_title;
		kiss_array_append (&aboutMenu.gui_objects, 2, &aboutMenu.label_title);

		kiss_label_new (&aboutMenu.label_preamble_top, &aboutMenu.window, "The LightYear Interactive Fiction engine", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "The LightYear Interactive Fiction engine", NULL) / 2), aboutMenu.label_title.rect.y + font_title.fontheight);
		aboutMenu.label_preamble_top.textcolor = kiss_white;
		aboutMenu.label_preamble_top.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 3, &aboutMenu.label_preamble_top);
		
		kiss_label_new (&aboutMenu.label_preamble_bottom, &aboutMenu.window, "has been lovingly created by", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "has been lovingly created by", NULL) / 2), aboutMenu.label_preamble_top.rect.y + font_subtitle.fontheight);
		aboutMenu.label_preamble_bottom.textcolor = kiss_white;
		aboutMenu.label_preamble_bottom.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 4, &aboutMenu.label_preamble_bottom);
		
		kiss_label_new (&aboutMenu.label_twocatstudios, &aboutMenu.window, "2Cat Studios", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "2Cat Studios", NULL) / 2), aboutMenu.label_preamble_bottom.rect.y + font_subtitle.fontheight + m_labelPadding);
		aboutMenu.label_twocatstudios.textcolor = kiss_white;
		aboutMenu.label_twocatstudios.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 5, &aboutMenu.label_twocatstudios);
		
		
		kiss_label_new (&aboutMenu.label_team_michaelb, &aboutMenu.window, "Michael Bethke - Programming & Design", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "Michael Bethke - Programming & Design", NULL) / 2), aboutMenu.label_twocatstudios.rect.y + font_subtitle.fontheight + m_labelPadding);
		aboutMenu.label_team_michaelb.textcolor = kiss_white;
		aboutMenu.label_team_michaelb.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 6, &aboutMenu.label_team_michaelb);
		
		kiss_label_new (&aboutMenu.label_team_janh, &aboutMenu.window, "Jan Heemstra - Feedback & Support", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "Jan Heemstra - Feedback & Support", NULL) / 2), aboutMenu.label_team_michaelb.rect.y + font_subtitle.fontheight);
		aboutMenu.label_team_janh.textcolor = kiss_white;
		aboutMenu.label_team_janh.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 7, &aboutMenu.label_team_janh);
		
		
		kiss_label_new (&aboutMenu.label_thanksto, &aboutMenu.window, "With thanks to", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "With thanks to", NULL) / 2), aboutMenu.label_team_janh.rect.y + (font_subtitle.fontheight * 2));
		aboutMenu.label_thanksto.textcolor = kiss_white;
		aboutMenu.label_thanksto.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 8, &aboutMenu.label_thanksto);
		
		kiss_label_new (&aboutMenu.label_supporters_bleikur, &aboutMenu.window, "\"Bleikur\" - Design & Feedback", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "\"Bleikur\" - Design & Feedback", NULL) / 2), aboutMenu.label_thanksto.rect.y + font_subtitle.fontheight);
		aboutMenu.label_supporters_bleikur.textcolor = kiss_white;
		aboutMenu.label_supporters_bleikur.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 9, &aboutMenu.label_supporters_bleikur);
		
		kiss_label_new (&aboutMenu.label_supporters_tarvok, &aboutMenu.window, "Tarvo Korrovits - KISS_SDL Support", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "Tarvo Korrovits - KISS_SDL Support", NULL) / 2), aboutMenu.label_supporters_bleikur.rect.y + font_subtitle.fontheight);
		aboutMenu.label_supporters_tarvok.textcolor = kiss_white;
		aboutMenu.label_supporters_tarvok.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 10, &aboutMenu.label_supporters_tarvok);
		
		aboutMenu.created = true;
		draw = 1;
	}
	
	return 0;
}


void RenderingManager::m_DrawMainMenu ()
{
	
	if (mainMenu.created == false)
		CreateMainMenu ();
	
	mainMenu.window.visible = 1;
	
	kiss_window_draw (&mainMenu.window, m_renderer);
	kiss_renderimage (m_renderer, background, 0, 0, NULL);
	
	kiss_label_draw (&mainMenu.label_title, m_renderer);
	kiss_label_draw (&mainMenu.label_subtitle, m_renderer);
	kiss_button_draw (&mainMenu.button_playGame, m_renderer);
	kiss_button_draw (&mainMenu.button_options, m_renderer);
	kiss_button_draw (&mainMenu.button_about, m_renderer);
	kiss_button_draw (&mainMenu.button_quit, m_renderer);
	kiss_label_draw (&mainMenu.label_version, m_renderer);
}


void RenderingManager::m_DrawOptionsMenu ()
{
	
	if (optionsMenu.created == false)
		CreateOptionsMenu ();
	
	optionsMenu.window.visible = 1;
	
	kiss_window_draw (&optionsMenu.window, m_renderer);
	kiss_renderimage (m_renderer, background, 0, 0, NULL);
	
	kiss_button_draw (&optionsMenu.button_back, m_renderer);
	kiss_label_draw (&optionsMenu.label_title, m_renderer);
}


void RenderingManager::m_DrawAboutMenu ()
{
	
	if (aboutMenu.created == false)
		CreateAboutMenu ();
	
	aboutMenu.window.visible = 1;
	
	kiss_window_draw (&aboutMenu.window, m_renderer);
	kiss_renderimage (m_renderer, background, 0, 0, NULL);
	
	kiss_button_draw (&aboutMenu.button_back, m_renderer);
	kiss_label_draw (&aboutMenu.label_title, m_renderer);
	kiss_label_draw (&aboutMenu.label_preamble_top, m_renderer);
	kiss_label_draw (&aboutMenu.label_preamble_bottom, m_renderer);
	
	kiss_label_draw (&aboutMenu.label_twocatstudios, m_renderer);
	kiss_renderimage (m_renderer, horizontal_bar, (aboutMenu.window.rect.w / 2) - (284 / 2), aboutMenu.label_twocatstudios.rect.y + font_subtitle.fontheight, NULL);
	kiss_label_draw (&aboutMenu.label_team_michaelb, m_renderer);
	kiss_label_draw (&aboutMenu.label_team_janh, m_renderer);
	
	kiss_label_draw (&aboutMenu.label_thanksto, m_renderer);
	kiss_renderimage (m_renderer, horizontal_bar, (aboutMenu.window.rect.w / 2) - (284 / 2), aboutMenu.label_thanksto.rect.y + font_subtitle.fontheight, NULL);
	kiss_label_draw (&aboutMenu.label_supporters_bleikur, m_renderer);
	kiss_label_draw (&aboutMenu.label_supporters_tarvok, m_renderer);
	
}


void RenderingManager::Update ()
{
	
	if (draw == 0)
		return;
	
	SDL_RenderClear (m_renderer);
	
	switch (menuState)
	{
		
		case NONE:
			break;
		
		case MAINMENU:
			m_DrawMainMenu ();
			break;
		
		case SELECTGAME:
			break;
		
		case OPTIONS:
			m_DrawOptionsMenu ();
			break;
		
		case ABOUT:
			mainMenu.window.visible = 0;
			m_DrawAboutMenu ();
			break;
		
		default:
			break;
	}
	
	SDL_RenderPresent (m_renderer);
	draw = 0;
}


void RenderingManager::Stop ()
{
	
	kiss_clean (&objects);
}