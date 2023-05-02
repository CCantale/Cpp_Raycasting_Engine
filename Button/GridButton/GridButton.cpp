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

GridButton::GridButton(std::string const &texturePath)
		: Button(texturePath)
{
	this->_color.r = 0;
	this->_color.g = 0;
	this->_color.b = 0;
	this->_color.a = 0;
	this->_active = false;
}

GridButton::GridButton(std::string const &texturePath, int x, int y)
		: Button(texturePath, x, y)
{
	this->_color.r = 0;
	this->_color.g = 0;
	this->_color.b = 0;
	this->_color.a = 0;
	this->_active = false;
}

GridButton::GridButton(std::string const &texturePath, int x, int y, SDL_Color &color)
		: Button(texturePath, x, y)
{
	this->_color.r = color.r;
	this->_color.g = color.g;
	this->_color.b = color.b;
	this->_color.a = color.a;
	this->_active = false;
}

GridButton::GridButton(GridButton &toCopy)
				: Button(static_cast<Button &>(toCopy))
{
	this->_color.r = toCopy._color.r;
	this->_color.g = toCopy._color.g;
	this->_color.b = toCopy._color.b;
	this->_color.a = toCopy._color.a;
	this->_active = false;
}

GridButton	&GridButton::operator=(GridButton &toCopy)
{
	static_cast<Button>(*this) = static_cast<Button &>(toCopy);
	this->_color.r = toCopy._color.r;
	this->_color.g = toCopy._color.g;
	this->_color.b = toCopy._color.b;
	this->_color.a = toCopy._color.a;
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

void	GridButton::render(void)
{
	this->Button::render();
	if (this->_active)
	{
		SDL_SetRenderDrawColor(Renderer::get(), _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(Renderer::get(), &this->_texture->getRect());
	}
}
