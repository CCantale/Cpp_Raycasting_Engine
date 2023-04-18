/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Raycaster.hpp                                         by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTER_HPP
# define RAYCASTER_HPP

# include <array>
# include "../Map/Map.hpp"
# include "../Player/Player.hpp"
# include "../game_info.h"

class	Raycaster
{
	public:
		static double				castNextRay(void);
		static std::array<double, WINDOW_WIDTH>	getWalls(void);

	private:
		static std::array<double, WINDOW_WIDTH>	_walls;
};

#endif
