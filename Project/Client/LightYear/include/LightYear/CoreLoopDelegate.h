#ifndef CORELOOPDELEGATE_H
#define CORELOOPDELEGATE_H

#include "Global.h"
#include "LocalizationManager.h"
#include "InputManager.h"
#include "RenderingManager.h"
#include "FileManager.h"
#include "kiss_sdl.h"

#include <iostream>



class CoreLoopDelegate
{

public:
	LocalizationManager localizationManager;
	InputManager inputManager;
	RenderingManager renderingManager;
	FileManager fileManager;
	
	int quit = NO;
	
	int Run ();

private:
	
	int m_millisecondLoopDelay = 16;

	void m_DebugSDL2Paths ();
	int m_Loop ();
	
};

#endif /* end of include guard: CORELOOPDELEGATE_H */
