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
# include <string>
# include <vector>
# include <cstdbool>
# include "../Game/Game.hpp"
//# include "../Editor/Editor.hpp"
# include "../Button/Button.hpp"
# include "../Button/GridButton/GridButton.hpp"

class Map
{
	public:
		static bool				init(void);
		static std::vector<std::string *>	&get(void);
		static void				clear(void);

	private:
		static std::vector<std::string *>	_map;
};

#endif
