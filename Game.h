#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "Terminal.h"
#include "GameObject.h"
#include "Dino.h"
#include "Floor.h"
#include "BoxObstacle.h"
class Game
{
private:
    enum class MoveDirection  //temporary directions to assing to dino
    {
        LEFT = -1,      
        NONE,
        RIGHT,
        UP,
        DOWN
    };

public:
    Game(Terminal& term);
    bool isDone() const;
    void update(float dt);
    void draw();

    std::vector<GameObject*> obstacles() const;
    Dino* player() const;
    GameObject* floor() const;

    Rectangle camera() const;
    virtual ~Game();
private:
    float _elapsedTime;
    int _score;
    int _gameOver;
    bool _isDone;
    Terminal _term; 
    GameObject* _floor = nullptr;
    Dino* _player = nullptr;
    std::vector<GameObject*> _obstacles;
    Rectangle _camera;
    int _lastObstacleX;
    const int minDistanceBetweenObstacles = 10;
    const int maxDistanceBetweenObstacles = 40;
    GameObject* _newObstacle();
    void _reset();
    void _releaseResources();

    void drawGameOver();
};

#endif // !GAME_H