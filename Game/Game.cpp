/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Game.hpp"

bool		Game::running;
SDL_Window	*Game::window;

void	Game::init(char const *title, int window_posX, int window_posY,
		int width, int height, int fullscreen)
{
	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		// error
	}
	window = SDL_CreateWindow(title, window_posX, window_posY, width,
			height, fullscreen);
	if (!window)
	{
		// error
	}
	running = true;
}

bool	Game::isRunning(void)
{
	return (running);
}

void	Game::handleEvents(void)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			running = false;
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
	SDL_DestroyWindow(window);
	Renderer::clear(); // in which to put IMG_Quit();
	SDL_Quit();
