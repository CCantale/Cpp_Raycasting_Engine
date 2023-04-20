/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Map.cpp                                               by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Map.hpp"

std::vector<std::string *>	Map::_map;

void	Map::init(void)
{
	std::ifstream	input("Map/map");
	std::string	str;

	if (!input.is_open())
	{
		std::cerr << "Map file not found." << std::endl;
		Game::quit();
		return ;
	}
	while (!input.eof())
	{
		std::getline(input, str);
		if (!str.empty())
			_map.push_back(new std::string(str));
	}
	input.close();
}

std::vector<std::string *>	&Map::get(void)
{
	return (_map);
}

void	Map::clear(void)
{
	for (std::string *s: _map)
		delete (s);
}
