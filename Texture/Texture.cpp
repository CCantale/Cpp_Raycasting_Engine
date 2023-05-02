/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Texture.hpp                                           by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Texture.hpp"

Texture::Texture(void)
{
	this->_rect.x = 0;
	this->_rect.y = 0;
}

Texture::Texture(std::string const &path)
{
	this->_texture = IMG_LoadTexture(Renderer::get(), path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = 0;
	this->_rect.y = 0;
}

Texture::Texture(std::string const &path, int x, int y)
{
	this->_texture = IMG_LoadTexture(Renderer::get(), path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = x;
	this->_rect.y = y;
}

Texture::Texture(Texture const &toCopy)
{
	this->_texture = IMG_LoadTexture(Renderer::get(), toCopy._path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = toCopy._rect.x;
	this->_rect.y = toCopy._rect.y;
}

Texture::~Texture(void)
{
	this->clear();
}

Texture	&Texture::operator=(Texture const &toCopy)
{
	this->_texture = IMG_LoadTexture(Renderer::get(), toCopy._path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = toCopy._rect.x;
	this->_rect.y = toCopy._rect.y;
	return (*this);
}

void	Texture::setTexture(std::string const &path)
{
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
	this->_texture = IMG_LoadTexture(Renderer::get(), path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
}

void	Texture::setPos(int x, int y)
{
	this->_rect.x = x;
	this->_rect.y = y;
}

void	Texture::setDimentions(int w, int h)
{
	this->_rect.w = w;
	this->_rect.h = h;
}

SDL_Rect const	&Texture::getRect(void)
{
	return (this->_rect);
}

SDL_Texture	*Texture::getTexture(void)
{
	return (this->_texture);
}

void	Texture::render(void)
{
	SDL_RenderCopy(Renderer::get(), this->_texture, NULL, &this->_rect);
}

void	Texture::clear(void)
{
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
}
