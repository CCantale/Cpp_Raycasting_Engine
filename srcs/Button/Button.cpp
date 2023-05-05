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
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(Texture *texture)
{
	this->_texture = texture;
	this->_visible = false;
	this->_underCursor = false;
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(Texture *texture, int x, int y, int w, int h)
{
	this->_texture = texture;
	this->_visible = false;
	this->_underCursor = false;
	this->setPos(x, y);
	this->setDimentions(w, h);
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(int x, int y, int w, int h)
{
	this->_texture = new Texture(x, y, w, h);
	this->_visible = false;
	this->_underCursor = false;
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(Button &toCopy)
{
	if (toCopy._texture)
		this->_texture = new Texture(toCopy.getTexture());
	this->_visible = false;
	this->_action = toCopy._action;
	this->_active = toCopy._active;
	setHighlightColor(35, 34, 33, 100);
}

Button	&Button::operator=(Button &toCopy)
{
	if (this->_texture)
		delete (this->_texture);
	this->_texture = new Texture(toCopy.getTexture());
	this->_visible = false;
	this->_action = toCopy._action;
	this->_active = toCopy._active;
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

SDL_Rect const	&Button::getRect(void)
{
	return (this->_texture->getRect());
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

void	Button::setDimentions(int w, int h)
{
	this->_texture->setDimentions(w, h);
}

void	Button::setAction(void (*action)(void))
{
	this->_action = action;
}

void	Button::setHighlightColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->_hlColor = { r, g, b, a };
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

void	Button::on(void)
{
	this->_active = true;
}

void	Button::off(void)
{
	this->_active = false;
}

bool	&Button::isActive(void)
{
	return (this->_active);
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
