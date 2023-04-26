/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   main.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"

void	init_everything(void)
{
	Game::init(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, FULLSCREEN);
	Map::init();
	Player::init();
	Keys::init();
}

int	main(void)
{
	init_everything();
	while(Game::isRunning())
	{
		Time::calculateDelta();
		Game::handleEvents();
		Game::update();
	}
	Game::clear();
	return (0);
}
