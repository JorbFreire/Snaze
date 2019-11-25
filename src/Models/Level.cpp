
#include "../include/Level.h"

Level::Level(int rows, int collums) {
    linhas = rows;
    colunas = collums;
}

int Level::collums() {
    return colunas;
}

int Level::rows() {
    return linhas;
}

void Level::setFood (int row, int collum) {
    f_row = row;
    f_col = collum;
    maze[row][collum] = 'F';
}

void Level::getFoodPos(int * row, int * collum) {
    *row = f_row;
    *collum = f_col;
}