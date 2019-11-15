#include<vector>
#include <fstream>

class Maze {
private:
    std::vector<std::vector<char>> board;
public:
    void storeBoard(std::ifstream input);
    void intToChar(int);
    void getBoard(void);
};