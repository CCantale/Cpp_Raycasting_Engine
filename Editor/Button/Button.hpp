/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Button.hpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef BUTTON_HPP
# define BUTTON_HPP

# include <SDL2/SDL_image.h>
# include <SDL2/SDL.h>
# include "../../Renderer/Renderer.hpp"

class	Button
{
	public:
				Button(void);
				Button(std::string const &texturePath);
				Button(std::string const &texturePath, int x, int y);
				Button(Button &toCopy);
				~Button(void);
		Button		&operator=(Button &toCopy);
		int		setTexture(std::string const &texturePath);
		void		setPos(int x, int y);
		int		getWidth(void);
		int		getHeight(void);
		void		show(void);
		void		hide(void);
		bool		isVisible(void);
		void		render(void);

	private:
		std::string const	&_texturePath;
		SDL_Texture	*_texture;
		SDL_Rect	_rect;
		bool		_visible;
};

#endif
