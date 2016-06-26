#ifndef CORELOOPDELEGATE_H
#define CORELOOPDELEGATE_H

#include "InputManager.h"
#include "RenderingManager.h"
#include "kiss_sdl.h"


class CoreLoopDelegate
{

public:
	InputManager inputManager;
	RenderingManager renderingManager;
	
	int quit = 0;
	
	int Run ();

private:
	
	int m_millisecondLoopDelay = 16;

	int Loop ();
	
};

#endif /* end of include guard: CORELOOPDELEGATE_H */
