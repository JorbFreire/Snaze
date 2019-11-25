#include "../../include/Snake.h"
#include "../../include/Level.h"
#include "../../include/SnakeGame.h"

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