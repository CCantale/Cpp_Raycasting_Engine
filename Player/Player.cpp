/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Player.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Player.hpp"

double		Player::_posX;
double		Player::_posY;
double		Player::_dirX;
double		Player::_dirY;
double		Player::_cameraX;
double		Player::_cameraY;
t_direction	Player::_movementDirection = NONE;

void	Player::init(void)
{
	std::vector<std::string *>	map;

	map = Map::get();
	for (size_t i = 0; i < map.size(); ++i)
	{
		for (size_t j = 0; j < map[i]->size(); ++j)
		{
			if ((*map[i])[j] == 'P')
				Player::updatePos(j, i);
		}
	}
	Player::updateDir(0, 1);
	Player::updateCamera(-FOV_SIZE, 0);
}

void	Player::update(void)
{
	if (_movementDirection != NONE)
		Player::move();
}

void	Player::move(void)
{
	std::vector<std::string *>	map;
	double				x;
	double				y;
	double				dirModX;
	double				dirModY;
	double				speed;

	map = Map::get();
	x = Player::getPosX();
	y = Player::getPosY();
	dirModX = Player::getDirX();
	dirModY = Player::getDirY();
	if (_movementDirection == BACKWARDS || _movementDirection == RIGHT)
		dirModX *= -1;
	if (_movementDirection == BACKWARDS || _movementDirection == LEFT)
		dirModX *= -1;
	speed = static_cast<double>(Time::getDelta()) * PLAYER_SPEED;
	if ((*map[static_cast<int>(y)])[static_cast<int>(x + dirModX * speed)] == ' '
			&& (*map[static_cast<int>(y + dirModY * speed)])[static_cast<int>(x)] == ' ')
	{
		Player::updatePos(x + dirModX * speed, y + dirModY * speed);
	}
}

void	Player::updatePos(double newX, double newY)
{
	if (newX > 0)
		_posX = newX;
	if (newY > 0)
		_posY = newY;
}

void	Player::updateDir(double newX, double newY)
{
	_dirX = newX;
	_dirY = newY;
}

void	Player::updateCamera(double newX, double newY)
{
	_cameraX = newX;
	_cameraY = newY;
}

double	Player::getPosX(void)
{
	return (_posX);
}

double	Player::getPosY(void)
{
	return (_posY);
}

double	Player::getDirX(void)
{
	return (_dirX);
}

double	Player::getDirY(void)
{
	return (_dirY);
}

double	Player::getCameraX(void)
{
	return (_cameraX);
}

double	Player::getCameraY(void)
{
	return (_cameraY);
}
