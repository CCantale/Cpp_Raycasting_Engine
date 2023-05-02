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
# include "../Renderer/Renderer.hpp"
# include "../Texture/Texture.hpp"

class	Button
{
	public:
				Button(void);
				Button(std::string const &texturePath);
				Button(std::string const &texturePath, int x, int y);
				Button(Button &toCopy);
		virtual		~Button(void);
		Button		&operator=(Button &toCopy);
		Texture		&getTexture(void);
		int		getWidth(void);
		int		getHeight(void);
		int		setTexture(std::string const &texturePath);
		void		setPos(int x, int y);
		void		setDimentions(int w, int h);
		void		setAction(void (*action)(void));
		void		setHighlightColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		bool		isThere(int x, int y);
		void		show(void);
		void		hide(void);
		bool		isVisible(void);
		void		highlight(void);
		void		lowlight(void);
		bool		isUnder(void);
		virtual void	render(void);
		void		activate(void);

	protected:
		Texture		*_texture;
		SDL_Color	_hlColor;
		bool		_visible;
		bool		_underCursor;

		void		(*_action)(void) = NULL;
};

#endif
