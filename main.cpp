/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   main.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"

int	main(void)
{
	Game::init(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, FULLSCREEN);
	while(Game::isRunning)
	{
		Time::getDelta();
		Game::handleEvents();
		Game::update();
	}
	Game::clear();
	return (0);
}
