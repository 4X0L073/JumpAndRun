#include "BoxObstacle.h"

BoxObstacle::BoxObstacle(Game* game, int x, int y, int width, int height) :
	GameObject(game, x, y, width, height) { };
	

void BoxObstacle::draw(Terminal& term, const Rectangle& camera)
{
	GameObject::draw(term, camera);
	Vec2D screenCoordinates = upperLeft() - camera.upperLeft();
	for (int i = 0; i < width; i++)
	{
		
		for (int c = 0; c < height; c++)
		{
			attron(COLOR_PAIR(4));
			term.draw_text(screenCoordinates.x + i, screenCoordinates.y + c, "O");
			attroff(COLOR_PAIR(4));
		}
		
	}
}