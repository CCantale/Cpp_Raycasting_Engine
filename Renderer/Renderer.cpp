/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Renderer.cpp                                          by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Renderer.hpp"

SDL_Renderer	*Renderer::_renderer = 0;

void	Renderer::init(SDL_Window *window)
{
	_renderer = SDL_CreateRenderer(window, -1, 0);
	if (!_renderer)
		Game::quit();
}

SDL_Renderer	*Renderer::get(void)
{
	return (_renderer);
}

static void 	drawBackground(void)
{
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderClear(Renderer::get());
}

void	Renderer::drawWalls(void)
{
	std::array<double, WINDOW_WIDTH> 	walls = Raycaster::getWalls();
	int					vertical_line_length;
	int					vertical_line_end;
	int					y;

	drawBackground();
	for (int x = 0; x < WINDOW_WIDTH; ++x)
	{
		if (walls[x] < 0)
		{
			SDL_SetRenderDrawColor(Renderer::get(), 175, 0, 0, 255);
			walls[x] *= -1;
		}
		else
		{
			SDL_SetRenderDrawColor(Renderer::get(), 230, 0, 0, 255);
		}
		vertical_line_length = static_cast<int>(WINDOW_HEIGHT / walls[x]);
		y = (WINDOW_HEIGHT - vertical_line_length) / 2;
		if (y < 0)
			y = 0;
		vertical_line_end = y + vertical_line_length;
		if (vertical_line_end >= WINDOW_HEIGHT)
			vertical_line_end = WINDOW_HEIGHT - 1;
		while (y <= vertical_line_end)
		{
			SDL_RenderDrawPoint(Renderer::get(), x, y);
			++y;
		}
	}
}
