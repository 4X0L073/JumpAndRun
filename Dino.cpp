#include "Dino.h"
#include "Game.h"

Dino::Dino(Game* game, int x, int y, int width, int height, int dir)
	: GameObject(game, x, y, width, height),
	_isMoving(false), //true if dino is moving
	_isJumping(false),
	_velX(0),
	_velY(0),
	_isDead(false) { }


bool Dino::isDead() const
{
	return _isDead;
}

bool Dino::isMoving() {
	return _velX;
}
void Dino::update(float dt)
{
	//this->x += _velX * static_cast<int>(_dir);

	//if (isMoving()) {
	//	this->x += _velX;
	//	//_isMoving = false;
	//}
	//else if (!isMoving()) {
		
	//}
	this->x += _velX;
	//if (abs(_velX <= 3))
	//	if (_velX > 2) x -= 1; //reduce speed
	//	else if (_velX < -2) x += 1;

	//
	_velY++;
	this->y += _velY;
	GameObject* floor = _game->floor();
 	if (floor->intersects(*this) || this->top() >= floor->bottom())
	{
		_velY = 0;
		this->y = _game->floor()->top() - Dino::HEIGHT;
		_isJumping = false;
	}
	for (auto& object: _game->obstacles())
	{
		if (object->intersects(*this))
		{
			_isDead = true;
		}
	}
}

void Dino::draw(Terminal& term, const Rectangle& camera)
{
	GameObject::draw(term, camera);
	
	attron(COLOR_PAIR(2));
	Vec2D screenCoords = upperLeft() - camera.upperLeft();
	
	term.draw_text(screenCoords.x, screenCoords.y, " O  ");
	term.draw_text(screenCoords.x, screenCoords.y+1, { '/','|',92 });
	//if (isMoving()) {
	//term.draw_text(screenCoords.x, screenCoords.y + 1, " | ");
	term.draw_text(screenCoords.x, screenCoords.y + 2,{ '/',' ',92 });
	// }

	attroff(COLOR_PAIR(2));
	

}

void Dino::move(int dir) {	
	if (dir != 0) {
		if (abs(_velX) < _speedLim)
			_velX += dir;
		else return;
		_isMoving = true;
	}
	else 
	{
		_velX = dir;
		_isMoving = false;
	}
}

void Dino::jump(int dir)
{
	if (_isMoving) {
		_velX += dir; //no effect
		_velY -= 5;
		_isJumping = true;
	}
	else if (_isMoving==false) {
		_velY -= 5;
		_isJumping = true;
	}
	//_isJumping = false; //enable multiple jumping
}