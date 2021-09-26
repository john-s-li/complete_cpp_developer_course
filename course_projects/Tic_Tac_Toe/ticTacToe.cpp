#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Declare all functions so program knows them
void initializeGame(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(string gameBoard[ROWS][COLS], string whichPlayer);
bool isInputValid(string gameBoard[ROWS][COLS], int r, int c);
void editBoardCell(string gameBoard[ROWS][COLS], int r, int c, string input);
bool cellAlreadyOccupied(string gameBoard[ROWS][COLS], int r, int c);
bool isBoardFull(string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
void runGame();


void initializeGame(string gameBoard[ROWS][COLS])
{
    /*
    Fills in the board game array with empty space
    NOTE: when a built-in array is passed as a param, it is automatically passed by reference
    */

    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            gameBoard[r][c] = " ";
        }
    }
}

void printCurrentBoard(string gameBoard[ROWS][COLS])
{
    /*
    Pretty prints the current configuration of the game board
    */
   cout << "\nHere is the current game board." << endl;
   for (int r = 0; r < ROWS; r++)
   {
       cout << "\n_______" << endl;
       for (int c = 0; c < COLS; c++)
       {
           if (c == 0)
           {
               cout <<  "|";
           }
           cout << gameBoard[r][c] << "|";
       }
   }
   cout << "\n_______\n" << endl;
}

void getUserInput(string gameBoard[ROWS][COLS], string whichPlayer)
{
    /*
    1. Takes in a a row and column input from the user
    2. Determine if the user input is valid or not
    3. Prompt user to input another row and column indices if input not valid OR call occupied
    4. Update the game board
    */
    bool validInput = false;
    int r; int c;
    cout << "Player " << whichPlayer << ", please enter a rox index and a col index. i.e. 1 2 _____________" << endl;

    while(!validInput)
    {   
        cin >> r;
        cin >> c;

        validInput = isInputValid(gameBoard, r, c);
        if (validInput)
        {
            editBoardCell(gameBoard, r, c, whichPlayer);
        }
        else
        {
            cout << "Please enter your input again..." << endl;
        }
    }

}

bool isInputValid(string gameBoard[ROWS][COLS], int r, int c)
{
    /*
    Returns whether or not the user input is valid
    */
   if (!(r >= 0 && r <= 2)) {return false;}
   if (!(c >= 0 && c <= 2)) {return false;}
   if (cellAlreadyOccupied(gameBoard, r, c)) {return false;}

   return true;
}

void editBoardCell(string gameBoard[ROWS][COLS], int r, int c, string input)
{
    /*
    Edits the cell at row r and col c with the either an 'X' or 'O' based on
    whose turn it is
    */
   gameBoard[r][c] = input;
}

bool cellAlreadyOccupied(string gameBoard[ROWS][COLS], int r, int c)
{
    /*
    Returns whether or not a cell in the game board is already occupied
    */
    return !(gameBoard[r][c] == " ");
}

bool isBoardFull(string gameBoard[ROWS][COLS])
{
    /*
    Checks if there are any empty spaces left in the game board
    */
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (gameBoard[r][c] == " ")
            {
                return false;
            }
        }
    }
    return true;
}

string getWinner(string gameBoard[ROWS][COLS])
{
    /*
    Returns either an "X" or "O" if there is a winner found
    Else, return "" for no current winner or no winner
    */
    // 1. Check rows
    for (int r = 0; r < ROWS; r++)
    {
        if (gameBoard[r][0] != " " && gameBoard[r][1] != " " && gameBoard[r][2] != " " &&
            gameBoard[r][0] == gameBoard[r][1] && gameBoard[r][1] == gameBoard[r][2])
        {
            return gameBoard[r][0];
        }
    }

    // 2. Check columns
    for (int c = 0; c < COLS; c++)
    {
        if (gameBoard[0][c] != " " && gameBoard[1][c] != " " && gameBoard[2][c] != " " &&
            gameBoard[0][c] == gameBoard[1][c] && gameBoard[1][c] == gameBoard[2][c])
        {
            return gameBoard[0][c];
        }
    }

    // 3. Check top left to bottom right diagonal
    if (gameBoard[0][0] != " " && gameBoard[1][1] != " " && gameBoard[2][2] != " " &&
        gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
    {
        return gameBoard[0][0];
    }

    // 4. Check bottom left to top right diagonal
    if (gameBoard[2][0] != " " && gameBoard[1][1] != " " && gameBoard[0][2] != " " &&
        gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
    {
        return gameBoard[0][0];
    }

    return "";

}

void runGame()
{
    bool boardFull = false;
    string startingPlayer = "";
    string checkWinner = "";

    string gameBoard[3][3]; // no element values filled in
    initializeGame(gameBoard);
    
    cout << "Welcome to Tic Tac Toe!" << endl;

    // Figure out if X or O starts first
    // if 1, then X else if 2 then O
    int beginInt = (rand()%2) + 1;
    if (beginInt == 1) { startingPlayer = "X"; }
    else { startingPlayer = "O"; }

    cout << "For this game, " << startingPlayer << " will start." << endl;
    while(checkWinner != "" || !boardFull)
    {
        printCurrentBoard(gameBoard);
        getUserInput(gameBoard, startingPlayer);
        checkWinner = getWinner(gameBoard);

        if (checkWinner != "")
        {
            cout << "Congratulations! The winner is Player " << checkWinner << endl;
            printCurrentBoard(gameBoard);
            break;
        }

        if (startingPlayer == "X")
        {
            startingPlayer = "O";
        }
        else
        {
            startingPlayer = "X";
        }
        boardFull = isBoardFull(gameBoard);
    }

    if (checkWinner == "")
    {
        cout << "Unfortunately, nobody won. . ." << endl;
    }
}

int main()
{
    srand(time(nullptr));
    cout << boolalpha;
    runGame();

    return 0;
}