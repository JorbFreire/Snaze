
#include "../include/receiveInput.h"

using namespace std;

void errorMsg(string error)
{
    error = "";
    if (error != "")
        cout << "Error: " << error << "\n\n";

    cout << "Usage: <input_file>\n"
         << "The input file must contain, for each level:\n"
         << "   The number of rows and collums in that order. Both must be integers within the interval (0,100]\n"
         << "   The maze that will be used in the levels. It's dimensions must match the values given for rows and collums."
         << "In order to enter more than one level, repeat this pattern for each level to be inserted.\n";

    exit(0);
}

string strToLower(string str)
{

    for (char &c : str)
        c = tolower(c);

    return str;
}

void receiveInput (int argc, char * argv[], int * quantity, int * rows, int * collums) {
    // Apenas nome do progrma (sem argumentos)
    if (argc == 1)
        errorMsg();

    // Mais do que 2 argumentos - incluindo o nome do programa(excesso)
    if (argc > 2)
        errorMsg("Too many arguments!");

    for (auto i{1}; i < argc; i++)
    {

        auto s_arg = strToLower(argv[i]);

        if (s_arg == "-r" || s_arg == "--r" || s_arg == "--row" || s_arg == "-row")
        {
            int nrows{0};

            // Teste 1
            if ((i + 1) == argc)
                errorMsg("Missing number of rows!");

            // Teste 2
            try
            {
                nrows = std::stoi(argv[i++]);
            }
            catch (const std::invalid_argument &e)
            {
                errorMsg("Invalid value for row!");
            }

            // Teste 3
            if (nrows < MIN_ROW || nrows > MAX_ROW)
                errorMsg("Number of rows out of the acceptable range!");

            *rows = nrows;
        }
        else if (s_arg == "-c" || s_arg == "--c" || s_arg == "--col" || s_arg == "-col")
        {
            int ncols{0};

            try
            {
                ncols = std::stoi(argv[i++]);
            }
            catch (const std::invalid_argument &e)
            {
                errorMsg("Invalid value for collum!");
            }

            if (ncols < MIN_COL || ncols > MAX_COL)
                errorMsg("Number of collums out of the acceptable range!");

            *collums = ncols;
        }
        else
        {
            int npuzzles{1};

            try
            {
                npuzzles = std::stoi(argv[i]);
            }
            catch (const std::invalid_argument &e)
            {
                errorMsg("Invalid value for number of puzzles!");
            }

            if (npuzzles < MIN_NPUZ || npuzzles > MAX_NPUZ)
                errorMsg("Number of puzzles out of the acceptable range!");

            *quantity = npuzzles;
        }
    }
}