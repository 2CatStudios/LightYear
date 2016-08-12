#ifndef CORELOOPDELEGATE_H
#define CORELOOPDELEGATE_H

#include <iostream>

#include "LocalizationManager.h"
#include "InputManager.h"
#include "RenderingManager.h"
#include "kiss_sdl.h"

#define YES 1
#define NO 0


class CoreLoopDelegate
{

public:
	LocalizationManager localizationManager;
	InputManager inputManager;
	RenderingManager renderingManager;
	
	int quit = NO;
	
	int Run ();

private:
	
	int m_millisecondLoopDelay = 16;

	void m_DebugSDL2Paths ();
	int m_Loop ();
	
};

#endif /* end of include guard: CORELOOPDELEGATE_H */
