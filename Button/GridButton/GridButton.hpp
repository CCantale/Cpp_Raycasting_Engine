/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   GridButton.hpp                                        by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef GRIDBUTTON_HPP
# define GRIDBUTTON_HPP

# include "../Button.hpp"

class	GridButton : public Button
{
	public:
				GridButton(void);
				~GridButton(void);
				GridButton(Texture *texture);
				GridButton(Texture *texture, SDL_Color &color);
				GridButton(GridButton &toCopy);
		GridButton	&operator=(GridButton &toCopy);
		void		on(void);
		void		off(void);
		bool		isActive(void);
		SDL_Color	&getColor(void);
		void		setColor(SDL_Color &color);
		void		activate(void);
		void		render(void);
	
	private:
		bool		_active;
		SDL_Color	_color;
};

#endif
