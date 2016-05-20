#ifndef LOGICDELEGATE_H
#define LOGICDELEGATE_H

#include <random>

#include "RenderManager.h"


class LogicDelegate
{
	
public:
	void Initialize ();
	int PLACEHOLDERFUNCTION (RenderManager &renderManager);

private:
	std::default_random_engine m_generator;
	std::uniform_int_distribution<> m_distrobution;
	int RandomInt ();
};


#endif /* end of include guard: LOGICDELEGATE_H */
