#include "CoreLoopDelegate.h"


int CoreLoopDelegate::InitializeKISS ()
{
	
	kiss_array_new (&m_objects);
	m_renderer = kiss_init ("LightYear", &m_objects, 1024, 576);
	
	return 0;
}


int CoreLoopDelegate::CreateWindowMenu ()
{
	
	kiss_window_new (&m_window_menu, NULL, 0, 0, 0, kiss_screen_width, kiss_screen_height);
	
	
	kiss_label_new (&m_label_title, &m_window_menu, "LightYear", (m_window_menu.rect.w/2) - (kiss_textwidth (font_title, "LightYear", NULL) / 2), 10);
	m_label_title.textcolor = kiss_white;
	m_label_title.font = font_title;
	
	
	kiss_label_new (&m_label_subtitle, &m_window_menu, "A hybrid IF engine, lightyears ahead.", m_window_menu.rect.w / 2 - (kiss_textwidth (font_subtitle, "A hybrid IF engine, lightyears ahead.", NULL) / 2), m_label_title.rect.y + font_title.fontheight);
	m_label_subtitle.textcolor = kiss_white;
	m_label_subtitle.font = font_subtitle;
	
	
	kiss_button_new (&m_button_playGame, &m_window_menu, "Play Game", m_window_menu.rect.w / 2 - kiss_normal.w / 2, m_label_subtitle.rect.y + kiss_buttonfont.fontheight + m_buttonPadding * 3);
	m_button_playGame.textcolor = kiss_white;
	
	
	kiss_button_new (&m_button_options, &m_window_menu, "Options", m_window_menu.rect.w / 2 - kiss_normal.w / 2, m_button_playGame.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
	m_button_options.textcolor = kiss_white;
	
	
	kiss_button_new (&m_button_about, &m_window_menu, "About", m_window_menu.rect.w / 2 - kiss_normal.w / 2, m_button_options.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
	m_button_about.textcolor = kiss_white;
	
	
	kiss_button_new (&m_button_quit, &m_window_menu, "Quit", m_window_menu.rect.w / 2 - kiss_normal.w / 2, m_button_about.rect.y + kiss_buttonfont.fontheight + m_buttonPadding);
	m_button_quit.textcolor = kiss_white;
	
	
	kiss_label_new (&m_label_version, &m_window_menu, "Version 0.0.0d1", 4, 0);
	m_label_version.textcolor = kiss_white;
	m_label_version.font = kiss_textfont;
	
	m_window_menu.visible = 1;
	
	return 0;
}

void CoreLoopDelegate::DrawWindowMenu ()
{
	
	kiss_window_draw (&m_window_menu, m_renderer);
	kiss_renderimage (m_renderer, menu_background, 0, 0, NULL);
	
	kiss_label_draw (&m_label_title, m_renderer);
	kiss_label_draw (&m_label_subtitle, m_renderer);
	kiss_button_draw (&m_button_playGame, m_renderer);
	kiss_button_draw (&m_button_options, m_renderer);
	kiss_button_draw (&m_button_about, m_renderer);
	kiss_button_draw (&m_button_quit, m_renderer);
	kiss_label_draw (&m_label_version, m_renderer);
}


int CoreLoopDelegate::Run ()
{
	
	if (InitializeKISS () != 0)
		return 1;
	
	if (CreateWindowMenu () != 0)
		return 1;
	
	if (Loop () != 0)
		return 1;
	
	return 0;
}


int CoreLoopDelegate::Loop ()
{
	
	while (m_quit == 0)
	{
		
		SDL_Delay (m_millisecondLoopDelay);

#pragma mark input
		
		while (SDL_PollEvent(&m_event))
		{
			
			if (m_event.type == SDL_QUIT)
				m_quit = 1;
			
			kiss_window_event (&m_window_menu, &m_event, &m_draw);
			m_inputManager.button_playGame_event (&m_button_playGame, &m_event, &m_draw);
			m_inputManager.button_options_event (&m_button_options, &m_event, &m_draw);
			m_inputManager.button_about_event (&m_button_about, &m_event, &m_draw);
			m_inputManager.button_quit_event (&m_button_quit, &m_event, &m_quit, &m_draw);
			
		}

#pragma mark rendering
		
		if (m_draw == 0)
			continue;
		
		SDL_RenderClear (m_renderer);
		DrawWindowMenu ();
		SDL_RenderPresent (m_renderer);
		m_draw = 0;
	}
	
	kiss_clean (&m_objects);
	
	return 0;
}