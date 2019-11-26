
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

void Level::randomInsertFood () {
    std::random_device r_row, r_collum;
    int row = r_row() % rows(); // Sortea uma linha
    int collum = r_collum() % collums(); // Sortea uma coluna
    if (maze[row][collum] == ' ') 
        maze[row][collum] = 'F';
    else
        randomInsertFood();
}

/*void Level::getFoodPos(int * row, int * collum) {
    *row = f_row;
    *collum = f_col;
} */