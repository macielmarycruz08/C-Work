#include <iostream>
#include <fstream>
#include "MatrixType.h"

using namespace std;

MatrixType :: MatrixType() 
{
    MakeEmpty();
}
void MatrixType::MakeEmpty() 
{
    numRows = numCols = 0;

    for( int r = 0; r < numRows; r++)
    for( int c = 0; c < numCols; c++)
        values[r][c] = 0;
}

void MatrixType::SetSize(int rowsSize, int colSize) 
{
    if ( rowsSize <= MAX_ROWS && colSize <= MAX_COLS)
    {
        if(rowsSize >= 1 && colSize >= 1)
        {
            numRows = rowsSize;
            numCols = colSize;
        }
        else
        cout << "The Min Matrix dimesion is 1 x 1" << endl;
    }
    else
    cout << "The Maximum Matrix dimension is 10 x 10"<< endl;
}

void MatrixType::StoreItem(int item, int row, int col) 
{
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) 
    {
        values[row][col] = item;
    }
}
 void MatrixType::Add(MatrixType otherOperand, MatrixType& result) 
 {
    if (AddSubCompatible(otherOperand)) 
    {
        for (int i = 0; i < numRows; ++i) 
        {
            for (int j = 0; j < numCols; ++j) 
            {
                result.values[i][j] = values[i][j] + otherOperand.values[i][j];
            }
        }
    }
}

void MatrixType::Sub(MatrixType otherOperand, MatrixType& result) 
{
    if (AddSubCompatible(otherOperand)) 
    {
        for (int i = 0; i < numRows; ++i) 
        {
            for (int j = 0; j < numCols; ++j) 
            {
                result.values[i][j] = values[i][j] - otherOperand.values[i][j];
            }
        }
    }
}

void MatrixType::Mult(MatrixType otherOperand, MatrixType& result) 
{
    if (MultCompatible(otherOperand)) 
    {
        for (int i = 0; i < numRows; ++i) 
        {
            for (int j = 0; j < otherOperand.numCols; ++j) 
            {
                result.values[i][j] = 0;
                for (int k = 0; k < numCols; ++k) 
                {
                    result.values[i][j] += values[i][k] * otherOperand.values[k][j];
                }
            }
        }
    }
}

void MatrixType::Print(ofstream& outfile) {
    for (int i = 0; i < numRows; ++i) 
    {
        for (int j = 0; j < numCols; ++j) 
        {
            outfile << values[i][j] << " ";
        }
        outfile << endl;
    }
}

bool MatrixType::AddSubCompatible(MatrixType otherOperand) 
{
    return numRows == otherOperand.numRows && numCols == otherOperand.numCols;
}

bool MatrixType::MultCompatible(MatrixType otherOperand) 
{
    return numCols == otherOperand.numRows;
}

