/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Editor.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Editor.hpp"

bool				Editor::_running;
int				Editor::_tilesPerSide;
std::vector<Button *>		Editor::_buttons;
std::vector<Button *>		Editor::_toolButtons;
std::array<bool, TOOLS_NBR>	Editor::_tools;
Texture				*Editor::_logo;
SDL_Rect			*Editor::_grid = NULL;

void	Editor::init(void)
{
	std::vector<Button *>::iterator	it;

	Editor::openingAnimation();
	it = _buttons.begin() + CHOOSE_MAPS_SIZE;
	_buttons.insert(it, new Button(new Texture("Editor/Images/Choose map's size.png")));
	_buttons[CHOOSE_MAPS_SIZE]->setPos(
			(WINDOW_WIDTH - _buttons[CHOOSE_MAPS_SIZE]->getWidth()) / 2,
			WINDOW_HEIGHT / 3
			);
	_buttons[CHOOSE_MAPS_SIZE]->setAction(&Editor::_sizesShowHide);
	_buttons[CHOOSE_MAPS_SIZE]->show();
	it = _buttons.begin() + THIRTY_BY_THIRTY;
	_buttons.insert(it, new Button(new Texture("Editor/Images/30 x 30.png")));
	_buttons[THIRTY_BY_THIRTY]->setPos(
			(WINDOW_WIDTH - _buttons[THIRTY_BY_THIRTY]->getWidth()) / 2,
			(WINDOW_HEIGHT / 3) + 100);
	_buttons[THIRTY_BY_THIRTY]->setAction(&Editor::_start30);
	setTool(WALL);
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

void	Editor::setTool(t_tool tool)
{
	for (bool &t : _tools)
	{
		t = false;
	}
	_tools[tool] = true;
}

t_tool	Editor::getTool(void)
{
	for (int i = 0; i < TOOLS_NBR; ++i)
	{
		if (_tools[i] == true)
			return (static_cast<t_tool>(i));
	}
	/* there's always a true tool, so this one's just a formality */
	return (WALL);
}

std::vector<Button *>	&Editor::getButtons(void)
{
	return (_buttons);
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
	for (Button *b : _toolButtons)
	{
		if (b->isVisible())
			b->hide();
		delete (b);
	}
	_toolButtons.clear();
}

void	Editor::quit(void)
{
	Editor::clearButtons();
	delete (_logo);
	if (_grid)
		delete (_grid);
	_running = false;
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderClear(Renderer::get());
	SDL_RenderPresent(Renderer::get());
}

void	Editor::_render(void)
{
	_logo->render();
	if (_grid) // this will become Map::render();
	{
		int	tile;

		tile = _grid->h / _tilesPerSide;
		SDL_SetRenderDrawColor(Renderer::get(), 255, 255, 255, 255);
		SDL_RenderDrawRect(Renderer::get(), _grid);
		for (int y = _grid->y + tile; y < _grid->h + _grid->y; y += tile)
			SDL_RenderDrawLine(Renderer::get(), _grid->x, y, _grid->x + _grid->w, y);
		for (int x = _grid->x + tile; x < _grid->w + _grid->x; x += tile)
			SDL_RenderDrawLine(Renderer::get(), x, _grid->y, x, _grid->y + _grid->h);

	}
	for (Button *b : _toolButtons)
	{
		b->render();
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
						//for (std::string *s : Map::get())
							//std::cout << *s << std::endl;
						break ;
					default:
						break ;
				}
				break ;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					Keys::down(MOUSE_LEFT);
					for (Button *b : _buttons)
					{
						if (b->isThere(event.button.x, event.button.y)
							&& b->isVisible())
						{
							b->activate();
						}
					}
					for (unsigned long i = 0; i < _toolButtons.size(); ++i)
					{
						if (_toolButtons[i]->isThere(event.button.x, event.button.y))
						{
							setTool(static_cast<t_tool>(i));
						}
					}
				}
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					Keys::down(MOUSE_RIGHT);
					for (Button *b : _buttons)
					{
						if (dynamic_cast<GridButton *>(b)
							&& b->isThere(event.button.x, event.button.y))
						{
							b->off();
						}
					}
				}
				break ;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					Keys::up(MOUSE_LEFT);
				}
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					Keys::up(MOUSE_RIGHT);
				}
				break ;
			case SDL_MOUSEMOTION:
				for (Button *b : _buttons)
				{
					if (b->isThere(event.motion.x, event.motion.y)
						&& b->isVisible() && b->isUnder() == false)
					{
						b->highlight();
						if (dynamic_cast<GridButton *>(b) && Keys::get()[MOUSE_LEFT])
						{
							b->activate();
						}
						else if (dynamic_cast<GridButton *>(b) && Keys::get()[MOUSE_RIGHT])
						{
							b->off();
						}
					}
					if (b->isThere(event.motion.x, event.motion.y) == false
						&& b->isVisible() && b->isUnder())
					{
						b->lowlight();
					}
				}
				for (Button *b : _toolButtons)
				{
					if (b->isThere(event.motion.x, event.motion.y) && !b->isUnder())
					{
						b->highlight();
					}
					if (!b->isThere(event.motion.x, event.motion.y) && b->isUnder())
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

/* All the following should be in another file or even
** in the Map class (not the first two, in that case) */

void	Editor::_sizesShowHide(void) // this should not be in the class
{
	if (_buttons[THIRTY_BY_THIRTY]->isVisible() == false)
		_buttons[THIRTY_BY_THIRTY]->show();
	else
		_buttons[THIRTY_BY_THIRTY]->hide();
}

void	Editor::_start30(void)
{
	_tilesPerSide = 30;
	Editor::start();
}

void	Editor::_start20(void)
{
	_tilesPerSide = 20;
	Editor::start();
}

void	Editor::_start10(void)
{
	_tilesPerSide = 10;
	Editor::start();
}

void	Editor::_startGame(void)
{
	if (Map::init())
	{
		Player::init();
		Editor::quit();
	}
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

static void	setMap(SDL_Rect *map, Texture *logo, int tilesPerSide)
{
	int	headerSize	= logo->getRect().h + 50;
	int	w		= WINDOW_WIDTH - 40;
	int	h 		= WINDOW_HEIGHT - headerSize;
	int	side;

	side = approx(std::min(w, h), tilesPerSide, headerSize); 
	map->w = side;
	map->h = side;
	map->x = (WINDOW_WIDTH - map->w) / 2;
	map->y = headerSize;
}

void	Editor::_makeToolButtons(void)
{
	_toolButtons.push_back(new Button(new Texture("Editor/Images/Spray.png"), 20, 40,
						(_logo->getRect().x - 60) / 3,
						(_logo->getRect().x - 60)/ 3));
	_toolButtons.push_back(new Button(new Texture("Editor/Images/SprayG.png"),
							20 + _toolButtons[0]->getWidth() + 10, 40,
							(_logo->getRect().x - 60) / 3,
							(_logo->getRect().x - 60)/ 3));
	_toolButtons.push_back(new Button(new Texture("Editor/Images/SprayB.png"),
							20 + _toolButtons[0]->getWidth() * 2 + 20, 40,
							(_logo->getRect().x - 60) / 3,
							(_logo->getRect().x - 60)/ 3));
}

void	Editor::start(void)
{
	SDL_Color			tileColor;
	int				tileSize;
	std::vector<Button *>::iterator	it;

	Editor::clearButtons();
	_grid = new SDL_Rect;
	setMap(_grid, _logo, _tilesPerSide);
	tileSize = _grid->w / _tilesPerSide;
	tileColor = { 230, 0, 0, 255 };
	for (int y = _grid->y + 1; y < _grid->h + _logo->getRect().h + 50; y += tileSize)
	{
		for (int x = _grid->x + 1; x < (WINDOW_WIDTH - _grid->w) / 2 + _grid->w; x += tileSize) 
		{
			_buttons.push_back(new GridButton(
							new Texture(x, y,
								tileSize - 2,
								tileSize - 2),
							tileColor));
		}
	}
	_buttons.push_back(new Button(new Texture("Editor/Images/START.png",
							(WINDOW_WIDTH + _logo->getRect().w) / 2 + 10, 50)));
	it = _buttons.end() - 1;
	(*it)->setAction(&_startGame);
	for (Button *b : _buttons)
		b->show();
	_makeToolButtons();
}
