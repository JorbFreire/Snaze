
#include "../include/SnakeGame.h"

using namespace std;

void initialize_game (Snake cobra, Level phase) {

    random_device r_row, r_collum;
    int row = r_row() % phase.rows(); // Sortea uma linha
    int collum = r_collum() % phase.rows(); // Sortea uma coluna
    if (phase.maze[row][collum] == ' ') {

        phase.maze[row][collum] = 'F'; // Define a fruta em uma posição aleatória

        for (int i = 0; i < phase.rows(); i++) // Encontra o spawn da cobra e a coloca nele
            for (int e = 0; e < phase.collums(); e++)
                if (phase.maze[i][e] == '*')
                    cobra.setPosition(i, e);
    }
    else {
        initialize_game(cobra, phase);
    }
}