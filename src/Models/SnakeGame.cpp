
#include "../include/SnakeGame.h"

using namespace std;

void SnakeGame::initialize_game (Snake cobra, Level phase) {

    random_device r_row, r_collum;
    int row = r_row() % phase.rows(); // Sortea uma linha
    int collum = r_collum() % phase.rows(); // Sortea uma coluna
    if (phase.maze[row][collum] == ' ') {

        phase.setFood(row, collum); // Define a fruta em uma posição aleatória


        for (int i = 0; i < phase.rows(); i++) // Encontra o spawn da cobra e a coloca nele
            for (int e = 0; e < phase.collums(); e++)
                if (phase.maze[i][e] == '*')
                    cobra.setPosition(i, e);
    }
    else {
        initialize_game(cobra, phase);
    }
}

void SnakeGame::process_events (char userInput, Snake snake, Level phase) {
    /* Treats the input as if it was keyboard input, abiding by the conventional game movement
       logic (W turning forward, A turning left, D turning right) and the E represents the Enter
       key, which would be used to confirm that the user  wants to move in the specified direction */
    switch(userInput) {
        case 'W':
            nextDirection = snake.direction();
            break;
        case 'A':
            nextDirection = snake.turnLeft();
            break;
        case 'D':
            nextDirection = snake.turnRight();
            break;
        case 'E':
            defineMove(snake);
            break;
    }
}

void SnakeGame::update (Snake snake, Level phase) {
    /* Possible outcomes that have to be dealt with:
       - the player enters no input
       - the player changes the head's direction
       - the player makes a move
        - it is possible to make that move, but there isn't food in the new position
        - it is possible to make that move and there is food in that position
        - it is not possible to make that move, the player remains in place and loses a heart */
    if (comparePos(snake)) {
        if (phase.maze[nextPosRow][nextPosCol] == '#') { // Not possible to make the move
            int currentRow, currentCol;
            snake.getHeadPos(&currentRow, &currentCol);
            nextPosRow = currentRow;
            nextPosCol = currentCol;
            hearts--;
        }
        else {
            
        }
        
        
    }
}

void render (Snake cobra, Level phase) {


}

void game_over() {
 /* if (codição de vitoria) {
        cout << mensagem de vitoria << endl;
    }
    else {
        cout << mensagem de derrota << endl;
    }*/
    exit(0);
}


/* Useful functions */

/* Processing Events */

void SnakeGame::defineMove (Snake snake) {
    int currentRow, currentCol;
    snake.getHeadPos(&currentRow, &currentCol);
    switch(nextDirection) {
        // Tratamento de segfault a primeira vista é desnecessário, voltar para cá caso de erro
        case 0: // Up
            nextPosRow = currentRow + 1;
            nextPosCol = currentCol;
            break;
        case 1: // Right
            nextPosRow = currentRow;
            nextPosCol = currentCol + 1;
            break;
        case 2: // Down
            nextPosRow = currentRow - 1;
            nextPosCol = currentCol;
            break;
        case 3: // Left
            nextPosRow = currentRow;
            nextPosCol = currentCol - 1;
            break;  
    }
}

/* Updating The Game */

bool SnakeGame::comparePos (Snake snake) {
    int currentRow, currentCol;
    snake.getHeadPos(&currentRow, &currentCol);
    if (currentRow == nextPosRow && currentCol == nextPosCol)
        return false;
    else
        return true;
}

void headUpdate (int facing, Level phase, Snake snake) {
    int row, collum;
    snake.getHeadPos(&row, &collum);
    switch(facing) {
        case 0:
            phase.maze[row][collum] = '△';
            break;
        case 1:
            phase.maze[row][collum] = '▷';
            break;
        case 2:
            phase.maze[row][collum] = '▽';
            break;
        case 3:
            phase.maze[row][collum] = '◁';
            break;
    }
}
