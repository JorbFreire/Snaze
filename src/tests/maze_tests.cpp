#include "../app/functions/Maze.cpp"
#include <gtest/gtest.h>

TEST(MazeTests, toCharTest) {
    ASSERT_EQ('#', toChar('#'));
    ASSERT_EQ('.', toChar('.'));
    ASSERT_EQ('.', toChar('*'));
}
TEST(mazeGenTest, maze) {
    std::vector<std::vector<char>> ExpectedStr{{'#','*','.'},
                                               {'#','*','.'},
                                               {'#','*','.'},
                                               {'#','*','.'},
                                               {'#','*','.'}};
    std::string inputStr = {"#*.#*.\n"};
    bool condition = ExpectedStr == mazeGen(inputStr, 5, 3);
    EXPECT_TRUE(condition);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}