#ifndef _BOXOBSTACLE_H
#define _BOXOBSTACLE_H
#include "Vec2D.h"
#include "Game.h"

class BoxObstacle : public GameObject
{
public:
	BoxObstacle(Game* game, int x, int y, int width, int height);

	/*virtual */void draw(Terminal& term, const Rectangle& camera);
	
};
		

#endif
