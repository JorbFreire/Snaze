#include "../../include/inputHandle.h"

using namespace std;
//vector < vector <string> > inputHandle

int main() { //this shall be a class method?
    string directory = "../../data/input/sample.txt"; // deve ser um parametro

    vector < vector <string> > maze;
    ifstream mazeInput;
    fstream mazeOut;

    mazeOut.open("../../data/out/maze.txt");
    mazeInput.open(directory);

    if(mazeInput.is_open()){
        string input;
        //colocar uma linha em "input" e quando acabar a linha, 
            //  salvar de fato, apagar input e seguir em frente
        while( ! mazeInput.eof()){
            input.push_back(mazeInput.get());
        }
        for(int i = 0; i <= input.size(); i++){
            string inp = &input[i];
            filter(&maze, inp);
        }
    }
    else{
        //caso diretorio seja invalido
        vector <string> error { "error: ", "file not found"};
        maze.push_back( error );
    }

    //salvando maze
    for (int i = 0; i <= maze.size(); i++ )
        for (int j = 0; j <= maze.size(); j++ )
            mazeOut << maze[i][j];
    

    mazeOut.close();
    mazeInput.close();
    //return maze;
}
void filter(vector < vector <string> > * maze, string &input){
    cout << input << endl;
    /*switch (input){
    case '1':{
        cout << " case 1 " << endl;
        maze.push_back("◼︎");
        break;
    }
    case ' ':{
        cout << " case 0 " << endl;
        maze.push_back(" ");
        break;
    }
    case '.':{
        cout << " case . " << endl;
        // parede invisivel ?
        break;
    case '\n': {
        //fim da linha
        break;
    }
    }
    default:
        break;
    }*/
}