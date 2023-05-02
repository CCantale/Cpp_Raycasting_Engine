/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   GridButton.cpp                                        by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "GridButton.hpp"

GridButton::GridButton(void) : Button()
{
	this->_color.r = 0;
	this->_color.g = 0;
	this->_color.b = 0;
	this->_color.a = 0;
	this->_active = false;
}

GridButton::~GridButton(void)
{
	;
}

GridButton::GridButton(Texture *texture) : Button(texture)
{
	this->_color.r = 0;
	this->_color.g = 0;
	this->_color.b = 0;
	this->_color.a = 0;
	this->_active = false;
}

GridButton::GridButton(Texture *texture, SDL_Color &color) : Button(texture)
{
	this->setColor(color);
	this->_active = false;
}

GridButton::GridButton(GridButton &toCopy) : Button(static_cast<Button &>(toCopy))
{
	this->setColor(toCopy._color);
	this->_active = false;
}

GridButton	&GridButton::operator=(GridButton &toCopy)
{
	static_cast<Button>(*this) = static_cast<Button &>(toCopy);
	this->setColor(toCopy._color);
	this->_active = toCopy._active;
	return (*this);
}

void	GridButton::on(void)
{
	this->_active = true;
}

void	GridButton::off(void)
{
	this->_active = false;
}

bool	GridButton::isActive(void)
{
	return (this->_active);
}

SDL_Color	&GridButton::getColor(void)
{
	return (this->_color);
}

void	GridButton::setColor(SDL_Color &color)
{
	this->_color.r = color.r;
	this->_color.g = color.g;
	this->_color.b = color.b;
	this->_color.a = color.a;
}

void	GridButton::activate(void)
{
	if (this->_active)
		this->off();
	else
		this->on();
}

void	GridButton::render(void)
{
	this->Button::render();
	if (this->_active)
	{
		SDL_SetRenderDrawColor(Renderer::get(), _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(Renderer::get(), &this->_texture->getRect());
	}
}
