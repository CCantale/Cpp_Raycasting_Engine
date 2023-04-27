/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Editor.hpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef EDITOR_HPP
# define EDITOR_HPP

# include <array>
# include "../Map/Map.hpp"
# include "../Player/Player.hpp"

# define TOOLS_NBR	3

typedef enum	e_tool
{
	t_WALL,
	t_EMPTY,
	t_PLAYER
}		t_tool;

class	Editor
{
	public:
		static void	init(void); // chiedere grandezza mappa 
		static void	update(void);
		static void	selectTool(t_tool tool);
		//static void	drawWorkspace(void);

	private:
		static std::array<bool, TOOLS_NBR>	_tools;
};

#endif
