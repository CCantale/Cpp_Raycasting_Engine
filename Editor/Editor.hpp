/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Editor.hpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef EDITOR_HPP
# define EDITOR_HPP

# include <SDL2/SDL_image.h>
# include <array>
# include <vector>
# include <cstdbool>
# include "../Button/Button.hpp"
# include "../Game/Game.hpp"
# include "../Map/Map.hpp"
# include "../Player/Player.hpp"
# include "../Texture/Texture.hpp"

# define TOOLS_NBR	3

typedef enum	e_tool
{
	t_WALL,
	t_FLOOR,
	t_PLAYER
}		t_tool;

typedef enum	e_texture
{
	CHOOSE_MAPS_SIZE,
	THIRTY_BY_THIRTY
}		t_texture;

class	Editor
{
	public:
		static void	init(void);
		static void	openingAnimation(void);
		static bool	isRunning(void);
		static void	clearButtons(void);
		static void	quit(void);
		static void	handleEvents(void);
		static void	update(void);
		static void	selectTool(t_tool tool);
		static void	sizesShowHide(void);
		static void	start(void);

	private:
		static bool				_running;
		static std::array<bool, TOOLS_NBR>	_tools;
		static std::vector<Button *>		_buttons;
		static Texture				*_logo;
		static SDL_Rect				*_map;

		static void				_render(void);
};

#endif
