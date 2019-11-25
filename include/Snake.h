#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
private:
    int size; // Tamanho da cobra, definido pelo numero de maçãs comidas
    int hearts; // Vidas da cobra, ao chegar em 0 ela morre
    int facing; // Which direction the snake is facing, represented by a integer
    int linha, coluna; // Posição da cobra
public:
    Snake();
    // Construtor da classe
    ~Snake();
    // Destrutor da classe

    int length(); // returns the lenght value
    int life(); // return the amount of lives 
    int direction(); // returns the direction

    void setPosition(int row, int collum); // sets the snake's position

    // Talvez as funções abaixo não sejam implementadas (só estão aqui para caso seja necesario)
    void turnRight();
    void turnLeft();

};

#endif