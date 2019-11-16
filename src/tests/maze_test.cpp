#include "../models/Maze.cpp"
#include <gtest/gtest.h>

TEST(intToChar, OnlyOne){
    ASSERT_EQ('A', maze.intToChar(1));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}