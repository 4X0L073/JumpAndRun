#include <iostream>
#include "Game.h"


Game::Game(Terminal& term) : _term(term)
{
    _reset();
}

bool Game::isDone() const
{
    return _isDone;
}


void Game::update(float dt)
{
    //MEVENT evt;
    //mouseinterval(-1);
    int pressed = wgetch(stdscr);
    switch (pressed)
    {
        // MOUSE ACTIONS
    //case KEY_MOUSE:
    //    if (nc_getmouse(&evt) == OK) {
    //        if(evt.bstate & BUTTON1_PRESSED)
    //            _player->move(1);                   //DOES NOT F*** WORKS
    //        else if(evt.bstate & BUTTON3_CLICKED)
    //            _player->move(-1);
    //    }

       
    // KEYBOARD ACTIONS   
    case 'w': //JUMP
		_player->jump(_player->_velX);
		break;
    case 'a': //LEFT
        _player->move(-1);
        //_camera.x = _player->x + _player->width;
        break;
    case 'e': //UP-RIGHT
        _player->move(1);
        _player->jump(_player->_velX);
        break;
    case 'q': //UP-LEFT
        _player->move(-1);
        _player->jump(_player->_velX);
        break;

    case 'd': //RIGHT
        _player->move(1);
       // _camera.x = _player->x + _player->width;
        break;
	case 'c':
		_reset();
		break;
	case 'x':
		_gameOver = true;
		_term.close();
		break;
	default:
        if(!_player->_isJumping)
        _player->move(0); //zum testen (ob player stopt)
		break;
	}
	_elapsedTime += dt;
	if (!_gameOver)
	{
		for (size_t i = 0; i < _obstacles.size(); i++)
		{
			GameObject* obj = _obstacles[i];
			if (obj->isInsideFrame() == false) {
				_obstacles.erase(_obstacles.begin(), _obstacles.begin() + 1);
				_obstacles.push_back(_newObstacle());
            }
			obj->update(dt);
		}
		_floor->update(dt);
		_player->update(dt);
     
	}

	if (_player->isDead())
		_gameOver = true;
	else
		_score++;
}


void Game::draw()
{

    _term.clear();
    if (!_gameOver) {
        _camera.width = _term.width();
        _camera.height = _term.height();
    }

    for each (GameObject * obj in _obstacles)
    {
        obj->draw(_term, _camera);
    }
    _floor->draw(_term, _camera);
    _player->draw(_term, _camera);

    _term.draw_text(0, 0, "_velX:"); //copy
    _term.draw_text(11, 0, std::to_string(_player->_velX)); //_score
    _term.draw_text(0, 2, "_velY"); //copy
    _term.draw_text(7, 2, std::to_string(_player->_velY)); //copy

    if (_gameOver) {
        drawGameOver();
        flash();
    }
    _term.sleep(20);

}

void Game::drawGameOver()
{
    std::string score_text = "Game Over! You got '" + std::to_string(_score) + "' points.";
    std::string reset_text = "Press 'c' to restart or x to quit.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size() / 2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size() / 2, half_height + 1, reset_text);

}

std::vector<GameObject*> Game::obstacles() const
{
    return _obstacles;
}

Dino* Game::player() const
{
    return _player;
}

GameObject* Game::floor() const
{
    return _floor;
}

Rectangle Game::camera() const
{
    return _camera;
}

GameObject* Game::_newObstacle()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis_x(Game::minDistanceBetweenObstacles, Game::maxDistanceBetweenObstacles);

    int x = _lastObstacleX + dis_x(gen);
    if (x < _camera.right()) x = _camera.right() + 1;
    int width = 2;
    _lastObstacleX = x + width;
    return new BoxObstacle(this, x, _floor->top() - 3, width, 3);
    
}

void Game::_reset()
{
    _releaseResources();

    _obstacles.clear();
    _elapsedTime = 0.f;
    _score = 0;
    _gameOver = false;
    _isDone = false;
    _camera = Rectangle(0, 0, _term.width(), _term.height());
    _lastObstacleX = 0;

    _floor = new Floor(this, _term.height(), _term.width());
    _player = new Dino(this, 2, _floor->top() - Dino::HEIGHT, Dino::WIDTH, Dino::HEIGHT,0);
    for (size_t i = 1; i < 5; i++)
    {
        GameObject* box = _newObstacle();
        _obstacles.push_back(box);

    }
}

Game::~Game()
{
    _releaseResources();
}

void Game::_releaseResources()
{
    for (size_t i = 0; i < _obstacles.size(); i++)
    {
        delete _obstacles[i];
    }
    delete _floor;
    delete _player;
}