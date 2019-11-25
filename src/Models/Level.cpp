
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