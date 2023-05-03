/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Map.cpp                                               by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Map.hpp"

std::vector<std::string *>	Map::_map;

/*void	Map::init(void)
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
}*/

void	Map::init(void)
{
	std::vector<Button *>	buttons;
	std::string		topAndBottom;
	int			prevY;
	int			i;
	
	buttons = Editor::getButtons();
	_map.push_back(new std::string("0"));
	prevY = buttons[0]->getRect().y;
	i = 0;
	for (Button *b : buttons)
	{
		if (b->getRect().y > prevY)
		{
			_map[i]->push_back('0');
			prevY = b->getRect().y;
			++i;
			_map.push_back(new std::string("0"));
		}
		if (static_cast<GridButton *>(b)->getPlayer())
		{
			_map[i]->push_back('P');
		}
		else if (b->isActive())
		{
			_map[i]->push_back('1');
		}
		else
		{
			_map[i]->push_back(' ');
		}
	}
	_map[i]->push_back('0');
	for (int j = 0; j < static_cast<int>(_map[0]->size()); ++j)
		topAndBottom.push_back('0');
	_map.push_back(new std::string(topAndBottom));
	_map.insert(_map.begin(), new std::string(topAndBottom));
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
