#include "RenderingManager.h"


int RenderingManager::InitializeKISS ()
{
	
	kiss_array_new (&objects);
	m_renderer = kiss_init ("LightYear", &objects, 1024, 576);
	
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


int RenderingManager::CreateAboutMenu ()
{
	
	if (aboutMenu.created == false)
	{
		
		kiss_array_new (&aboutMenu.gui_objects);
		
		kiss_window_new (&aboutMenu.window, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
		kiss_array_append (&aboutMenu.gui_objects, 0, &aboutMenu.window);
		
		kiss_label_new (&aboutMenu.label_title, &aboutMenu.window, "About", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_title, "About", NULL) / 2), 10);
		aboutMenu.label_title.textcolor = kiss_white;
		aboutMenu.label_title.font = font_title;
		kiss_array_append (&aboutMenu.gui_objects, 1, &aboutMenu.label_title);
		
		kiss_label_new (&aboutMenu.label_credits, &aboutMenu.window, "The LightYear Interactive Fiction engine\nhas been lovingly created by\n\n2Cat Studios\nMichael Bethke - Programming & Design\nJan Heemstra - Feedback & Support\n\nWith thanks to\nAnders Huft - Design & Feedback\nTarvo Korrovits - KISS_SDL Support", (aboutMenu.window.rect.w / 2) - (kiss_textwidth (font_subtitle, "The LightYear Interactive Fiction engine", NULL) / 2), aboutMenu.label_title.rect.y + font_title.fontheight + m_labelPadding);
		aboutMenu.label_credits.textcolor = kiss_white;
		aboutMenu.label_credits.font = font_subtitle;
		kiss_array_append (&aboutMenu.gui_objects, 2, &aboutMenu.label_title);
		
		kiss_button_new (&aboutMenu.button_back, &aboutMenu.window, "Return", m_buttonPadding, m_buttonPadding);
		aboutMenu.button_back.textcolor = kiss_white;
		kiss_array_append (&aboutMenu.gui_objects, 3, &aboutMenu.button_back);
		
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
	kiss_renderimage (m_renderer, menu_background, 0, 0, NULL);
	
	kiss_label_draw (&mainMenu.label_title, m_renderer);
	kiss_label_draw (&mainMenu.label_subtitle, m_renderer);
	kiss_button_draw (&mainMenu.button_playGame, m_renderer);
	kiss_button_draw (&mainMenu.button_options, m_renderer);
	kiss_button_draw (&mainMenu.button_about, m_renderer);
	kiss_button_draw (&mainMenu.button_quit, m_renderer);
	kiss_label_draw (&mainMenu.label_version, m_renderer);
}


void RenderingManager::m_DrawAboutMenu ()
{
	
	if (aboutMenu.created == false)
		CreateAboutMenu ();
	
	aboutMenu.window.visible = 1;
	
	kiss_window_draw (&aboutMenu.window, m_renderer);
	kiss_renderimage (m_renderer, menu_background, 0, 0, NULL);
	
	kiss_label_draw (&aboutMenu.label_title, m_renderer);
	kiss_label_draw (&aboutMenu.label_credits, m_renderer);
	kiss_button_draw (&aboutMenu.button_back, m_renderer);
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