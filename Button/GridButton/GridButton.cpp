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
	this->_color = { 0, 0, 0, 0 };
	this->_player = false;
	this->_playerTexture = new Texture("Logo/Ray.png",
				this->_texture->getRect().x, this->_texture->getRect().y);
	this->_playerTexture->setDimentions(this->getWidth(), this->getHeight());
}

GridButton::~GridButton(void)
{
	;
}

GridButton::GridButton(Texture *texture) : Button(texture)
{
	this->_color = { 0, 0, 0, 0 };
	this->_player = false;
	this->_playerTexture = new Texture("Logo/Ray.png",
				this->_texture->getRect().x, this->_texture->getRect().y);
	this->_playerTexture->setDimentions(this->getWidth(), this->getHeight());
}

GridButton::GridButton(Texture *texture, SDL_Color &color) : Button(texture)
{
	this->setColor(color);
	this->_player = false;
	this->_playerTexture = new Texture("Logo/Ray.png",
				this->_texture->getRect().x, this->_texture->getRect().y);
	this->_playerTexture->setDimentions(this->getWidth(), this->getHeight());
}

GridButton::GridButton(GridButton &toCopy) : Button(static_cast<Button &>(toCopy))
{
	this->setColor(toCopy._color);
	this->_player = toCopy._player;
	this->_playerTexture = new Texture(*toCopy._playerTexture);
}

GridButton	&GridButton::operator=(GridButton &toCopy)
{
	static_cast<Button>(*this) = static_cast<Button &>(toCopy);
	this->setColor(toCopy._color);
	this->_player = toCopy._player;
	return (*this);
}

SDL_Color	&GridButton::getColor(void)
{
	return (this->_color);
}

void	GridButton::setColor(SDL_Color &color)
{
	this->_color = color;
}

void	GridButton::activate(void)
{
	t_tool	tool;

	tool = Editor::getTool();
	switch (tool)
	{
		case (WALL):
			this->on();
			break ;
		case (PLAYER):
			if (!this->_player && !this->_active)
			{
				this->_player = true;
			}
			else
				this->_player = false;
			break ;
		case (ERASER):
			this->off();
			break ;
	}
}

void	GridButton::render(void)
{
	this->Button::render();
	if (this->_active)
	{
		SDL_SetRenderDrawColor(Renderer::get(), _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(Renderer::get(), &this->_texture->getRect());
	}
	if (this->_player)
		this->_playerTexture->render();
}
