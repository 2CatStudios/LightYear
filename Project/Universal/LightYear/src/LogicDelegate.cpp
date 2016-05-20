#include "LogicDelegate.h"


void LogicDelegate::Initialize ()
{
	
	m_distrobution = std::uniform_int_distribution<> (0, 9);
}


int LogicDelegate::PLACEHOLDERFUNCTION (RenderManager &renderManager)
{
	
	
	sprintf (renderManager.RANDOMCSTRING, "%d", RandomInt ());
	renderManager.storyRenderer.updateStory = true;
	return 0;
}


int LogicDelegate::RandomInt ()
{

	return m_distrobution (m_generator);
}