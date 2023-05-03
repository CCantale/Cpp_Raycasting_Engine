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
# include "../Button/GridButton/GridButton.hpp"
# include "../Game/Game.hpp"
# include "../Map/Map.hpp"
# include "../Player/Player.hpp"
# include "../Texture/Texture.hpp"

# define TOOLS_NBR	3

typedef enum	e_tool
{
	WALL,
	PLAYER,
	ERASER
}		t_tool;

typedef enum	e_texture
{
	CHOOSE_MAPS_SIZE,
	THIRTY_BY_THIRTY
}		t_texture;

class	Editor
{
	public:
		static void				init(void);
		static void				openingAnimation(void);
		static bool				isRunning(void);
		static void				setTool(t_tool tool);
		static t_tool				getTool(void);
		static std::vector<Button *>		&getButtons(void);
		static void				clearButtons(void);
		static void				quit(void);
		static void				handleEvents(void);
		static void				update(void);
		static void				selectTool(t_tool tool);
		static void				start(void);

	private:
		static bool				_running;
		static int				_tilesPerSide;
		static std::array<bool, TOOLS_NBR>	_tools;
		static std::vector<Button *>		_buttons;
		static std::vector<Button *>		_toolButtons;
		static Texture				*_logo;
		static SDL_Rect				*_map;

		static void				_render(void);
		static void				_sizesShowHide(void);
		static void				_start30(void);
		static void				_makeToolButtons(void);
};

#endif
