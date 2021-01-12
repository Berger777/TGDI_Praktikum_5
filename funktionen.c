#include <stdlib.h>
#include "stdio.h"


int **matrixErstellen(int zeile, int spalte){
    int** matrix = malloc((sizeof(int*))*zeile);
    for (int i = 0; i < zeile; ++i) {
        matrix[i] = malloc((sizeof(int))*spalte);
        for (int j = 0; j < spalte; ++j) {
            matrix[i][j] = (rand()%64)-32;
        }
    }
    return matrix;
}

int*** vektorenArrErstellen(int n){
    int*** array = malloc((sizeof(int**))*n);
    for (int i = 0; i < n; ++i) {
        array[i] = matrixErstellen(i,1);
    }
    return array;
}

int*** matrizenArrQuadratischErstellen(int n){
    int*** array = malloc((sizeof(int**))*n);
    for (int i = 0; i < n; ++i) {
        array[i] = matrixErstellen(i,i);
    }
    return array;
}


void freeMatrix(int** matrix,int zeilen){
    for (int i = 0; i < zeilen; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeArrQuadratischeMatrizen(int*** matrizenArr, int anz){
    for (int i = 0; i < anz; ++i) {
        freeMatrix(matrizenArr[i],i);
    }
    free(matrizenArr);
}

void freeVektorArr(int*** vektorArr, int anz){
    for (int i = 0; i < anz; ++i) {
        freeMatrix(vektorArr[i],i);
    }
    free(vektorArr);
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

