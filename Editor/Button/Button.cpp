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
	setHighlightColor(35, 34, 33, 100);
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
	this->_underCursor = false;
	setHighlightColor(35, 34, 33, 100);
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
	setHighlightColor(35, 34, 33, 100);
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
	setHighlightColor(35, 34, 33, 100);
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
	setHighlightColor(35, 34, 33, 100);
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

void	Button::setAction(void (*action)(void))
{
	this->_action = action;
}

void	Button::setHighlightColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->_hlColor.r = r;
	this->_hlColor.g = g;
	this->_hlColor.b = b;
	this->_hlColor.a = a;
}

int	Button::getWidth(void)
{
	return (_rect.w);
}

int	Button::getHeight(void)
{
	return (_rect.h);
}

bool	Button::isThere(int x, int y)
{
	if (x >= this->_rect.x && x < this->_rect.x + this->_rect.w
		&& y >= this->_rect.y && y < this->_rect.y + this->_rect.h)
	{
		return (true);
	}
	return (false);
	std::cout << "no" << std::endl;
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

void	Button::highlight(void)
{
	this->_underCursor = true;
}

void	Button::lowlight(void)
{
	this->_underCursor = false;
}

bool	Button::isUnder(void)
{
	return (_underCursor);
}

void	Button::render(void)
{
	if (_underCursor)
	{
		SDL_SetRenderDrawColor(Renderer::get(), _hlColor.r, _hlColor.g, _hlColor.b, _hlColor.a);
		SDL_RenderFillRect(Renderer::get(), &this->_rect);
	}
	SDL_RenderCopy(Renderer::get(), this->_texture, NULL, &this->_rect);
}

void	Button::activate(void)
{
	if (_action)
		this->_action();
}
