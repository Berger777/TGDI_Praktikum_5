#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_ZEILEN_A 10
#define MATRIX_SPALTEN_A 4
#define MATRIX_ZEILEN_B 4
#define MATRIX_SPALTEN_B 12

#define MAX 600

int*** vektorenArrErstellen(int n);
int*** matrizenArrQuadratischErstellen(int n);
void freeArrQuadratischeMatrizen(int*** matrizenArr, int anz);
void freeVektorArr(int*** vektorArr, int anz);
int **matrixErstellen(int zeilen, int spalten);
void matrixAusgeben(int** matrix, int zeilen, int spalten);
void freeMatrix(int** matrix,int zeilen);
int** matrixMultiplikation(int** matrixA,int aZeilen, int aSpalten, int** matrixB, int bZeilen, int bSpalten);
void matrixMultiplikationTest();

void matrixKreuzVektor();

int main() {
    srand(time(NULL));
    int*** matrizen_a = matrizenArrQuadratischErstellen(MAX);
    int*** matrizen_b = matrizenArrQuadratischErstellen(MAX);
    printf("Matrizen erstellt!\n");

    FILE *datei = fopen("data2.dat","w");
    for (int i = 2; i < MAX; ++i) {
        double time = clock();
        matrixMultiplikation(matrizen_a[i],i,i,matrizen_b[i],i,i);
        double timeEnd = ((clock() - time)/(CLOCKS_PER_SEC))*1000;
        fprintf(datei,"%d\t%f\n",i,timeEnd);
        fflush(datei);
        printf("%d\t%f\n",i,timeEnd);
    }

    freeArrQuadratischeMatrizen(matrizen_a,MAX);
    freeArrQuadratischeMatrizen(matrizen_b,MAX);

    //matrixKreuzVektor();
    //matrixMultiplikationTest();
    return 0;
}

void matrixKreuzVektor() {
    int*** vektoren = vektorenArrErstellen(MAX);
    int*** matrizen = matrizenArrQuadratischErstellen(MAX);
    printf("Matrizen erstellt!\n");

    FILE *datei = fopen("data.dat","w");
    for (int i = 2; i < MAX; ++i) {
        double time = clock();
        matrixMultiplikation(matrizen[i],i,i,vektoren[i],i,1);
        double timeEnd = ((clock() - time)/(CLOCKS_PER_SEC))*1000;
        fprintf(datei,"%d\t%f\n",i,timeEnd);
        printf("%d\t%f\n",i,timeEnd);
    }

    freeArrQuadratischeMatrizen(matrizen,MAX);
    freeVektorArr(vektoren,MAX);
}

void matrixMultiplikationTest(){
    int** matrix_a = matrixErstellen(MATRIX_ZEILEN_A, MATRIX_SPALTEN_A);
    matrixAusgeben(matrix_a, MATRIX_ZEILEN_A, MATRIX_SPALTEN_A);
    int** matrix_b = matrixErstellen(MATRIX_ZEILEN_B, MATRIX_SPALTEN_B);
    matrixAusgeben(matrix_b, MATRIX_ZEILEN_B, MATRIX_SPALTEN_B);

    int** matrix_c = matrixMultiplikation(matrix_a,MATRIX_ZEILEN_A,MATRIX_SPALTEN_A,matrix_b,MATRIX_ZEILEN_B,MATRIX_SPALTEN_B);
    matrixAusgeben(matrix_c,MATRIX_ZEILEN_A,MATRIX_SPALTEN_B);

    freeMatrix(matrix_a, MATRIX_ZEILEN_A);
    freeMatrix(matrix_b, MATRIX_ZEILEN_B);
    freeMatrix(matrix_c, MATRIX_ZEILEN_A);
}

