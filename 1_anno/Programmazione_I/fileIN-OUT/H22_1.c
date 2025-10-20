#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void createMatrix(double**);
void fillMatrix(double**, int, int);
void printMatrix(double**, int, int);
void writeMatrix(FILE *, double**, int, int);
double** transMatrix(double**,int,int);

int main(){
    int N, M;
    printf("Inserisci il numero di righe (N): ");
    scanf("%d", &N);
    printf("Inserisci il numero di colonne (M): ");
    scanf("%d", &M);

double** matrix = (double**)malloc(N * sizeof(double*));
    for(int i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(M * sizeof(double));
    }


    fillMatrix(matrix,N,M);
    printMatrix(matrix,N,M);

    FILE *fileOUT = fopen("fileOUT.txt","w");
    writeMatrix(fileOUT, matrix, N, M);

    double** transposedMatrix = transMatrix(matrix,N,M);
    printMatrix(transposedMatrix,N,M);
    writeMatrix(fileOUT,transposedMatrix,N,M);

}

    double ** transMatrix(double **matrix, int N, int M){
        double** transposedMatrix = (double**)malloc(M * sizeof(double*));
    for(int i = 0; i < M; i++) {
        transposedMatrix[i] = (double*)malloc(N * sizeof(double));
    }

    // Calcolo della trasposta
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
    }




    void writeMatrix(FILE *fileOUT, double**matrix, int N, int M){
    
     fprintf(fileOUT, "\nMatrice generata:\n");
    for(int i = 0; i < N; i++) {
        fprintf(fileOUT, "[ ");
        for(int j = 0; j < M; j++) {
            fprintf(fileOUT, "%.2f ", matrix[i][j]);
        }
        fprintf(fileOUT, "]\n");
    }   
    }


    void fillMatrix(double **matrix, int sizeN, int sizeM){
        srand(time(NULL));
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeM; j++) {
            matrix[i][j] = 1 + rand() % 9;
        }
    } 
}

    void printMatrix(double**matrix, int sizeN, int sizeM){
        printf("\nMatrice generata:\n");
    for(int i = 0; i < sizeN; i++) {
        printf("[ ");
        for(int j = 0; j < sizeM; j++) {
            printf("| %1.2f ", matrix[i][j]);
        }
        printf("]\n");
    }
    }