/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Keys.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Keys.hpp"

std::array<bool, KEYS_NBR>	Keys::_keys;

void	Keys::init(void)
{
	for (auto it = _keys.begin(); it != _keys.end(); ++it)
		*it = false;
}

void	Keys::down(t_key k)
{
	_keys[k] = true;
	std::cout << "down " << k << std::endl;
}

void	Keys::up(t_key k)
{
	_keys[k] = false;
	std::cout << "up " << k << std::endl;
}

std::array<bool, KEYS_NBR>	&Keys::get(void)
{
	return (_keys);
}
