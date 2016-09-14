#ifndef CORELOOPDELEGATE_H
#define CORELOOPDELEGATE_H

#include "Global.h"
#include "LocalizationManager.h"
#include "InputManager.h"
#include "RenderingManager.h"
#include "kiss_sdl.h"

class CoreLoopDelegate
{

public:
	LocalizationManager localizationManager;
	InputManager inputManager;
	RenderingManager renderingManager;
	
	int quit = NO;
	
	int Run ();

private:
	
	int m_millisecond_loop_delay = 16;

	int m_Loop ();
	
};

#endif /* end of include guard: CORELOOPDELEGATE_H */
