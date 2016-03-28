#include "vec2.h"

vec2::vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec2 vec2::operator*(real32 A, vector2D B)
{
    vec2 result;
    result.x = A * B.x;
    result.y = A * B.y;
    return result;
}

vec2 vec2::operator*(vector2D B, real32 A)
{
    vec2 result;
    result.x = B.x * A;
    result.y = B.y * A;
    return result;
}

vec2 &vec2::operator*=(vector2D &A, real32 B)
{
    A = B * A;
    return A;
}

vec2 vec2::operator-(vector2D A)
{
    vec2 result;
    result.x = -A.x;
    result.y = -A.y;
    return result;
}

vec2 vec2::operator+(vector2D A, vector2D B)
{
    vec2 result;
    result.x = A.x + B.x;
    result.y = A.y + B.y;
    return result;
}

vec2 &vec2::operator+=(vector2D &A, vector2D B)
{
    A = B + A;
    return A;
}

vec2 vec2::operator-(vector2D A, vector2D B)
{
    vec2 result;
    result.x = A.x - B.x;
    result.y = A.y - B.y;
    return result;
}

float vec2::Square(real32 A)
{
    float result;
    result = A * A;
    return result;
}

float vec2::Dot(vector2D A, vector2D B)
{
    float result = A.x * B.x + A.y * B.y;
    return result;
}

float vec2::MagnitudeSqr(vector2D A)
{
    real32 result = Dot(A, A);
    return result;
}
