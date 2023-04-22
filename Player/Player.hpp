/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Player.hpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../Map/Map.hpp"
# include "../game_info.h"

class	Player
{
	public:
		static void	init(void);
		static double	getPosX(void);
		static double	getPosY(void);
		static double	getDirX(void);
		static double	getDirY(void);
		static double	getCameraX(void);
		static double	getCameraY(void);
		static void	updatePos(double newX, double newY);
		static void	updateDir(double newX, double newY);
		static void	updateCamera(double newX, double newY);

	private:
		static double	_posX;
		static double	_posY;
		static double	_dirX;
		static double	_dirY;
		static double	_cameraX;
		static double	_cameraY;
};

#endif
