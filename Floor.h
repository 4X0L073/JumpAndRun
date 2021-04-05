 #ifndef FLOOR_H
#define FLOOR_H

#include "GameObject.h"
class Floor : public GameObject
{
public:
	Floor(Game* game, int termHeight, int termWidth) : GameObject(game, 0, termHeight - 1, termWidth, 1) { }
	virtual void update(float dt);
	virtual void draw(Terminal& term, const Rectangle& camera);
};

#endif // !FLOOR_H
