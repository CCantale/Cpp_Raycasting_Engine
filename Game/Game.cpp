/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Game.hpp"

bool		Game::_running;
SDL_Window	*Game::_window;

void	Game::init(char const *title, int _window_posX, int _window_posY,
		int width, int height, int fullscreen)
{
	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		// error
	}
	_window = SDL_CreateWindow(title, _window_posX, _window_posY, width,
			height, fullscreen);
	if (!_window)
	{
		// error
	}
	_running = true;
}

bool	Game::isRunning(void)
{
	return (_running);
}

void	Game::handleEvents(void)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			_running = false;
			break;
		default:
			break ;
	}
}

void	Game::update(void)
{
	// stuff to loop
}

void	Game::clear(void)
{
	SDL_DestroyWindow(_window);
	//Renderer::clear(); // in which to put IMG_Quit();
	SDL_Quit();
}
