#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Rectangle.h"
#include "Terminal.h"
#include <vector>

class Game;

class GameObject : public Rectangle 
{
	//friend Game;
protected:
	Game* _game;
	bool _isInsideFrame;
public:
	
	GameObject(Game* game, const Rectangle& rect) : 
		Rectangle(rect.x, rect.y, rect.width, rect.height), _game(game), _isInsideFrame(true) { }

	GameObject(Game* game, int x, int y, int width, int height) :
		Rectangle(x, y, width, height), _game(game) , _isInsideFrame(true) { }

	virtual void update(float dt) {}

	virtual void draw(Terminal& term, const Rectangle& camera)
	{
		_isInsideFrame = left() >= camera.left();
	}
	virtual bool isInsideFrame() const
	{
		return _isInsideFrame;
	}
};

#endif // !GAME_OBJECT_H
 