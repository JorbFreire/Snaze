
#include "../include/Snake.h"

Snake::Snake() {
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

void Snake::setPosition(int row, int collum) {
    linha = row;
    coluna = collum;
}