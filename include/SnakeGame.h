#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Level.h"
#include "Player.h"
#include "Snake.h"

#include <vector>
#include <iostream>

class SnakeGame
{
private:
    int hearts;
    // Represents the snake's life points
    int foodEaten;
    // How many food particles the snake has eaten up to that point
    int foodTotal;
    // How much food there is to eat in that level
    int nextDirection;
    // Direction that the player is making the snake face, which will be used to move
    int nextPosRow, nextPosCol;
    /* Next position that the snake will take, defined by the process_events() function
       and used by the update() function to move the snake and change the hearts and
       Food eaten variables as well as place new food in case it is needed*/
public:
    SnakeGame(Level phase);
    // Construtor da classe
    ~SnakeGame();
    // Destrutor da classe

    /*GameLoop Methods*/

    void initialize_game(Snake cobra, Level phase);
    // Inicia o jogo, fazendo o setup de todas os elementos necessários
    void process_events(char userInput, Snake cobra, Level phase);
    // Processes player input, altering variable values but not making changes to the maze itself
    void update(Snake cobra, Level phase);
    // Cuisa em atualizar o labirinto do jogo dada a entrada (ou falta dela)
    void render(Snake cobra, Level phase);
    // Cuida de imprimir o estado atual tenha esse mudado ou não
    void game_over(bool running);
    // Encerra o jogo, dada que uma condição foi cumprida

    /*Helper Methods*/

    void defineMove(Snake snake);
    // Called by the process_events() method, it serves to define the next move the snake will make
    bool comparePos(Snake snake);
    // Compares the values of the snake's current position to those of the new positions to see if a move was made
    void updateHead(Snake snake, Level phase);
    // Updates the head of the snake inside the maze (as in, it changes the char representative of it depending on the direction)
};


#endif