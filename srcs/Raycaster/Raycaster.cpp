/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Raycaster.cpp                                         by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Raycaster.hpp"


static double	cast_next_ray(int ray_nbr);
static double	get_step_length(double ray_direction);
static double	cast_ray_get_wall_height(
	double direction[2], int closest_border_to_player[2], double step[2]);
static double	raycasting_algorithm(
	double closest_border_to_ray[2], short step_on_map[2],
	double step_length[2], int closest_border_to_player[2]);
/* end of static declarations */



std::array<double, WINDOW_WIDTH>	Raycaster::_walls;

std::array<double, WINDOW_WIDTH>	Raycaster::getWalls(void)
{
	return (_walls);
}

void	Raycaster::activate(void)
{
	for (int i = 0; i < WINDOW_WIDTH; ++i)
		_walls[i] = cast_next_ray(i);
}

static double	cast_next_ray(int ray_nbr)
{
	double	ray_val;
	double	ray_direction[2];
	int	closest_border_to_player[2];
	double	ray_step_length[2];

	ray_val = 2 * ray_nbr / (double)WINDOW_WIDTH - 1;
	ray_direction[X] = Player::getDirX() + Player::getCameraX() * ray_val;
	ray_direction[Y] = Player::getDirY() + Player::getCameraY() * ray_val;
	closest_border_to_player[X] = (int)Player::getPosX();
	closest_border_to_player[Y] = (int)Player::getPosY();
	ray_step_length[X] = get_step_length(ray_direction[X]);
	ray_step_length[Y] = get_step_length(ray_direction[Y]);
	return (cast_ray_get_wall_height(
			ray_direction,
			closest_border_to_player,
			ray_step_length
		));
}

static double	get_step_length(double ray_direction)
{
	if (ray_direction != 0)
		return (fabs(1 / ray_direction));
	else
		return (1e30);
}

/* If not specified, all names here are referring to the ray
** and to where it got so far, not to it's origin (player) */
static double	cast_ray_get_wall_height(
		double direction[2], int closest_border_to_player[2], double step[2])
{
	double	closest_border_to_ray[2];
	short	step_on_map[2];

	step_on_map[X] = 1;
	step_on_map[Y] = 1;
	if (direction[X] < 0)
		step_on_map[X] = -1;
	if (direction[Y] < 0)
		step_on_map[Y] = -1;
	if (direction[X] < 0)
		closest_border_to_ray[X] = (Player::getPosX()
				- closest_border_to_player[X]) * step[X];
	else
		closest_border_to_ray[X] = (closest_border_to_player[X]
				+ 1.0 - Player::getPosX()) * step[X];
	if (direction[Y] < 0)
		closest_border_to_ray[Y] = (Player::getPosY()
				- closest_border_to_player[Y]) * step[Y];
	else
		closest_border_to_ray[Y] = (closest_border_to_player[Y]
				+ 1.0 - Player::getPosY()) * step[Y];
	return (raycasting_algorithm(
			closest_border_to_ray,
			step_on_map, step,
			closest_border_to_player));
}

static double	raycasting_algorithm(
	double closest_border_to_ray[2], short step_on_map[2],
	double step_length[2], int closest_border_to_player[2])
{
	std::vector<std::string *>	map = Map::get();
	bool		hit;
	int		axis_hit;

	hit = false;
	while (hit == false)
	{
		if (closest_border_to_ray[X] < closest_border_to_ray[Y])
		{
			closest_border_to_ray[X] += step_length[X];
			closest_border_to_player[X] += step_on_map[X];
			axis_hit = X;
		}
		else
		{
			closest_border_to_ray[Y] += step_length[Y];
			closest_border_to_player[Y] += step_on_map[Y];
			axis_hit = Y;
		}
		if ((*map[closest_border_to_player[Y]])[closest_border_to_player[X]] == '1'
			|| (*map[closest_border_to_player[Y]])[closest_border_to_player[X]] == '0')
		{
			hit = true;
		}
	}
	if (axis_hit == X)
		return (closest_border_to_ray[axis_hit] - step_length[axis_hit]);
	else
		return (-closest_border_to_ray[axis_hit] + step_length[axis_hit]);
}

static void 	drawBackground(void)
{
	SDL_Rect	sky;
	SDL_Rect	floor;

	sky.x = 0;
	sky.y = 0;
	sky.w = WINDOW_WIDTH;
	sky.h = WINDOW_HEIGHT / 2;
	floor.x = 0;
	floor.y = WINDOW_HEIGHT / 2;
	floor.w = WINDOW_WIDTH;
	floor.h = WINDOW_HEIGHT / 2;
	SDL_SetRenderDrawColor(Renderer::get(), 0, 0, 0, 255);
	SDL_RenderDrawRect(Renderer::get(), &sky);
	SDL_RenderFillRect(Renderer::get(), &sky);
	SDL_SetRenderDrawColor(Renderer::get(), 35, 34, 33, 255);
	SDL_RenderDrawRect(Renderer::get(), &floor);
	SDL_RenderFillRect(Renderer::get(), &floor);
}

void	Raycaster::drawWalls(void)
{
	int					vertical_line_length;
	int					vertical_line_end;
	int					y;

	Raycaster::activate();
	drawBackground();
	for (int x = 0; x < WINDOW_WIDTH; ++x)
	{
		if (_walls[x] < 0)
		{
			SDL_SetRenderDrawColor(Renderer::get(), 175, 0, 0, 255);
			_walls[x] *= -1;
		}
		else
		{
			SDL_SetRenderDrawColor(Renderer::get(), 230, 0, 0, 255);
		}
		vertical_line_length = static_cast<int>(WINDOW_HEIGHT / _walls[x]);
		y = (WINDOW_HEIGHT - vertical_line_length) / 2;
		if (y < 0)
			y = 0;
		vertical_line_end = y + vertical_line_length;
		if (vertical_line_end >= WINDOW_HEIGHT)
			vertical_line_end = WINDOW_HEIGHT - 1;
		while (y <= vertical_line_end)
		{
			SDL_RenderDrawPoint(Renderer::get(), x, y);
			++y;
		}
	}
}
