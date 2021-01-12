#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_ZEILEN_A 10
#define MATRIX_SPALTEN_A 4
#define MATRIX_ZEILEN_B 4
#define MATRIX_SPALTEN_B 12


int **matrixErstellen(int zeilen, int spalten);
void matrixAusgeben(int** matrix, int zeilen, int spalten);
void freeMatrix(int** matrix,int zeilen);
int** matrixMultiplikation(int** matrixA,int aZeilen, int aSpalten, int** matrixB, int bZeilen, int bSpalten);

int main() {
    srand(time(NULL));
    int** matrix_a = matrixErstellen(MATRIX_ZEILEN_A, MATRIX_SPALTEN_A);
    matrixAusgeben(matrix_a, MATRIX_ZEILEN_A, MATRIX_SPALTEN_A);
    int** matrix_b = matrixErstellen(MATRIX_ZEILEN_B, MATRIX_SPALTEN_B);
    matrixAusgeben(matrix_b, MATRIX_ZEILEN_B, MATRIX_SPALTEN_B);

    int** matrix_c = matrixMultiplikation(matrix_a,MATRIX_ZEILEN_A,MATRIX_SPALTEN_A,matrix_b,MATRIX_ZEILEN_B,MATRIX_SPALTEN_B);
    matrixAusgeben(matrix_c,MATRIX_ZEILEN_A,MATRIX_SPALTEN_B);

    freeMatrix(matrix_a, MATRIX_ZEILEN_A);
    freeMatrix(matrix_b, MATRIX_ZEILEN_B);
    freeMatrix(matrix_c, MATRIX_ZEILEN_A);
    return 0;
}

