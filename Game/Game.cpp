/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Game.hpp"

bool		Game::_running = false;
bool		Game::_keyDown = false;
SDL_Window	*Game::_window;

void	Game::init(char const *title, int _window_posX, int _window_posY,
		int width, int height, int fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL: Couldn't init" << std::endl;
		return ;
	}
	_window = SDL_CreateWindow(title, _window_posX, _window_posY, width,
			height, fullscreen);
	if (!_window)
	{
		std::cout << "SDL: Couldn't open window" << std::endl;
		SDL_Quit();
		return ;
	}
	Renderer::init(_window);
	SDL_RenderClear(Renderer::get());
	SDL_RenderPresent(Renderer::get());
	_running = true;
}

bool	Game::isRunning(void)
{
	return (_running);
}

void	Game::quit(void)
{
	_running = false;
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
		case SDL_KEYDOWN:
			_keyDown = true;
			break ;
		case SDL_KEYUP:
			_keyDown = false;
			break ;
		default:
			break ;
	}
}

void	Game::update(void)
{
	// stuff to loop
	Player::update();
	if (_keyDown == true)
	{
		Raycaster::activate();
		Renderer::drawWalls();
	}
	SDL_RenderPresent(Renderer::get());
}

void	Game::clear(void)
{
	SDL_DestroyWindow(_window);
	if (Renderer::get())
		SDL_DestroyRenderer(Renderer::get());
	Map::clear();
	// IMG_Quit();
	SDL_Quit();
}
