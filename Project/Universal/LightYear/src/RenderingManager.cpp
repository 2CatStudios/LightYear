#include "RenderingManager.h"


int RenderingManager::InitializeKISS ()
{
	
	kiss_array_new (&objects);
	kiss_array_new (&menu_gui_objects);
	m_renderer = kiss_init ("LightYear", &objects, 1024, 576);
	
	return 0;
}


int RenderingManager::CreateWindowMenu ()
{
	
	kiss_window_new (&window_menu, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
	kiss_array_append (&menu_gui_objects, 0, &window_menu);
	
	kiss_label_new (&label_version, &window_menu, "Version 0.0.0d1", 4, 0);
	label_version.textcolor = kiss_white;
	label_version.font = kiss_textfont;
	kiss_array_append (&menu_gui_objects, 1, &label_version);
	
	kiss_label_new (&label_title, &window_menu, "LightYear", (window_menu.rect.w/2) - (kiss_textwidth (font_title, "LightYear", NULL) / 2), 10);
	label_title.textcolor = kiss_white;
	label_title.font = font_title;
	kiss_array_append (&menu_gui_objects, 2, &label_title);
	
	kiss_label_new (&label_subtitle, &window_menu, "A hybrid IF engine, lightyears ahead.", window_menu.rect.w / 2 - (kiss_textwidth (font_subtitle, "A hybrid IF engine, lightyears ahead.", NULL) / 2), label_title.rect.y + font_title.fontheight);
	label_subtitle.textcolor = kiss_white;
	label_subtitle.font = font_subtitle;
	kiss_array_append (&menu_gui_objects, 3, &label_subtitle);
	
	kiss_button_new (&button_playGame, &window_menu, "Play Game", window_menu.rect.w / 2 - kiss_normal.w / 2, label_subtitle.rect.y + kiss_buttonfont.fontheight + m_buttonPadding * 3);
	button_playGame.textcolor = kiss_white;
	kiss_array_append (&menu_gui_objects, 4, &button_playGame);
	
	kiss_button_new (&button_options, &window_menu, "Options", window_menu.rect.w / 2 - kiss_normal.w / 2, button_playGame.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
	button_options.textcolor = kiss_white;
	kiss_array_append (&menu_gui_objects, 5, &button_options);
	
	kiss_button_new (&button_about, &window_menu, "About", window_menu.rect.w / 2 - kiss_normal.w / 2, button_options.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
	button_about.textcolor = kiss_white;
	kiss_array_append (&menu_gui_objects, 6, &button_about);
	
	kiss_button_new (&button_quit, &window_menu, "Quit", window_menu.rect.w / 2 - kiss_normal.w / 2, button_about.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
	button_quit.textcolor = kiss_white;
	kiss_array_append (&menu_gui_objects, 7, &button_quit);
	
	window_menu.visible = 1;
	
	return 0;
}

void RenderingManager::DrawWindowMenu ()
{
	
	kiss_window_draw (&window_menu, m_renderer);
	kiss_renderimage (m_renderer, menu_background, 0, 0, NULL);
	
	kiss_label_draw (&label_title, m_renderer);
	kiss_label_draw (&label_subtitle, m_renderer);
	kiss_button_draw (&button_playGame, m_renderer);
	kiss_button_draw (&button_options, m_renderer);
	kiss_button_draw (&button_about, m_renderer);
	kiss_button_draw (&button_quit, m_renderer);
	kiss_label_draw (&label_version, m_renderer);
}


void RenderingManager::Update ()
{
	
	if (draw == 0)
		return;
	
	SDL_RenderClear (m_renderer);
	DrawWindowMenu ();
	SDL_RenderPresent (m_renderer);
	draw = 0;
}


void RenderingManager::Stop ()
{
	
	kiss_clean (&objects);
}