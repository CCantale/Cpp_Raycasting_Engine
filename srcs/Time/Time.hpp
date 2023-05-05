/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Time.hpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef TIME_HPP
# define TIME_HPP

# include <SDL2/SDL.h>
# include "../common.h"

class	Time
{
	public:
		static void		calculateDelta(void);
		static Uint32	 	getDelta(void);
	
	private:
		static Uint32		_deltaTime;
		static Uint32		_lastTime;
};

#endif


