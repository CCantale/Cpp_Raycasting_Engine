/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   main.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"
#include "Raycaster/Raycaster.hpp" // garbage

int	main(void)
{
	Game::init(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, FULLSCREEN);
	Map::init();
	Player::init();
	//garbage
	std::array<double, WINDOW_WIDTH>	walls = Raycaster::getWalls();
	Raycaster::activate();
	for(double &w: walls)
		std::cout << w << " ";
	// end of gatrbage
	while(Game::isRunning())
	{
		Time::calculateDelta();
		Game::handleEvents();
		Game::update();
	}
	Game::clear();
	return (0);
}
