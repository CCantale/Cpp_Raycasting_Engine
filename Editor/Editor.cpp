/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Editor.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Editor.hpp"

bool				Editor::_running;
int				Editor::_tileSize;
std::vector<Button *>		Editor::_buttons;
std::array<bool, TOOLS_NBR>	Editor::_tools = { false, false, false };
Texture				*Editor::_logo;
SDL_Rect			*Editor::_map = NULL;

void	Editor::init(void)
{
	std::vector<Button *>::iterator	it;

	Editor::openingAnimation(); // the EventPoll should start after this
	it = _buttons.begin() + CHOOSE_MAPS_SIZE;
	_buttons.insert(it, new Button("Editor/Images/Choose map's size.png"));
	_buttons[CHOOSE_MAPS_SIZE]->setPos(
			(WINDOW_WIDTH - _buttons[CHOOSE_MAPS_SIZE]->getWidth()) / 2,
			WINDOW_HEIGHT / 3
			);
	_buttons[CHOOSE_MAPS_SIZE]->setAction(&sizesShowHide);
	_buttons[CHOOSE_MAPS_SIZE]->show();
	it = _buttons.begin() + THIRTY_BY_THIRTY;
	_buttons.insert(it, new Button("Editor/Images/30 x 30 pxl.png"));
	_buttons[THIRTY_BY_THIRTY]->setPos(
			(WINDOW_WIDTH - _buttons[THIRTY_BY_THIRTY]->getWidth()) / 2,
			(WINDOW_HEIGHT / 3) + 100);
	_buttons[THIRTY_BY_THIRTY]->setAction(&Editor::start30);
	_running = true;
}

void	Editor::openingAnimation(void)
{
	int		alpha;

	_logo = new Texture("Logo/RayLogo.png");
	if (!_logo)
	{
		std::cerr << "Failed to load texture" << std::endl;
		return ;
	}
	_logo->setPos(WINDOW_WIDTH / 2 - _logo->getRect().w / 2, WINDOW_HEIGHT / 2 - _logo->getRect().h / 2 - 40);
	alpha = 0;
	while (_logo->getRect().y > 30)
	{
		Time::calculateDelta();
		SDL_RenderClear(Renderer::get());
		SDL_SetTextureAlphaMod(_logo->getTexture(), alpha);
		_logo->render();
		SDL_RenderPresent(Renderer::get());
		SDL_Delay(10);
		if (alpha == 255)
		{
			SDL_Delay(20);
		}
		if (alpha < 255)
			++alpha;
		else
			_logo->setPos(_logo->getRect().x, _logo->getRect().y - Time::getDelta() / 12);
	}
	SDL_RenderClear(Renderer::get());
	_logo->render();
}

bool	Editor::isRunning(void)
{
	return (_running);
}

void	Editor::clearButtons(void)
{
	for (Button *b : _buttons)
	{
		if (b->isVisible())
			b->hide();
		delete (b);
	}
	_buttons.clear();
}

void	Editor::quit(void)
{
	_running = false;
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderClear(Renderer::get());
	Editor::clearButtons();
	delete (_logo);
	if (_map)
		delete (_map);
}

void	Editor::_render(void)
{
	_logo->render();
	if (_map)
	{
		int	tile;

		tile = _map->h / _tileSize;
		SDL_SetRenderDrawColor(Renderer::get(), 255, 255, 255, 255);
		SDL_RenderDrawRect(Renderer::get(), _map);
		for (int y = _map->y + tile; y < _map->h + _map->y; y += tile)
			SDL_RenderDrawLine(Renderer::get(), _map->x, y, _map->x + _map->w - 1, y);
		for (int x = _map->x + tile; x < _map->w + _map->x; x += tile)
			SDL_RenderDrawLine(Renderer::get(), x, _map->y, x, _map->y + _map->h);

	}
	for (Button *b : _buttons)
	{
		if (b->isVisible())
			b->render();
	}
}

void	Editor::update(void)
{
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderClear(Renderer::get());
	_render();
	SDL_RenderPresent(Renderer::get());
}

void	Editor::handleEvents(void)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				Editor::quit();
				Game::quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Editor::quit();
						Game::quit();
						break ;
					default:
						break ;
				}
				break ;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					for (Button *b : _buttons)
					{
						if (b->isThere(event.button.x, event.button.y)
							&& b->isVisible())
						{
							b->activate();
						}
					}
				}
				break ;
			case SDL_MOUSEMOTION:
				for (Button *b : _buttons)
				{
					if (b->isThere(event.motion.x, event.motion.y)
						&& b->isVisible() && b->isUnder() == false)
					{
						b->highlight();
					}
					if (b->isThere(event.motion.x, event.motion.y) == false
						&& b->isVisible() && b->isUnder())
					{
						b->lowlight();
					}
				}
				break ;
			default:
				break ;
		}
	}
}

/* All the following should be in another file */

void	Editor::sizesShowHide(void) // this should not be in the class
{
	if (_buttons[THIRTY_BY_THIRTY]->isVisible() == false)
		_buttons[THIRTY_BY_THIRTY]->show();
	else
		_buttons[THIRTY_BY_THIRTY]->hide();
}

void	Editor::start30(void)
{
	_tileSize = 30;
	Editor::start();
}

static int	approx(int nbr, int approxTo, int headerSize)
{
	std::vector<int>		multiples;
	std::vector<int>::iterator	it;

	for (int m = 0; m < 1000; m += approxTo)
		multiples.push_back(m);
	it = multiples.begin();
	while (*it < nbr && it < multiples.end())
		++it;
	while (*it + headerSize > WINDOW_HEIGHT - 20)
		--it;
	return (*it);
}

static void	setMap(SDL_Rect *map, Texture *logo, int tileSize)
{
	int	headerSize	= logo->getRect().h + 50;
	int	w		= WINDOW_WIDTH - 40;
	int	h 		= WINDOW_HEIGHT - headerSize;
	int	side;

	side = approx(std::min(w, h), tileSize, headerSize); 
	map->w = side;
	map->h = side;
	map->x = (WINDOW_WIDTH - map->w) / 2;
	map->y = headerSize;
}

void	Editor::start(void)
{
	SDL_Rect	*map;

	Editor::clearButtons();
	map = new SDL_Rect;
	setMap(map, _logo, _tileSize);
	_map = map;

}
