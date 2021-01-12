#include <stdlib.h>
#include "stdio.h"

int **matrixErstellen(int zeile, int spalte){
    int** matrix = malloc((sizeof(int*))*zeile);
    for (int i = 0; i < zeile; ++i) {
        matrix[i] = malloc((sizeof(int))*spalte);
        for (int j = 0; j < spalte; ++j) {
            matrix[i][j] = rand()%10;
        }
    }
    return matrix;
}

void freeMatrix(int** matrix,int zeilen){
    for (int i = 0; i < zeilen; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int** matrixMultiplikation(int** matrixA,int aZeilen, int aSpalten, int** matrixB, int bZeilen, int bSpalten){
    if(aSpalten != bZeilen){
        return NULL;
    }

    int** matrixC = matrixErstellen(aZeilen,bSpalten);

    int sum = 0;
    for (int i = 0; i < aZeilen; ++i) {
        for (int p = 0; p < bSpalten; ++p) {
            sum = 0;
            for (int j = 0; j < aSpalten; ++j) {
                sum += matrixA[i][j] * matrixB[j][p];
            }
            matrixC[i][p] = sum;
            sum=0;
        }
    }

    return matrixC;
}

void matrixAusgeben(int** matrix, int zeilen, int spalten){
    printf("\n");
    for (int i = 0; i < zeilen; ++i) {
        for (int j = 0; j < spalten; ++j) {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

