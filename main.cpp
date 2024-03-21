#include <iostream>
#include <fstream>
#include "MatrixType.h"
#include "MatrixType.cpp"
using namespace std;

void createNewMatrix(int i, MatrixType *matrices, bool *add);
void printMatrix(int i, MatrixType *matrices, bool *add);
void addMatrices(int i, int j, int k, MatrixType *matrices, bool *add);
void subtractMatrices(int i, int j, int k, MatrixType *matrices, bool *add);
void multiplyMatrices(int i, int j, int k, MatrixType *matrices, bool *add);
    
void createNewMatrix(int i, MatrixType *matrices, bool *add) {
    int rows, cols, value;
    cout << "Creating new matrix in slot " << i << "\n";
    cout << "Enter row size: ";
    cin >> rows;
    cout << "Enter colum size:";
    cin >> cols;

    if (rows > 0 && rows <= MAX_ROWS && cols > 0 && cols <= MAX_COLS) {
        add[i] = true;
        matrices[i].SetSize(rows, cols);

        int j = 0;
        while (j < rows) 
        {
            cout << "Row " << j << ": ";
            int k = 0;
            while (k < cols) 
            {
                cin >> value;
                matrices[i].StoreItem(value, j, k);
                k++;
            }
            j++;
        }
        ofstream outFile("output.txt");
        matrices[i].Print(outFile);
        outFile.close();
    } else {
        cout << "Invalid dimensions\n";
    }
}

void printMatrix(int i, MatrixType *matrices, bool *add) {
    if (i >= 0 && i < 10) {
        if (add[i]) {
            ofstream outFile("output.txt");
            matrices[i].Print(outFile);
            outFile.close();
        } else {
            cout << "No matrix at slot " << i << "\n";
        }
    } else {
        cout << "Please select a value from 0 - 9.\n";
    }
}

void addMatrices(int i, int j, int k, MatrixType *matrices, bool *add) {
    if (add[i]) 
    {
        if (add[j]) 
        {
            add[k] = true;
        matrices[i].Add(matrices[j], matrices[k]);
        } else 
        cout << "No matrix at slot " << j << "\n";
    } else 
    cout << "No matrix at slot " << i << "\n";
}

void subtractMatrices(int i, int j, int k, MatrixType *matrices, bool *add) {
    if (add[i]) 
    {
        if (add[j]) 
        {
            add[k] = true;
            matrices[i].Sub(matrices[j], matrices[k]);
        } else
            cout << "No matrix at slot " << j << "\n";
    } else
        cout << "No matrix at slot " << i << "\n";

}

void multiplyMatrices(int i, int j, int k, MatrixType *matrices, bool *add) {
    if (add[i]) 
    {
        if (add[j]) 
        {
            add[k] = true;
            matrices[i].Mult(matrices[j], matrices[k]);
        } else
            cout << "No matrix at slot " << j << "\n";
    } else
        cout << "No matrix at slot " << i << "\n";
}

int main() {
    int v, i, j, k;
    MatrixType *matrices = new MatrixType[10];
    bool add[10] = {false};
    while (true) {
        cout << "\n Menu\n";
        cout << "0 - New Matrix         Usage: 0 <matrix>\n";
        cout << "1 - Add Matrices       Usage: 1 <matrix> <matrix> <matrix>\n";
        cout << "2 - Subtract Matrices  Usage: 2 <matrix> <matrix> <matrix>\n";
        cout << "3 - Multiply Matrices  Usage: 3 <matrix> <matrix> <matrix>\n";
        cout << "4 - Print Matrix       Usage: 4 <matrix>\n";
        cout << "5 - Quit               Usage: 5\n";
        cout << "Enter option 1-5: ";
        cin >> v;
        if (v < 5) {
            cin >> i;
            if (v > 0 && v < 4) {
                cin >> j >> k;
                if (i == j || j == k || i == k) { 
                    cout << "Matrices should be different\n";
                    return 0;
                }
            }
        }
        switch (v) {
            case 0: createNewMatrix(i, matrices, add); break;
            case 1: addMatrices(i, j, k, matrices, add); break;
            case 2: subtractMatrices(i, j, k, matrices, add); break;
            case 3: multiplyMatrices(i, j, k, matrices, add); break;
            case 4: printMatrix(i, matrices, add); break;
            case 5: return 0;
            default: cout << "Invalid choice\n";
        }
    }
    return 0;
}