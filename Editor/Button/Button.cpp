/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Button.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Button.hpp"

Button::Button(void) : _texture(NULL), _texturePath("No texture")
{
	this->_rect.x = 0;
	this->_rect.y = 0;
}

Button::Button(std::string const &texturePath)
{
	this->_texturePath = texturePath;
	this->_texture = IMG_LoadTexture(Renderer::get(), texturePath.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = 0;
	this->_rect.y = 0;
	this->_visible = false;
}

Button::Button(std::string const &texturePath, int x, int y)
{
	this->_texturePath = texturePath;
	this->_texture = IMG_LoadTexture(Renderer::get(), texturePath.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = x;
	this->_rect.y = y;
	this->_visible = false;
}

Button::Button(Button &toCopy)
{
	this->_texturePath = toCopy._texturePath;
	this->_texture = IMG_LoadTexture(Renderer::get(), toCopy._texturePath.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = toCopy._rect.x;
	this->_rect.y = toCopy._rect.y;
	this->_visible = false;
}

Button	&Button::operator=(Button &toCopy)
{
	this->_texturePath = toCopy._texturePath;
	this->_texture = IMG_LoadTexture(Renderer::get(), toCopy._texturePath.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = toCopy._rect.x;
	this->_rect.y = toCopy._rect.y;
	this->_visible = false;
	return (*this);
}

Button::~Button(void)
{
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
}

int	Button::setTexture(std::string const &texturePath)
{
	this->_texturePath = texturePath;
	this->_texture = IMG_LoadTexture(Renderer::get(), texturePath.c_str());
	if (!this->_texture)
		return (-1);
	SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	return (0);
}

void	Button::setPos(int x, int y)
{
	this->_rect.x = x;
	this->_rect.y = y;
}

int	Button::getWidth(void)
{
	return (_rect.w);
}

int	Button::getHeight(void)
{
	return (_rect.h);
}

void	Button::show(void)
{
	this->_visible = true;
}

void	Button::hide(void)
{
	this->_visible = false;
}

bool	Button::isVisible(void)
{
	return (_visible);
}

void	Button::render(void)
{
	SDL_RenderCopy(Renderer::get(), this->_texture, NULL, &this->_rect);
}

