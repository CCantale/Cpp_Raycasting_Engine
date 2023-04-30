/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Editor.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Editor.hpp"

bool				Editor::_running;
bool				Editor::_somethingHappened;
std::vector<Button *>		Editor::_buttons;
std::array<bool, TOOLS_NBR>	Editor::_tools = { false, false, false };

void	Editor::init(void)
{
	std::vector<Button *>::iterator	it;

	it = _buttons.begin() + CHOOSE_MAPS_SIZE;
	_buttons.insert(it, new Button("Editor/Images/Choose map's size.png"));
	_buttons[CHOOSE_MAPS_SIZE]->setPos(
			(WINDOW_WIDTH - _buttons[CHOOSE_MAPS_SIZE]->getWidth()) / 2,
			WINDOW_HEIGHT / 3
			);
	_buttons[CHOOSE_MAPS_SIZE]->setAction(&sizesShowHide);
	it = _buttons.begin() + THIRTY_BY_THIRTY;
	_buttons.insert(it, new Button("Editor/Images/30 x 30 pxl.png"));
	_buttons[THIRTY_BY_THIRTY]->setPos(
			(WINDOW_WIDTH - _buttons[THIRTY_BY_THIRTY]->getWidth()) / 2,
			(WINDOW_HEIGHT / 3) + 100);
	_buttons[THIRTY_BY_THIRTY]->setAction(&Editor::start);
	_running = true;
	_somethingHappened = true;
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
	Editor::clearButtons();
	_running = false;
}

void	Editor::_render(void)
{
	Editor::_buttons[CHOOSE_MAPS_SIZE]->show();
	for (Button *b : Editor::_buttons)
	{
		if (b->isVisible())
			b->render();
	}
	SDL_RenderPresent(Renderer::get());
}

void	Editor::update(void)
{
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderClear(Renderer::get());
	if (_somethingHappened == true)
	{
		_render();
		_somethingHappened = false;
	}
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
							_somethingHappened = true;
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
						_somethingHappened = true;
					}
					if (b->isThere(event.motion.x, event.motion.y) == false
						&& b->isVisible() && b->isUnder())
					{
						b->lowlight();
						_somethingHappened = true;
					}
				}
				break ;
			default:
				break ;
		}
	}
}

void	Editor::sizesShowHide(void)
{
	if (_buttons[THIRTY_BY_THIRTY]->isVisible() == false)
		_buttons[THIRTY_BY_THIRTY]->show();
	else
		_buttons[THIRTY_BY_THIRTY]->hide();
}

void	Editor::start(void)
{
	Editor::clearButtons();
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderClear(Renderer::get());
}
