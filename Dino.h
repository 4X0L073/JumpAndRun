#ifndef DINO_H
#define DINO_H

#include "GameObject.h"
#include "Terminal.h"
#include "Vec2D.h"

class Dino : public GameObject
{
public:
	Dino(Game* game, int x, int y, int width, int height, int dir);
	void update(float dt) override;
	void draw(Terminal& term, const Rectangle& camera) override;
	virtual bool isDead() const;
	virtual void jump(int dir);

	virtual void move(int dir); //move dino
	virtual bool isMoving();
	bool _isMoving; // is dino moving?
	bool _isJumping;
	int _velX;	//Velocity in x axis
	int _velY; // Velocity in y axis
	static const int WIDTH = 4;
	static const int HEIGHT = 3;
private:
	const short _speedLim=3;  //speed limit
	bool _isDead;
};

#endif // !DINO_H