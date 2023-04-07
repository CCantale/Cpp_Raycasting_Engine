/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Renderer.cpp                                          by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Renderer.hpp"

SDL_Renderer	*Renderer::_renderer;

void	Renderer::init(SDL_Window *window)
{
	_renderer = SDL_CreateRenderer(window, -1, 0);
	if (!_renderer)
		Game::quit();
}

SDL_Renderer	*Renderer::getRenderer(void)
{
	return (_renderer);
}
