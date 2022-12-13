#pragma once

class Vector2D
{
public:
    Vector2D();
    Vector2D(float x, float y);
    ~Vector2D();

    float length();

    Vector2D operator+(const Vector2D& vec) const;
    friend Vector2D& operator+=(Vector2D& vec_l, const Vector2D& vec_r);

    Vector2D operator*(float scalar);
    Vector2D& operator*=(float scalar);

    Vector2D operator-(const Vector2D& vec) const;
    friend Vector2D& operator-=(Vector2D& vec_l, const Vector2D& vec_r);

    Vector2D operator/(float scalar);
    Vector2D& operator/=(float scalar);

    void normalize();

    float get_x();
    float get_y();

    void set_x(float x);
    void set_y(float y);

private:
    float x, y;
};


