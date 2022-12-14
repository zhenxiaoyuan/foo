#include "vector2d.hpp"
#include <math.h>

Vector2D::Vector2D() : x{0}, y{0}
{
}

Vector2D::Vector2D(float x, float y) : x{x}, y{y}
{
}

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator+(const Vector2D& vec) const
{
    return Vector2D(this->x + vec.x, this->y + vec.y);
}

Vector2D Vector2D::operator*(float scalar)
{
    return Vector2D(this->x * scalar, this->y * scalar);
}

Vector2D &Vector2D::operator*=(float scalar)
{
    this->x *= scalar;
    this->y *= scalar;

    return *this;
}

Vector2D Vector2D::operator-(const Vector2D &vec) const
{
    return Vector2D(this->x - vec.x, this->y - vec.y);
}

Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(this->x / scalar, this->y /scalar);
}

Vector2D &Vector2D::operator/=(float scalar)
{
    this->x /= scalar;
    this->y /= scalar;

    return *this;
}

Vector2D& operator+=(Vector2D& vec_l, const Vector2D& vec_r)
{
    vec_l.x += vec_r.x;
    vec_l.y += vec_r.y;

    return vec_l;
}

Vector2D &operator-=(Vector2D &vec_l, const Vector2D &vec_r)
{
    vec_l.x -= vec_r.x;
    vec_l.y -= vec_r.y;

    return vec_l;
}

float Vector2D::length()
{
    return sqrt(this->x * this->x + this->y * this->y);
}

void Vector2D::normalize()
{
    float l = this->length();
    if (l > 0) {
        (*this) *= (1 / l);
    }
}

void Vector2D::zero()
{
    this->set_x(0);
    this->set_y(0);
}

const float Vector2D::get_x() const
{
    return this->x;
}

const float Vector2D::get_y() const
{
    return this->y;
}

void Vector2D::set_x(float x)
{
    this->x = x;
}

void Vector2D::set_y(float y)
{
    this->y = y;
}
