/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.hpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef GAME_HPP
# define GAME_HPP

# include <SDL2/SDL.h>
# include "../common.h"
# include "../Renderer/Renderer.hpp"
# include "../Raycaster/Raycaster.hpp"
# include "../Map/Map.hpp"

class Game
{
	public:
		static void		init(char const *title, int window_posX,
						int window_posY, int width,
						int height, int fullscreen);
		static void		handleEvents(void);
		static void		update(void);
		static bool		isRunning(void);
		static void		quit(void);
		static void		clear(void);

	private:
		static bool		_running;
		static bool		_keyDown;
		static SDL_Window	*_window;
};

#endif
