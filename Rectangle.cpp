#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
{
}

Rectangle::Rectangle() : x(0), y(0), width(0), height(0) { }

Vec2D Rectangle::upperLeft() const
{
	return Vec2D(x, y);
}
Vec2D Rectangle::upperRight() const
{
	return Vec2D(x + width, y);
}
Vec2D Rectangle::lowerLeft() const
{
	return Vec2D(x, y + height);
}

Vec2D Rectangle::lowerRight() const
{
	return Vec2D(x + width, y + height);
}

int Rectangle::left() const
{
	return x;
}

int Rectangle::right() const
{
	return x + width;
}
int Rectangle::top() const
{
	return y;
}
int Rectangle::bottom() const
{
	return y + height;
}

bool Rectangle::intersects(const Rectangle& other) const
{
	return (
		left() < other.right() && 
		right() > other.left() && 
		top() < other.bottom() && 
		bottom() > other.top()
	);
}

bool Rectangle::contains(const Rectangle& other) const
{
	return other.left() > this->left() && 
		other.right() < this->right() &&
		other.top() < this->top() && 
		other.bottom() > this->bottom();
}