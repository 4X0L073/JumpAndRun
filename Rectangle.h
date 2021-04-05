#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vec2D.h"

struct Rectangle
{
public:
	Rectangle(int x, int y, int width, int height);
	Rectangle();

	int x;
	int y;
	int width;
	int height;

	/// The coordinates of the upper right corner of the rectangle.
	Vec2D upperLeft() const;

	/// The coordinates of the upper right corner of the rectangle.
	Vec2D upperRight() const;

	/// The coordinates of the lower left corner of the rectangle.
	Vec2D lowerLeft() const;

	/// The coordinates of the lower right corner of the rectangle.
	Vec2D lowerRight() const;

	/// The x coordinate of the left border.
	int left() const;
	/// The x coordinate of the right border.
	int right() const;
	/// The x coordinate of the top border.
	int top() const;
	/// The x coordinate of the bottom border.
	int bottom() const;

	/// Checks whether the rectangle intersects with the given rectangle other.
	/// Returns true, if they intersect, otherwise false.
	bool intersects(const Rectangle& other) const;

	/// Checks whether this rectangle contains the given rectangle.
	/// Returns true, if it contains the given rectangle, otherwise false.
	bool contains(const Rectangle& other) const;
};

#endif // !RECTANGLE_H