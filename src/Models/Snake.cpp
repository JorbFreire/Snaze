
#include "../include/Snake.h"

Snake::Snake() {
}

Snake::~Snake()
{
}

int Snake::length() {
    return size;
}

void Snake::grow() {
    size++;
}

int Snake::direction() {
    return facing;
}

void Snake::setDirection(int newDirection) {
    facing = newDirection;
}

int Snake::life() {
    return hearts;
}

void Snake::setPosition(int row, int collum) {
    linha = row;
    coluna = collum;
}

void Snake::getHeadPos(int * row, int * collum) {
    *row = linha;
    *collum = coluna;
}

int Snake::turnLeft() {
   int turn = direction();
   if (turn == 0) {
       turn += 3;
       facing = turn;
   }
   else {
       turn -= 1;
   }
   return turn;
}

int Snake::turnRight() {
   int turn = direction();
   turn = (turn + 1) % 4;
   return turn;
}

void Snake::setTailPos(int row, int col) {
    tailRow = row;
    tailCol = col;
}

void Snake::getTailPos(int * row, int * col) {
    *row = tailRow;
    *col = tailCol; 
}
