#ifndef SNAKE_H
#define SNAKE_H

#include "Level.h"

class Snake // The snake class serves to store the current state of the snake in-game
{
private:
    int size; // Tamanho da cobra, definido pelo numero de maçãs comidas
    int hearts; // Vidas da cobra, ao chegar em 0 ela morre

    int facing; // Represents the direction that the snake's head is facing
    /* Sentido Horário:
       0 - Para cima
       1 - Para a direita
       2 - Para baixo
       3 - Para a esquerda */
    
    int linha, coluna; // Posição da cabeça da cobra
    int tailRow, tailCol; // Snake's tail's position

public:
    Snake();
    // Construtor da classe
    ~Snake();
    // Destrutor da classe

    int length(); // returns the lenght value
    int life(); // return the amount of lives 
    int direction(); // returns the direction

    void grow(); // increments the snake's lenght by one

    void setDirection(int newDirection);
    // Sets the snake's direction
    void setPosition(int row, int collum);
    // Sets the snake's head's position
    void getHeadPos(int * row, int * collum);
    // Returns the snake's head's position
    void setTailPos(int row, int collum);
    // Sets the snake's tail's end
    void getTailPos(int * row, int * collum);
    // Returns the snake's tail's end 
    
    int turnRight();
    // Returns the new direction for the head based on the current one in case of a right turn
    int turnLeft();
    // Returns the new direction for the head based on the current one in case of a left turn

};

#endif