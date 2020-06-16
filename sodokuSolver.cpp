using namespace std;

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>

class SodokuGame {

    int grid[9][9];

    public: SodokuGame() {

        cliMenu();

    }

    private: void cliMenu() {

        // Inital text display when program starts.

        cout << "Type 1 for command input. Type 2 for file input.";

        int option = cliGetOption();

        if (option == 1) {
            loadCliPuzzle();
        }
        if (option == 2) {
            loadFilePuzzle();
        }
    }

    private: int cliGetOption() {

        int option;
        bool valid_input = false;
        while (valid_input == false) {
            
            if (cin.fail()) {
                valid_input = false;
                cin.clear();
                cin.ignore(100, '\n');
            }

            cin >> option;

            if (option >= 1 && option <= 2) {

                return option;

            }
            else {
                // input provided is not valid
                cout << option << " is an incorrect option. Type 1 for command input. Type 2 for file input.";
            }
        }
        return 0;
    }

    private: void loadCliPuzzle() {

        // Get user to type sodoku puzzle 

        int rowIterator, colIterator;

        for (int rowIter = 1; rowIter <= 9; rowIter++) {
            for (int colIter = 1; colIter <= 9; colIter++) {
                
                int position;
                cout << "Enter position: [" << rowIter << "][" << colIter << "] of the puzzle. Type 0 for blanks.";
                
                cin >> position;
                
                if (position >= 0 && position < 9) {
                    grid[rowIter][colIter] = position;
                }
                else {
                    cout << "Incorrect value. Please enter 1 to 9 for a number, or 0 for a blank.";
                    colIter--;
                }
            }
        }
        
        showGrid();
    }

    private: void loadFilePuzzle() {

        cout << "The file which will be read will be called: InputPuzzle.txt\n";
        ifstream input_file;
        input_file.open("InputPuzzle.txt", ios::in);

        for (int rowIter = 0; rowIter < 9; rowIter++) {

            string readLine;
            input_file >> readLine;

            for (int colIter = 0; colIter < 9; colIter++) {
                
                int readValue = std::stoi(readLine.substr(colIter, 1));
                

                if (!(readValue >= 0 || readValue <= 9)) {
                    cout << "Value for cell [" << (rowIter * 9) + colIter + 1 << "] is incorrect. Please fix.";
                    exit(EXIT_FAILURE);
                }

                grid[rowIter][colIter] = readValue;

                
            }
            
            if (input_file.eof()) {
                    break;

            }
        }

        input_file.close();
        cout << endl;

        showGrid();

    }

    private: void showGrid() {

        cout << "The puzzle you have entered is:\n";
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }

    }
};

int main() {

    SodokuGame sg;
    return 0;

}