/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Game.hpp"

bool		Game::_running = false;
bool		Game::_somethingHappened = true;
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
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
					Keys::down(KEY_UP);
					break ;
				case SDLK_DOWN:
					Keys::down(KEY_DOWN);
					break ;
				case SDLK_LEFT:
					Keys::down(KEY_LEFT);
					break ;
				case SDLK_RIGHT:
					Keys::down(KEY_RIGHT);
					break ;
				case SDLK_w:
					Keys::down(KEY_W);
					break ;
				case SDLK_a:
					Keys::down(KEY_A);
					break ;
				case SDLK_s:
					Keys::down(KEY_S);
					break ;
				case SDLK_d:
					Keys::down(KEY_D);
					break ;
				case SDLK_ESCAPE:
					_running = false;
					break ;
			}
			break ;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
					Keys::up(KEY_UP);
					break ;
				case SDLK_DOWN:
					Keys::up(KEY_DOWN);
					break ;
				case SDLK_LEFT:
					Keys::up(KEY_LEFT);
					break ;
				case SDLK_RIGHT:
					Keys::up(KEY_RIGHT);
					break ;
				case SDLK_w:
					Keys::up(KEY_W);
					break ;
				case SDLK_a:
					Keys::up(KEY_A);
					break ;
				case SDLK_s:
					Keys::up(KEY_S);
					break ;
				case SDLK_d:
					Keys::up(KEY_D);
					break ;
			}
			break ;
		default:
			break ;
	}
}

void	Game::somethingHappened(void)
{
	_somethingHappened = true;
}

void	Game::update(void)
{
	Player::update();
	if (_somethingHappened == true)
	{
		Raycaster::activate();
		Renderer::drawWalls();
		SDL_RenderPresent(Renderer::get());
		_somethingHappened = false;
	}
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
