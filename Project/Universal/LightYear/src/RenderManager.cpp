#include "RenderManager.h"


void RenderManager::Initialize ()
{
	
	m_prettyWhiteFont = TTF_OpenFont (m_font, 24);
}


void RenderManager::Destroy ()
{
	
	TTF_CloseFont (m_prettyWhiteFont);
}


bool RenderManager::FrameUpdate ()
{
	
	if (storyRenderer.updateStory == true)
		return true;
	else
		return false;
}


int RenderManager::UpdateRenderer (WindowManager &windowManager)
{
	
	if (RenderStory (windowManager) != 0)
	{
		
		std::cout << "Unable to create story surface or texture!" << std::endl;
	}
    
	if (SDL_QueryTexture (storyRenderer.storyTexture, NULL, NULL, &storyRenderer.storyRect.w, &storyRenderer.storyRect.h) != 0)
	{
		
		std::cout << "Unable to query texture!" << std::endl;
	}
    
	storyRenderer.storyRect.x = ((windowManager.MAIN_WINDOW_WIDTH / 2) - (storyRenderer.storyRect.w / 2));
	storyRenderer.storyRect.y = ((windowManager.MAIN_WINDOW_HEIGHT / 2) - (storyRenderer.storyRect.h / 2));
    
	SDL_RenderClear(windowManager.renderer);
	SDL_RenderCopy (windowManager.renderer, storyRenderer.storyTexture, NULL, &storyRenderer.storyRect);
	SDL_RenderPresent(windowManager.renderer);
	
	return 0;
}


int RenderManager::RenderStory (WindowManager &windowManager)
{
	
	storyRenderer.storySurface = TTF_RenderUTF8_Blended (m_prettyWhiteFont, RANDOMCSTRING, m_colourWhite);
	storyRenderer.storyTexture = SDL_CreateTextureFromSurface (windowManager.renderer, storyRenderer.storySurface);
	storyRenderer.updateStory = false;
	
	return 0;
}