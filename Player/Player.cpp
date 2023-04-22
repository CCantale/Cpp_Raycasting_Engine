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
			{
				Player::updatePos(j, i);
				(*map[i])[j] = ' ';
			}
		}
	}
	Player::updateDir(0, 1);
	Player::updateCamera(-FOV_SIZE, 0);
}

void	Player::update(void)
{
	std::array<bool, KEYS_NBR>	keys = Keys::get();

	if (keys[KEY_W] == true && keys[KEY_S] == false)
		_movementDirection = FORWARD;
	else if (keys[KEY_S] == true && keys[KEY_W] == false)
		_movementDirection = BACKWARDS;
	else if (keys[KEY_A] == true && keys[KEY_D] == false)
		_movementDirection = LEFT;
	else if (keys[KEY_D] == true && keys[KEY_A] == false)
		_movementDirection = RIGHT;
	else
		_movementDirection = NONE;
	if (_movementDirection != NONE)
		Player::move();
}

void	Player::move(void)
{
	std::vector<std::string *>	map;
	double				x;
	double				y;
	double				speed;
	int				dirModX = 1;
	int				dirModY = 1;

	map = Map::get();
	x = Player::getPosX();
	y = Player::getPosY();
	if (_movementDirection == BACKWARDS || _movementDirection == RIGHT)
		dirModX = -1;
	if (_movementDirection == BACKWARDS || _movementDirection == LEFT)
		dirModY = -1;
	speed = static_cast<double>(Time::getDelta()) / 1000 * PLAYER_SPEED;
	if ((*map[static_cast<int>(y)])[static_cast<int>(x + Player::getDirX() * speed)] == ' '
		&& (*map[static_cast<int>(y + Player::getDirY() * speed)])[static_cast<int>(x)] == ' ')
	{
		Player::updatePos(x + (Player::getDirX() * speed) * dirModX, y + (Player::getDirY() * speed) * dirModY);
		Game::somethingHappened();
	}
					//std::cout << speed << " " << Time::getDelta() << " " << PLAYER_SPEED << std::endl; // garbage
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
