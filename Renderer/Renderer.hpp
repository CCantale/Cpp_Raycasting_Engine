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
# include "../common.h"
# include "../Game/Game.hpp"

class	Renderer
{
	public:
		static void		init(SDL_Window *window);
		static SDL_Renderer	*get(void);
		static void		drawWalls(void);

	private:
		static SDL_Renderer	*_renderer;
};

#endif
