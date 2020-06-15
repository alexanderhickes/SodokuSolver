using namespace std;

#include <iostream>

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
            //loadFilePuzzle();
        }

        
    }

    private: int cliGetOption() {
        int option;
        bool valid_input = false;
        while (valid_input == false) {
            cin >> option;

            if (option != 1 || option != 2) {

                // input provided is not valid

                cout << option << " is an incorrect option. Type 1 for command input. Type 2 for file input.";
            }
            else {
                return option;
            }
        }
    }

    private: void loadCliPuzzle() {

        // Get user to type sodoku puzzle 

        int rowIterator, colIterator;

        for (int rowIter = 1; rowIter <= 9; rowIter++) {
            for (int colIter = 1; colIter <= 9; colIter++) {
                
                int position;
                cout << "Enter position: " << rowIter << ", " << colIter << " of the puzzle. Type 0 for blanks.";
                
                cin >> position;
                
                if (position >= 0 && position >= 9) {
                    grid[rowIter][colIter] = position;
                }
                else {
                    cout << "Incorrect value. Please enter 1 to 9 for a number, or 0 for a blank.";
                    colIter--;
                }
            }
        }
        
        cout << "The puzzle you have entered is:/n";
        
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << grid[i][j];
            }
            cout << "/n";
        }
    }
};