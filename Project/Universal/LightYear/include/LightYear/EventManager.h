#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "WindowManager.h"


class EventManager
{
	
public:
	int PollInput (WindowManager &windowManager);

private:
	SDL_Event m_event;
	
};

#endif //EVENTMANAGER_H