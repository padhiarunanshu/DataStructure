// This program was asked in TiVo, programming round!

#include <iostream>
using namespace std;

void updateZeroMatrix(int mat[][4], int row, int col) {
    bool row_flag = false;
    bool col_flag = false;
    for (int i = 0; i < row; i++ ) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && mat[i][j] == 0)
                row_flag = true;
            if (j == 0 && mat[i][j] == 0)
                col_flag = true;
                
            if (mat[i][j] == 0) {
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < row; i ++) {
        for (int j = 1; j < col; j ++) {
            if (mat[0][j] == 0 || mat[i][0] == 0) {
                mat[i][j] = 0;
            }
        }
    }
    if (row_flag == true){
        for (int i = 0; i < col; i++) {
            mat[0][i] = 0;
        }
    }
    if (col_flag == true) {
        for (int i = 0; i < row; i ++) {
            mat[i][0] = 0;
        }
    }
}

void print(int mat[][4], int row, int col) {
    for (int i = 0; i < row; i++ ) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << "  ";    
        }
        cout << endl;
    }
}
    
int main()
{
    int arr[][4] = { {4, 1, 2, 3}, 
                    {2, 5, 0, 3},
                    {2, 3, 1, 8},
                    {0, 5, 6, 1} };

    cout << "Matrix before : \n";
    print(arr, 4, 4);
    cout << endl;
    updateZeroMatrix(arr, 4, 4);
    
    cout << "Matrix after : \n";
    print(arr, 4, 4);
    
    return 0;
}
