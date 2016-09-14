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

		//TODO: DRY!
		switch (uiManager->menuState)
		{
		
			case UIManager::NONE:
				break;
		
			case UIManager::MAINMENU:
				m_MainMenuWindowInput (quit);
				break;
		
			case UIManager::SELECTGAME:
				m_SelectGameWindowInput ();
				break;
		
			case UIManager::OPTIONS:
				m_OptionsWindowInput ();
				break;
		
			case UIManager::ABOUT:
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
	
	kiss_window_event ((kiss_window*) kiss_array_data (uiManager->mainMenu.gui_objects_array (), 0), &m_event, &renderingManager->draw);
	kiss_window_event ((kiss_window*) kiss_array_data (uiManager->mainMenu.gui_objects_array (), 4), &m_event, &renderingManager->draw);
	m_mainmenu_window_menu_event (&m_event, &renderingManager->draw);
	m_mainmenu_button_playGame_event ((kiss_button*) kiss_array_data (uiManager->mainMenu.gui_objects_array (), 5), &m_event, &renderingManager->draw);
	m_mainmenu_button_options_event ((kiss_button*) kiss_array_data (uiManager->mainMenu.gui_objects_array (), 6), &m_event, &renderingManager->draw);
	m_mainmenu_button_about_event ((kiss_button*) kiss_array_data (uiManager->mainMenu.gui_objects_array (), 7), &m_event, &renderingManager->draw);
	m_mainmenu_button_quit_event ((kiss_button*) kiss_array_data (uiManager->mainMenu.gui_objects_array (), 8), &m_event, &quit, &renderingManager->draw);
}


void InputManager::m_SelectGameWindowInput ()
{
	
	//kiss_window_event ((kiss_window*) kiss_array_data (&uiManager->selectgameMenu.gui_objects, 0), &m_event, &renderingManager->draw);
	m_selectgamemenu_window_menu_event (&m_event, &renderingManager->draw);
	m_selectgamemenu_button_back_event ((kiss_button*) kiss_array_data (uiManager->selectgameMenu.gui_objects_array (), 1), &m_event, &renderingManager->draw);
}


void InputManager::m_OptionsWindowInput ()
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (uiManager->optionsMenu.gui_objects_array (), 0), &m_event, &renderingManager->draw);
	m_optionsmenu_button_back_event ((kiss_button*) kiss_array_data (uiManager->optionsMenu.gui_objects_array (), 1), &m_event, &renderingManager->draw);
}


void InputManager::m_AboutWindowInput ()
{
	
	kiss_window_event ((kiss_window*) kiss_array_data (uiManager->aboutMenu.gui_objects_array (), 0), &m_event, &renderingManager->draw);
	m_aboutmenu_button_back_event ((kiss_button*) kiss_array_data (uiManager->aboutMenu.gui_objects_array (), 1), &m_event, &renderingManager->draw);
	m_aboutmenu_vscrollbar_event ((kiss_vscrollbar*) kiss_array_data (uiManager->aboutMenu.gui_objects_array (), 3), &m_event, &renderingManager->draw);
	m_aboutmenu_window_event ((kiss_vscrollbar*) kiss_array_data (uiManager->aboutMenu.gui_objects_array (), 3), &m_event, &renderingManager->draw);
}



/*MAIN MENU*/

void InputManager::m_mainmenu_window_menu_event (SDL_Event *e, int *draw)
{
	
	if (e->type == SDL_MOUSEMOTION)
	{
		
		m_mainmenu_scroll_y = uiManager->mainMenu.scroll_view_starting_y - (e->motion.y * 0.1);
		
		uiManager->mainMenu.scroll_view.rect.y = m_mainmenu_scroll_y;
		uiManager->CalculateMainMenuPositionsY ();
		*draw = 1;
	}
}


void InputManager::m_mainmenu_button_playGame_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		uiManager->menuState = UIManager::SELECTGAME;
	}
}


void InputManager::m_mainmenu_button_options_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		uiManager->menuState = UIManager::OPTIONS;
	}
}


void InputManager::m_mainmenu_button_about_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		uiManager->menuState = UIManager::ABOUT;
	}
}


void InputManager::m_mainmenu_button_quit_event (kiss_button *button, SDL_Event *e, int *quit, int *draw)
{
	
	if (kiss_button_event(button, e, draw))
	{
		
		*quit = 1;
	}
}



/*SELECT GAME MENU*/

void InputManager::m_selectgamemenu_window_menu_event (SDL_Event *e, int *draw)
{
	
	if (e->type == SDL_DROPFILE)
	{
		
		m_dropped_file_directory = e->drop.file;
		
		std::cout << "Dropped " << m_dropped_file_directory << std::endl;
		SDL_free (m_dropped_file_directory);
	}
}

void InputManager::m_selectgamemenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		uiManager->menuState = UIManager::MAINMENU;
	}
}



/*OPTIONS MENU*/

void InputManager::m_optionsmenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		uiManager->menuState = UIManager::MAINMENU;
	}
}



/*ABOUT MENU*/

void InputManager::m_aboutmenu_button_back_event (kiss_button *button, SDL_Event *e, int *draw)
{
	
	if (kiss_button_event (button, e, draw))
	{
		
		uiManager->menuState = UIManager::MAINMENU;
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
		
		double movement = uiManager->aboutMenu.scroll_view.rect.y;
		movement = -1 * e->wheel.y;// * 350;
		
		uiManager->aboutMenu.scroll_view.rect.y = movement;
		uiManager->CalculateAboutMenuPositionsY ();
		*draw = 1;
	}*/
}


void InputManager::m_aboutmenu_vscrollbar_event (kiss_vscrollbar *vscrollbar, SDL_Event *e, int *draw)
{
	
	if (kiss_vscrollbar_event (vscrollbar, e, draw))
	{
		
		double movement = uiManager->aboutMenu.scroll_view.rect.y;
		movement = -1 * vscrollbar->fraction * 350; //NOTE: 350 is an arbitrary number. //TODO: Calculate this, somehow.
		
		uiManager->aboutMenu.scroll_view.rect.y = movement;
		uiManager->CalculateAboutMenuPositionsY ();
	}
}