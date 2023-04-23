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
t_direction	Player::_rotationDirection = NONE;

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

	/* forward - backwards movement */
	if (keys[KEY_W] == true && keys[KEY_S] == false)
		Player::move(FORWARD);
	else if (keys[KEY_S] == true && keys[KEY_W] == false)
		Player::move(BACKWARDS);

	/* left - right movement */
	if (keys[KEY_A] == true && keys[KEY_D] == false)
		Player::move(LEFT);
	else if (keys[KEY_D] == true && keys[KEY_A] == false)
		Player::move(RIGHT);

	/* rotation */
	if (keys[KEY_RIGHT] == true && keys[KEY_LEFT] == false)
		Player::rotate(RIGHT);
	else if (keys[KEY_LEFT] == true && keys[KEY_RIGHT] == false)
		Player::rotate(LEFT);
}

void	Player::move(t_direction dir)
{
	std::vector<std::string *>	map;
	double				x	= Player::getPosX();
	double				y	= Player::getPosY();
	double				dirModX	= Player::getDirX();
	double				dirModY	= Player::getDirY();
	double				speed;

	map = Map::get();
	if (dir == LEFT || dir == RIGHT)
	{
		dirModX = Player::getDirY();
		dirModY = Player::getDirX();
	}
	if (dir == BACKWARDS || dir == RIGHT)
		dirModX *= -1;
	if (dir == BACKWARDS || dir == LEFT)
		dirModY *= -1;
	speed = static_cast<double>(Time::getDelta()) * PLAYER_SPEED / 1000;
	if ((*map[static_cast<int>(y)])[static_cast<int>(x + dirModX * speed)] == ' '
		&& (*map[static_cast<int>(y + dirModY * speed)])[static_cast<int>(x)] == ' ')
	{
		Player::updatePos(x + dirModX * speed, y + dirModY * speed);
		Game::somethingHappened();
	}
}

void	Player::rotate(t_direction dir)
{
	double	speed;
	double	newDirX;
	double	newDirY;
	double	newCamX;
	double	newCamY;

	speed = static_cast<double>(Time::getDelta()) * ROTATION_SPEED / 1000;
	if (dir == LEFT)
		speed *= -1;
	newDirX = Player::getDirX() * std::cos(speed) - Player::getDirY() * std::sin(speed);
	newDirY = Player::getDirX() * std::sin(speed) + Player::getDirY() * std::cos(speed);
	newCamX = Player::getCameraX() * std::cos(speed) - Player::getCameraY() * std::sin(speed);
	newCamY = Player::getCameraX() * std::sin(speed) + Player::getCameraY() * std::cos(speed);
	Player::updateDir(newDirX, newDirY);
	Player::updateCamera(newCamX, newCamY);
	Game::somethingHappened();
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
