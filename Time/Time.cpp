/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Time.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Time.hpp"

Uint32	Time::_lastTime;
Uint32	Time::_deltaTime;

void	Time::calculateDelta(void)
{
	if (_lastTime == 0)
		_lastTime = SDL_GetTicks();
	_deltaTime = SDL_GetTicks() - _lastTime;
}

Uint32	Time::getDelta(void)
{
	return (_deltaTime);
}


