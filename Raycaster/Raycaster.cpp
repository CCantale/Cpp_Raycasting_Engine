/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Raycaster.cpp                                         by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Raycaster.hpp"

std::array<double, WINDOW_WIDTH>	Raycaster::_walls;

std::array<double, WINDOW_WIDTH>	Raycaster::getWalls(void)
{
	return (_walls);
}

void	Raycaster::activate(void)
{
	for (auto &e: _walls)
		e = castNextRay();
}

double	Raycaster::castNextRay(void)
{
	// insert code here...
}
