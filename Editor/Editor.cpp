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
	it = _buttons.begin() + THIRTY_BY_THIRTY;
	_buttons.insert(it, new Button("Editor/Images/30 x 30 pxl.png"));
	_buttons[THIRTY_BY_THIRTY]->setPos(
			(WINDOW_WIDTH - _buttons[THIRTY_BY_THIRTY]->getWidth()) / 2,
			(WINDOW_HEIGHT / 3) + 100);
	_running = true;
	_somethingHappened = true;
}

bool	Editor::isRunning(void)
{
	return (_running);
}

void	Editor::quit(void)
{
	for (Button *b : Editor::_buttons)
		delete (b);
	_running = false;
}

void	Editor::_render(void)
{
	Editor::_buttons[CHOOSE_MAPS_SIZE]->show();
	Editor::_buttons[THIRTY_BY_THIRTY]->show();
	for (Button *b : Editor::_buttons)
	{
		if (b->isVisible())
			b->render();
	}
	SDL_RenderPresent(Renderer::get());
}

void	Editor::update(void)
{
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
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Editor::quit();
						break ;
					default:
						break ;
				}
			default:
				break ;
		}
	}
}
