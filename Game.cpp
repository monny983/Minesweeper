#include <iostream>
#include<cstring>
using namespace std;

bool validateMatrixDimension(int matrix_dimension)
{
    if (matrix_dimension >= 3 && matrix_dimension <= 10)
        return true;
    else
    {
        return false;
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
}
