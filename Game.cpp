#include <iostream>
#include<cstring>
using namespace std;

const int max_X_coordinate = 100;
const int max_Y_coordinate = 100;

const int maxNumberOfHiddenMines = 30;

//Дали клетката е свободна. Тук вече допускаме, че x_coordinate и y_coordinate са валидни координати.
bool isCellFree(char playerBoard[max_X_coordinate][max_Y_coordinate], int x_coordinate, int y_coordinate)
{
    return playerBoard[x_coordinate][y_coordinate] == '*';
}

bool validateMatrixDimension(int matrix_dimension)
{
    if (matrix_dimension >= 3 && matrix_dimension <= 10)
        return true;
    else
    {
        return false;
    }
}

bool validateMineCount(int enteredMineCount, int matrix_dimension)
{
    if (enteredMineCount >= 1 && enteredMineCount <= (3 * matrix_dimension))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createPlayerBoard(int matrix_dimension, char playerBoard[max_X_coordinate][max_Y_coordinate])
{
    for (int i = 0; i < matrix_dimension; i++)
    {
        for (int j = 0; j < matrix_dimension; j++)
        {
            playerBoard[i][j] = '*';

        }
    }
}

void addMinesToBoard(char playerBoard[max_X_coordinate][max_Y_coordinate], int enteredMineCount, int matrix_dimension)
{
    for (int j = 0; j < enteredMineCount; j++)
    {

        int randomRow = (rand() % matrix_dimension) + 1;
        int randomColumn = (rand() % matrix_dimension) + 1;

        bool isCellFreeResult = isCellFree(playerBoard, randomRow, randomColumn);

        while (isCellFreeResult == false) {
            randomRow = (rand() % matrix_dimension) + 1;
            randomColumn = (rand() % matrix_dimension) + 1;

            isCellFreeResult = isCellFree(playerBoard, randomRow, randomColumn);
        }

        playerBoard[randomRow][randomColumn] = '@';
    }
}

int main()
{
    char playerBoard[max_X_coordinate][max_Y_coordinate] = {};

    char helpingBoard[max_X_coordinate][max_Y_coordinate] = {};

    int matrix_dimension;
    int enteredMineCount;
    string command;  // TODO
    int minesCount;
    bool playing = true;
    int x_coordinate, y_coordinate;

    cout << "Hey there, enter a valid dimension! ";
    cin >> matrix_dimension;
    
    bool result = validateMatrixDimension(matrix_dimension);
    while (result == false)
    {
        cout << "Enter again! ";
        cin >> matrix_dimension;
        result = validateMatrixDimension(matrix_dimension);

    }
    
    cout << "Hey there, enter a valid mine count! ";
    cin >> enteredMineCount;
    bool resultValidateMineCount = validateMineCount(enteredMineCount, matrix_dimension);
    while (resultValidateMineCount == false)
    {
        cout << "Enter again: ";
        cin >> enteredMineCount;
        resultValidateMineCount = validateMineCount(enteredMineCount, matrix_dimension);
    }
    
    createPlayerBoard(matrix_dimension, playerBoard);

    createPlayerBoard(matrix_dimension, helpingBoard);

    addMinesToBoard(helpingBoard, enteredMineCount, matrix_dimension);
}
