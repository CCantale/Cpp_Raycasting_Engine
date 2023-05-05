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
# include <cstdbool>
# include "../Map/Map.hpp"
# include "../Player/Player.hpp"
# include "../game_info.h"

# define X	0
# define Y	1

class	Raycaster
{
	public:
		static void				activate(void);
		static std::array<double, WINDOW_WIDTH>	getWalls(void);
		static void				drawWalls(void);

	private:
		static std::array<double, WINDOW_WIDTH>	_walls;
};

#endif
