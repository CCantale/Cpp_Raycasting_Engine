/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Renderer.hpp                                          by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef RENDERER_HPP
# define RENDERER_HPP

# include <SDL2/SDL.h>
# include <array>
# include "../common.h"
# include "../game_info.h"

class	Renderer
{
	public:
		static int		init(SDL_Window *window);
		static SDL_Renderer	*get(void);
		static void		drawWalls(void);

	private:
		static SDL_Renderer	*_renderer;
};

#endif
