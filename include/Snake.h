#ifndef SNAKE_H
#define SNAKE_H

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

public:
    Snake();
    // Construtor da classe
    ~Snake();
    // Destrutor da classe

    int length(); // returns the lenght value
    int life(); // return the amount of lives 
    int direction(); // returns the direction

    void setPosition(int row, int collum); // sets the snake's position
    void getHeadPos(int * row, int * collum); // returns the snake's head's position
    
    int turnRight();
    // Returns the new direction for the head based on the current one in case of a right turn
    int turnLeft();
    // Returns the new direction for the head based on the current one in case of a left turn

};

#endif