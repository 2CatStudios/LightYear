#include "InputManager.h"


int InputManager::GetInput (int &quit)
{
	
	while (SDL_PollEvent(&m_event))
	{
		
		if (m_event.type == SDL_QUIT)
		{
			quit = 1;
			break;
		}

		switch (renderingManager->menuState)
		{
		
			case RenderingManager::NONE:
				break;
		
			case RenderingManager::MAINMENU:
				m_MainMenuWindowInput (quit);
				break;
		
			case RenderingManager::SELECTGAME:
				if (renderingManager->selectgameMenu.created == true)
					m_SelectGameWindowInput ();
				break;
		
			case RenderingManager::OPTIONS:
				if (renderingManager->optionsMenu.created == true)
					m_OptionsWindowInput ();
				break;
		
			case RenderingManager::ABOUT:
				if (renderingManager->aboutMenu.created == true)
					m_AboutWindowInput ();
				break;
		
			default:
				break;
		}
	}
	
	return 0;
}


void InputManager::m_MainMenuWindowInput (int &quit)
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 0), &m_event, &renderingManager->draw);
	m_mainmenu_button_playGame_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 4), &m_event, &renderingManager->draw);
	m_mainmenu_button_options_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 5), &m_event, &renderingManager->draw);
	m_mainmenu_button_about_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 6), &m_event, &renderingManager->draw);
	m_mainmenu_button_quit_event ((kiss_button*) kiss_array_data (&renderingManager->mainMenu.gui_objects, 7), &m_event, &quit, &renderingManager->draw);
}


void InputManager::m_SelectGameWindowInput ()
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager->selectgameMenu.gui_objects, 0), &m_event, &renderingManager->draw);
	m_optionsmenu_button_back_event ((kiss_button*) kiss_array_data (&renderingManager->selectgameMenu.gui_objects, 1), &m_event, &renderingManager->draw);
}


//NOTE: One seg-fault crash
void InputManager::m_OptionsWindowInput ()
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager->optionsMenu.gui_objects, 0), &m_event, &renderingManager->draw);
	m_optionsmenu_button_back_event ((kiss_button*) kiss_array_data (&renderingManager->optionsMenu.gui_objects, 1), &m_event, &renderingManager->draw);
}


//NOTE: Two seg-fault crashs
void InputManager::m_AboutWindowInput ()
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager->aboutMenu.gui_objects, 0), &m_event, &renderingManager->draw);
	m_aboutmenu_button_back_event ((kiss_button*) kiss_array_data (&renderingManager->aboutMenu.gui_objects, 1), &m_event, &renderingManager->draw);
	m_aboutmenu_vscrollbar_event ((kiss_vscrollbar*) kiss_array_data (&renderingManager->aboutMenu.gui_objects, 3), &m_event, &renderingManager->draw);
	m_aboutmenu_window_event ((kiss_vscrollbar*) kiss_array_data (&renderingManager->aboutMenu.gui_objects, 3), &m_event, &renderingManager->draw);
	//kiss_window_event ((kiss_window*) kiss_array_data (&renderingManager->aboutMenu.gui_objects, 2), &m_event, &renderingManager->draw); //For tracking scroll-wheel
}


void InputManager::m_mainmenu_button_playGame_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		renderingManager->menuState = RenderingManager::SELECTGAME;
	}
}


void InputManager::m_mainmenu_button_options_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		renderingManager->menuState = RenderingManager::OPTIONS;
	}
}


void InputManager::m_mainmenu_button_about_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		renderingManager->menuState = RenderingManager::ABOUT;
	}
}


void InputManager::m_mainmenu_button_quit_event (kiss_button *button, SDL_Event *e, int *quit, int *draw)
{
	
	if (kiss_button_event(button, e, draw))
	{
		
		*quit = 1;
	}
}


void InputManager::m_optionsmenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		renderingManager->menuState = RenderingManager::MAINMENU;
	}
}


//NOTE: One seg-fault crash
void InputManager::m_aboutmenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		renderingManager->menuState = RenderingManager::MAINMENU;
	}
}


/*
> I would like to implement mouse scrolling on a textbox, do you have any tips for how to go about doing it?
 
How i think about doing it, is this. Overwrite the text box event function, and catch mouse scroll events. Then do anything only when textbox->array->length - textxtbox->maxlines >= 0 . Then when the scroll event is up, decrease the textbox1->firstline  by 1, but not to less than 0. And when the scroll event is down, increase the textbox1->firstline by one, but not to more than textbox->array->length - textxtbox->maxlines. And then *draw = 1. A kind of basic increase and decrease, with certain limits.
*/
void InputManager::m_aboutmenu_window_event (kiss_vscrollbar *vscrollbar, SDL_Event *e, int *draw)
{
	
	/*if (e->type == SDL_MOUSEWHEEL)
	{
		
		//std::cout << "MOUSEWHEEL EVENT" << std::endl;
		
		double movement = renderingManager->aboutMenu.scroll_view.rect.y;
		movement = -1 * e->wheel.y;// * 350;
		
		renderingManager->aboutMenu.scroll_view.rect.y = movement;
		renderingManager->CalculateAboutMenuPositionsY ();
		*draw = 1;
	}*/
}


void InputManager::m_aboutmenu_vscrollbar_event (kiss_vscrollbar *vscrollbar, SDL_Event *e, int *draw)
{
	
	if (kiss_vscrollbar_event (vscrollbar, e, draw))
	{
		
		double movement = renderingManager->aboutMenu.scroll_view.rect.y;
		movement = -1 * vscrollbar->fraction * 350;
		
		renderingManager->aboutMenu.scroll_view.rect.y = movement;
		renderingManager->CalculateAboutMenuPositionsY ();
	}
}