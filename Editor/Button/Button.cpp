/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Button.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Button.hpp"

Button::Button(void)
{
	this->_texture = NULL;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(std::string const &texturePath)
{
	this->_texture = new Texture(texturePath);
	this->_visible = false;
	this->_underCursor = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(std::string const &texturePath, int x, int y)
{
	this->_texture = new Texture(texturePath);
	this->_texture->setPos(x, y);
	this->_visible = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(Button &toCopy)
{
	this->_texture = new Texture(toCopy.getTexture());
	this->_visible = false;
	setHighlightColor(35, 34, 33, 100);
}

Button	&Button::operator=(Button &toCopy)
{
	this->_texture = new Texture(toCopy.getTexture());
	this->_visible = false;
	setHighlightColor(35, 34, 33, 100);
	return (*this);
}

Button::~Button(void)
{
	if (this->_texture)
		delete (this->_texture);
}

Texture	&Button::getTexture(void)
{
	return (*this->_texture);
}

int	Button::getWidth(void)
{
	return (this->_texture->getRect().w);
}

int	Button::getHeight(void)
{
	return (this->_texture->getRect().h);
}

int	Button::setTexture(std::string const &texturePath)
{
	this->_texture = new Texture(texturePath);
	if (!this->_texture)
		return (-1);
	return (0);
}

void	Button::setPos(int x, int y)
{
	this->_texture->setPos(x, y);
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

bool	Button::isThere(int x, int y)
{
	SDL_Rect	rect;

	rect = this->_texture->getRect();
	if (x >= rect.x && x < rect.x + rect.w
		&& y >= rect.y && y < rect.y + rect.h)
	{
		return (true);
	}
	return (false);
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
		SDL_RenderFillRect(Renderer::get(), &this->_texture->getRect());
	}
	if (this->_texture)
		this->_texture->render();
}

void	Button::activate(void)
{
	if (_action)
		this->_action();
}
