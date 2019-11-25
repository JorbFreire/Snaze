#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

class Level
{
private:
    int linhas;
    // Quantia de linhas do labirinto fornecidas no arquivo
    int colunas;
    // Quantia de colunas do labirinto fornecidas no arquivo
public:
    Level(int rows, int collums);
    // Construtor da classe
    ~Level();
    // Destrutor da classe (que não vou definir)
    int rows();
    // Retorna rows
    int collums();
    // Retorna collums
    std::vector < std::vector <char> > maze;
    // Matriz que guarda o labirinto
};

#endif