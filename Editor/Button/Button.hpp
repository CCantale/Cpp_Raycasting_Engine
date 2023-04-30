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
# include <string>
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
		void		setAction(void (*action)(void));
		void		setHighlightColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		int		getWidth(void);
		int		getHeight(void);
		bool		isThere(int x, int y);
		void		show(void);
		void		hide(void);
		bool		isVisible(void);
		void		highlight(void);
		void		lowlight(void);
		bool		isUnder(void);
		void		render(void);
		void		activate(void);

	private:
		SDL_Texture	*_texture;
		std::string  	_texturePath;
		SDL_Rect	_rect;
		SDL_Color	_hlColor;
		bool		_visible;
		bool		_underCursor;

		void		(*_action)(void) = NULL;
};

#endif
