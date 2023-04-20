/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Map.hpp                                               by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include "../Game/Game.hpp"

class Map
{
	public:
		static void				init(void);
		static std::vector<std::string *>		get(void);
		static void				clear(void);

	private:
		static std::vector<std::string *>	_map;
};

#endif
