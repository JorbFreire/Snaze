
#include "../include/SnakeGame.h"

using namespace std;

void SnakeGame::initialize_game (Snake cobra, Level phase) {

    hearts = 5;
    foodEaten = 0;

    phase.randomInsertFood(); // Define a fruta em uma posição aleatória

    for (int i = 0; i < phase.rows(); i++) // Encontra o spawn da cobra e a coloca nele
        for (int e = 0; e < phase.collums(); e++)
            if (phase.maze[i][e] == '*')
                cobra.setPosition(i, e);

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
        if (phase.maze[nextPosRow][nextPosCol] == '#') { // Not possible to make the move.
            int currentRow, currentCol;
            snake.getHeadPos(&currentRow, &currentCol);
            nextPosRow = currentRow;
            nextPosCol = currentCol;
            hearts--;

            updateHead(snake, phase); // Updates the direction that the snake's head is facing
        }
        else { // It is possible to make the move
            if (phase.maze[nextPosRow][nextPosCol] == 'F') { // There is food in that position.
                phase.randomInsertFood();
                if (snake.length() == 1) {
                    int headRow, headCol;
                    snake.getHeadPos(&headRow, &headCol);
                    snake.setTailPos(headRow, headCol);
                }
                int tailRow, tailCol;
                snake.getTailPos(&tailRow, &tailCol);
                if (phase.maze[tailRow + 1][tailCol] == ' ') {
                    phase.maze[tailRow + 1][tailCol] == '▅';
                    snake.setTailPos(tailRow + 1, tailCol);
                }
                else if (phase.maze[tailRow - 1][tailCol] == ' ') {
                    phase.maze[tailRow - 1][tailCol] == '▅';
                    snake.setTailPos(tailRow - 1, tailCol);
                }
                else if (phase.maze[tailRow][tailCol + 1] == ' ') {
                    phase.maze[tailRow][tailCol + 1] == '▅';
                    snake.setTailPos(tailRow, tailCol + 1);
                }
                else if (phase.maze[tailRow][tailCol - 1] == ' ') {
                    phase.maze[tailRow][tailCol - 1] == '▅';
                    snake.setTailPos(tailRow, tailCol - 1);
                }
                snake.grow();
                foodEaten++;
            }
            updateHead(snake, phase); // Updates the direction that the snake's head is facing
            snake.setDirection(nextDirection); // Sets the snake's head's new direction
            vector < int > * lastPosRowVec = new vector < int >; 
            vector < int > * lastPosColVec = new vector < int >; 
            /* Stores the last position of the snake before updating 
            to the new one. Used to update it's tail. */
            int headRow, headCol;
            snake.getHeadPos(&headRow, &headCol);
            lPosVecGenerator(headRow, headCol, phase, lastPosRowVec, lastPosColVec);
            // Fill in the vector with the positions of all the parts of the snake (head & tail)
            snake.setPosition(nextPosRow, nextPosCol);
            for (int i = snake.length(); i > 0; i--) {
                phase.maze[lastPosRowVec->at(i)][lastPosColVec->at(i)] = '▅';
            }
            phase.maze[lastPosRowVec->at(0)][lastPosColVec->at(0)] = ' ';
            /* First, the current positions of each part of the snake are stored in the two
               temporary vectors, then the head moves to the new position and the vecotrs are
               used to move it's tail forward.*/
        }    
    }
    else {
        updateHead(snake, phase); // Updates the direction that the snake's head is facing
    }
}

void SnakeGame::render (Snake cobra, Level phase) {


}

void SnakeGame::game_over(bool running) {
  if (foodEaten == foodTotal) {
        //cout << mensagem de vitoria << endl;
        running = false;
    }
    else if (hearts == 0) {
        //cout << mensagem de derrota << endl;
        running = false;
    }
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

// Doesn't need to be inside the SnakeGame class
void SnakeGame::lPosVecGenerator (int row, int col, Level phase, vector <int> * lastPosRowVec, vector <int> * lastPosColVec) {
    if (phase.maze[row + 1][col] == '▅') 
        lPosVecGenerator(row + 1, col, phase, lastPosRowVec, lastPosColVec);
    else if (phase.maze[row - 1][col] == '▅') 
        lPosVecGenerator(row - 1, col, phase, lastPosRowVec, lastPosColVec);
    else if (phase.maze[row][col + 1] == '▅') 
        lPosVecGenerator(row, col + 1, phase, lastPosRowVec, lastPosColVec);
    else if (phase.maze[row][col - 1] == '▅') 
        lPosVecGenerator(row, col - 1, phase, lastPosRowVec, lastPosColVec);
    
    lastPosRowVec->push_back(row);
    lastPosColVec->push_back(col);
}

void SnakeGame::updateHead (Snake snake, Level phase) {
    int row, collum;
    snake.getHeadPos(&row, &collum);
    switch(nextDirection) {
        case 0:
            phase.maze[row][collum] = '▲';
            break;
        case 1:
            phase.maze[row][collum] = '►';
            break;
        case 2:
            phase.maze[row][collum] = '▼';
            break;
        case 3:
            phase.maze[row][collum] = '◄';
            break;
    }
}

/* Rendering The Game */
