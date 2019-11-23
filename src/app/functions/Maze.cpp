#include <math.h>
#include "../libs.h"
 
using namespace std;
vector <vector<char>> mazeGen(string input, unsigned short int rows, unsigned short int collums ){

    vector <vector<char>> vec;
    
    recursion(&vec);

    return vec;
}
void recursion(vector <vector<char>> * vec){
    for(int i = 0; i <= input->size(); i++)
        *vec[1]->push_back(toChar(input[i]));

}
char toChar(char input){
    char thisChar;
    switch (input){
        case '#':{
            /* code */
            break;
        }
        case '.':{
            break;
        }
        case '*':{
            break;
        }
        case '\n':{
            break;
        }    
        default:
            break;
    }
    return 'A';
}