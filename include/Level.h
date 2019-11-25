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
     int f_col, f_row;
    // Posição da atual fruta do mapa
public:
    Level(int rows, int collums);
    // Construtor da classe
    ~Level();
    // Destrutor da classe (que não vou definir)
    int rows();
    // Retorna rows
    int collums();
    // Retorna collums
    void setFood(int row, int collum);
    // Posicionar a particula de comida no labirinto
    void getFoodPos(int * row, int * collum);
    // Retorna a posição da coluna, atribuindo sua coords às duas variaveis fornecidas
    std::vector < std::vector <char> > maze;
    // Matriz que guarda o labirinto
};

#endif