/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Renderer.cpp                                          by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Renderer.hpp"

SDL_Renderer	*Renderer::_renderer = 0;

int	Renderer::init(SDL_Window *window)
{
	_renderer = SDL_CreateRenderer(window, -1, 0);
	if (!_renderer)
		return (-1);
	return (0);
}

SDL_Renderer	*Renderer::get(void)
{
	return (_renderer);
}

