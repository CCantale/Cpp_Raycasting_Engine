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
				GridButton(std::string const &texturePath);
				GridButton(std::string const &texturePath,
						int x, int y);
				GridButton(std::string const &texturePath,
						int x, int y, SDL_Color &color);
				GridButton(GridButton &toCopy);
		GridButton	&operator=(GridButton &toCopy);
		void		on(void);
		void		off(void);
		SDL_Color	&getColor(void);
		void		setColor(SDL_Color &color);
		void		render(void);
	
	private:
		bool		_active;
		SDL_Color	_color;
};

#endif
