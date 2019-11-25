
#include "../include/Snake.h"

Snake::Snake(int length, int life, int direction) {
    size = length;
    hearts = life;
    facing = direction;
}

Snake::~Snake()
{
}

int Snake::length() {
    return size;
}

int Snake::direction() {
    return facing;
}

int Snake::life() {
    return hearts;
}