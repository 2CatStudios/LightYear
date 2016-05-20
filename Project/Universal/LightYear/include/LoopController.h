#ifndef LOOPCONTROLLER_H
#define LOOPCONTROLLER_H

#include <iostream>

#include "WindowManager.h"

#include "EventManager.h"
#include "LogicDelegate.h"
#include "RenderManager.h"


class LoopController
{
	
public:
	WindowManager windowManager;
	
	EventManager eventManager;
	LogicDelegate logicDelegate;
	RenderManager renderManager;
	
	int CoreLoop ();

private:
	bool m_mainLoop = true;
	
	int m_eventLoop = true;
	int m_logicLoop = true;
	int m_renderLoop = true;
	
	int StartSDL ();
	int EventsLogicRendering ();
};

#endif //LOOPCONTROLLER_H