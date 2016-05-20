#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "cleanup.h"

class WindowManager
{
	
public:
	int InitializeSDL ();
	int CreateMainWindow ();
	
	int ShutdownSDL ();
	
	SDL_Window *window;
	SDL_Renderer *renderer;
	
	const char MAIN_WINDOW_TITLE[24] = "LightYear";
	const int MAIN_WINDOW_WIDTH = 1024;
	const int MAIN_WINDOW_HEIGHT = 576;

private:

};

#endif //WINDOWMANAGER_H