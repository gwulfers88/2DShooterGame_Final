#ifndef VEC2_H
#define VEC2_H


class vec2
{
public:
    vec2(float x, float y);

    vec2 operator*(float A, vec2 B);
    vec2 operator*(vec2 B, float A);
    vec2 &operator*=(vec2 &A, float B);
    vec2 operator-(vec2 A);
    vec2 operator+(vec2 A, vec2 B);
    vec2 &operator+=(vec2 &A, vec2 B);
    vec2 operator-(vec2 A, vec2 B);

    float Square(float A);
    float Dot(vec2 A, vec2 B);
    float MagnitudeSqr(vec2 A);

    float x;
    float y;
};

#endif // VEC2_H
