#include "WindowManager.h"


int WindowManager::InitializeSDL ()
{
	
	if (SDL_Init (SDL_INIT_VIDEO) != 0)
	{

		return 1;
	}
	
	if (TTF_Init() != 0)
	{
		
		SDL_Quit ();
		return 1;
	}
	
	return 0;
}


int WindowManager::CreateMainWindow ()
{
	
	SDL_DisplayMode displayMode;
	if (SDL_GetCurrentDisplayMode (0, &displayMode) != 0)
	{
		
		SDL_Quit ();
		return 1;
	}
	
	window = SDL_CreateWindow (MAIN_WINDOW_TITLE, ((displayMode.w / 2) - MAIN_WINDOW_WIDTH / 2), ((displayMode.h / 2) - MAIN_WINDOW_HEIGHT / 2), MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
	
		SDL_Quit ();
		return 1;
	}
	
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
	
		cleanup (window);
		SDL_Quit ();
		return 1;
	}
	
	return 0;
}


int WindowManager::ShutdownSDL ()
{
	
	TTF_Quit ();
	cleanup (renderer, window);
	SDL_Quit ();
	
	return 0;
}