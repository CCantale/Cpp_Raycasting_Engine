/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Texture.hpp                                           by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef TEXTURE_HPP
# define TEXTURE_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <string>
# include "../Renderer/Renderer.hpp"

class	Texture
{
	public:
				Texture(void);
				Texture(std::string const &path);
				Texture(std::string const &path, int x, int y);
				Texture(Texture const &toCopy);
				~Texture(void);
		Texture		&operator=(Texture const &toCopy);
		void		setTexture(std::string const &path);
		void		setPos(int x, int y);
		void		setDimentions(int w, int h);
		SDL_Rect const	&getRect(void);
		SDL_Texture	*getTexture(void);
		void		render(void);
		void		clear(void);

	private:
		std::string	_path;
		SDL_Texture	*_texture;
		SDL_Rect	_rect;
};

#endif
