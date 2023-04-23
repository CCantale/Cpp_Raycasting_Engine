/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Keys.hpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef KEYS_HPP
# define KEYS_HPP

# include <array>
# include "../common.h"

# define KEYS_NBR	8

typedef enum	e_key
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D
}		t_key;

class	Keys
{
	public:
		static void				init(void);
		static void				down(t_key key);
		static void				up(t_key key);
		static std::array<bool, KEYS_NBR>	&get(void);

	private:
		static std::array<bool, KEYS_NBR>	_keys;
};

#endif
