/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Time.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Time.hpp"

Uint32	Time::_lastTime = 0;
Uint32	Time::_deltaTime;

void	Time::calculateDelta(void)
{
	if (_lastTime == 0)
		_lastTime = SDL_GetTicks();
	_deltaTime = SDL_GetTicks() - _lastTime;
	_lastTime = SDL_GetTicks();
}

Uint32	Time::getDelta(void)
{
	return (_deltaTime);
}


