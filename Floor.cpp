#include "Floor.h"
#include "Game.h"

void Floor::update(float dt)
{
	//if(_player)
	this->x/*++*/;
	this->width = _game->camera().width;
}
void Floor::draw(Terminal& term, const Rectangle& camera)
{
	GameObject::draw(term, camera);
	Vec2D screenCoords = upperLeft() - camera.upperLeft();
	for (int i = 0; i < camera.width; i++)
	{
		attron(COLOR_PAIR(2));
		term.draw_text(screenCoords.x + i, screenCoords.y, "*");
		attroff(COLOR_PAIR(2));
		
	}
}