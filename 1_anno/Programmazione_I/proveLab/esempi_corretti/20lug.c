#include<stdio.h>
#include<stdlib.h>

typedef struct{
    FILE *file;
    int N,M;
}params;

params readInput(int argc,char *argv[]);
double ***allocateMatrix(params record);
void fillMatrix(double***matrix,params record);
void printMatrix(double***matrix,params record);
void normalize(double***matrix_source,double***matrix_dest,params record);
void sortMatrixCols(double***matrix,params record);

int main(int argc, char*argv[]){
    params record = readInput(argc,argv);

    double ***matrix = allocateMatrix(record);
    double ***matrix_dest = allocateMatrix(record);
}


void sortMatrixCols(double***matrix,params record){
    for (int j = 0; j < record.M; ++j) {
        for (int i = 0; i < record.N - 1; ++i) {
            for (int k = i + 1; k < record.N; ++k) {
                if (*matrix[i][j] > *matrix[k][j])
                    {
                    double temp = *matrix[i][j];
                    *matrix[i][j] = *matrix[k][j];
                    *matrix[k][j] = temp;
                }
            }
        }
    }
}


void normalize(double***matrix_source,double***matrix_dest,params record){
    double max_val;

    for (int j = 0; j < record.M; ++j)
    {
        max_val = *matrix_source[0][j];
        for (int i = 1; i < record.N; ++i)
        {
            if (*matrix_source[i][j] > max_val)
            {
                max_val = *matrix_source[i][j];
            }
        }
             for (int i = 0; i < record.N; ++i)
             {
                *matrix_dest[i][j] = (*matrix_source[i][j]) / max_val;
             }
    }
}


void printMatrix(double***matrix,params record){
    for (int i = 0; i < record.N; ++i)
    {
        for (int j = 0; j < record.M; ++j)
        {
            fprintf(stdout,"%.6lf",*matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



void fillMatrix(double***matrix,params record){
    for (int i = 0; i < record.N; ++i)
    {
        for (int j = 0; i < record.M; ++j)
        {
            if (fscanf(record.file,"%lf",matrix[i][j]) != 1)
            {
                fprintf(stderr,"error in matrix fill!");
                exit(-1);
            }
            
        }
        
    }
    fclose(record.file);
}


double ***allocateMatrix(params record){
    double ***matrix = malloc(record.N * sizeof(double**));
    for (int i = 0; i < record.N; i++)
    {
        matrix[i] = malloc(record.M * sizeof(double*));

        for (int j = 0; i < record.M; j++)
        {
            matrix[i][j] = malloc(sizeof(double));
        }
           
    }
    return matrix;
}

params readInput(int argc, char*argv[]){
if (argc != 4)
    {
        fprintf(stderr,"Usage: <file.txt> <int> <int>, integers must be in 5-10!");
        exit(-1);
    }
    
    params record = {0,0,0};

    FILE *file = fopen(argv[1],"r");
    newRecord.file = file;

    if (!file)
    {
        fprintf(stderr,"err in file!");
        exit(-1);
    }
    
    int N = atoi(argv[2]);
    record.N = N;

    int M = atoi(argv[3]);
    record.M = M;

    if (( N < 5 || N > 10) || ( M < 5 || M > 10))
    {
        fprintf(stderr,"M and N must be in 5-10 range!");
        exit(-1);
    }

    return  record;
}