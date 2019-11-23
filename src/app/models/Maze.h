#ifndef MAZE
#define MAZE

class Maze {
private:
    std::vector<std::vector<char>> board;
public:
    void storeBoard(std::ifstream input);
    int intToChar(int);
    void getBoard(void);
};
#endif