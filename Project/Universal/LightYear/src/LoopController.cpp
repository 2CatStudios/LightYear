#include "LoopController.h"


int LoopController::CoreLoop ()
{
	
	if (StartSDL () != 0)
	{
		
		std::cout << "Unable to start SDL! [LoopController.cpp - int StartMainLoop() : 10]" << std::endl;
		return 1;
	}
	
	logicDelegate.Initialize ();
	renderManager.Initialize ();
	
	
	while (m_mainLoop == true)
	{
		
		if (EventsLogicRendering () != 0)
		{
			
			std::cout << "Error in CoreLoop! [LoopController.cpp - int StartMainLoop() : 21]" << std::endl;
			windowManager.ShutdownSDL ();
			return 1;
		}
	}
	
	renderManager.Destroy ();
	windowManager.ShutdownSDL ();
	return 0;
}


int LoopController::StartSDL ()
{
	
	if (windowManager.InitializeSDL () != 0)
	{
		
		std::cout << "Unable to initialize SDL! [LoopController.cpp - int StartSDL() : 36]" << std::endl;
		return 1;
	}
	
	if (windowManager.CreateMainWindow () != 0)
	{
		
		std::cout << "Unable to create main window! [LoopController.cpp - int StartSDL() : 43]" << std::endl;
		return 1;
	}
	
	return 0;
}


int LoopController::EventsLogicRendering ()
{
	
	/*
		0. Events - EventManager
		1. Logic
		2. Rendering
	*/
	
#pragma mark EVENT
	m_eventLoop = eventManager.PollInput (windowManager);
	
	switch (m_eventLoop)
	{
		
		case 0:
			break;
		
		case 1:
			return 1;
			break;
		
		case 2:
			m_mainLoop = false;
			std::cout << "quit" << std::endl;
			break;
	}
	
#pragma mark LOGIC
	m_logicLoop = logicDelegate.PLACEHOLDERFUNCTION (renderManager);
	
	if (m_logicLoop != 0)
	{
		
		return 1;
	}
	
#pragma mark RENDER
	if (renderManager.FrameUpdate () == true)
	{
		
		m_renderLoop = renderManager.UpdateRenderer (windowManager);
		
		if (m_renderLoop != 0)
		{
			
			return 1;
		}
	}
	
	return 0;
}