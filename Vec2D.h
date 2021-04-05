#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
    Vec2D(int x, int y) :
        x(x), y(y) {}

    int x;
    int y;

    //friend Vec2D operator-(const Vec2D& lhs, const Vec2D& rhs);
    Vec2D& operator-=(const Vec2D& other) 
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    //friend Vec2D operator+(const Vec2D& lhs, const Vec2D& rhs);
    Vec2D& operator+=(const Vec2D& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
};

inline Vec2D operator-(Vec2D lhs, const Vec2D& rhs) // Vec2D lhs da es kein const ist, kamm man ihm mit call by value aufrufen
{
    lhs -= rhs;
    return lhs;
}

inline Vec2D operator+(Vec2D lhs, const Vec2D& rhs)
{
    lhs += rhs;
    return rhs;
}



#endif // !VEC2D_H
