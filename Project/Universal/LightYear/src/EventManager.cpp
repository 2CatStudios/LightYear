#include "EventManager.h"


int EventManager::PollInput (WindowManager &windowManager)
{
	
	while (SDL_PollEvent (&m_event) != 0)
	{
		
		if (SDL_PollEvent (&m_event))
		{
			
			switch (m_event.type)
			{
				
				case SDL_QUIT:
					return 2;
					break;
					
				case SDL_MOUSEBUTTONDOWN:
					break;
					
				case SDL_TEXTINPUT:
					break;
		    }
		}
	}
	
	return 0;
}