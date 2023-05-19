#ifndef NEWLAB_PROCEDURE3_H
#define NEWLAB_PROCEDURE3_H
#pragma once

struct Vector2D
{
    float x;
    float y;
};

void moveSquare(Vector2D* square, const Vector2D* vector)
{
    square->x += vector->x;
    square->y += vector->y;
}

#endif
//NEWLAB_PROCEDURE3_H
