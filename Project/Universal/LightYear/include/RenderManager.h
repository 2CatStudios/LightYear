#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "cleanup.h"

#include "WindowManager.h"


class StoryRenderer
{
public:
	SDL_Surface *storySurface;
	SDL_Texture* storyTexture;
	SDL_Rect storyRect;
	
	bool updateStory = true;
};


class RenderManager
{
	
public:
	void Initialize ();
	void Destroy ();
	bool FrameUpdate ();
	int UpdateRenderer (WindowManager &windowManager);
	
	StoryRenderer storyRenderer;
	
	char RANDOMCSTRING[7];

private:
	
	const char m_font[25] = "/Library/Fonts/Arial.ttf";
	TTF_Font *m_prettyWhiteFont;
	
	SDL_Color m_colourWhite = {255, 255, 255};
	SDL_Color m_colourLightGrey = {192, 192, 192};
	SDL_Color m_colourDarkGrey = {64, 64, 64};
	SDL_Color m_colourBlack = {0, 0, 0};

	int RenderStory (WindowManager &windowManager);
};


#endif //RENDERMANAGER_H