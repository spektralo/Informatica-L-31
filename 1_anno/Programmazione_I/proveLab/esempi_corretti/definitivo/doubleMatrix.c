#include<stdio.h>
#include<stdlib.h>

typedef struct{
    FILE* file;
    int N;
    int M;
}input;

input readInput(int argc, char *argv[]);
double*** allocateMatrix(input record);
void fillMatrix(double***matrix,input record);
void printMatrix(double ***matrix, input record);
void normalize(double***matrix_source,double***matrix_dest,input record);
void sortMatrixCols(double***matrix,input record);


int main(int argc, char *argv[]){

    input record = readInput(argc,argv);

    double ***matrix_A = allocateMatrix(record);
    double ***matrix_B = allocateMatrix(record);

    fillMatrix(matrix_A,record);
    normalize(matrix_A,matrix_B,record);

    printf("** A **\n");
    printMatrix(matrix_A,record);

    printf("** B **\n");
    printMatrix(matrix_B,record);

    sortMatrixCols(matrix_B,record);
    printf("** B (sorted columns) **\n");
    printMatrix(matrix_B,record);
    
}


void sortMatrixCols(double***matrix,input record){
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

void normalize(double***matrix_source,double***matrix_dest,input record){
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

void fillMatrix(double***matrix,input record){
    for (int i = 0; i < record.N; ++i)
         {

        for (int j = 0; j < record.M; ++j)
             {

            if (fscanf(record.file,"%lf",matrix[i][j]) != 1)
                {
                fprintf(stderr,"err in matrix fill!");
                fclose(record.file);
                exit(-1);
                }
            }
        }
    fclose(record.file);
}


void printMatrix(double ***matrix, input record) {
    for (int i = 0; i < record.N; ++i) {
        for (int j = 0; j < record.M; ++j) {
            printf("[%.6lf] ", *matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double*** allocateMatrix(input record){

    double ***matrix = malloc(record.N * sizeof(double**));
        for (int i = 0; i < record.N; i++)
        {
            matrix[i] = malloc(record.M * sizeof(double*));
                
                for (int j = 0; j < record.M ;j++)
                {
                    matrix[i][j] = malloc(sizeof(double));
                }       
        }
    return matrix;
}

input readInput(int argc, char *argv[]){
    if (argc != 4)
    {
        fprintf(stderr,"Usage: <file.txt> <int> <int>, integers must be in 5-10!");
        exit(-1);
    }
    
    input newRecord = {0,0,0};

    FILE *file = fopen(argv[1],"r");
    newRecord.file = file;

    if (!file)
    {
        fprintf(stderr,"err in file!");
        exit(-1);
    }
    
    int N = atoi(argv[2]);
    newRecord.N = N;

    int M = atoi(argv[3]);
    newRecord.M = M;

    if (( N < 5 || N > 10) || ( M < 5 || M > 10))
    {
        fprintf(stderr,"M and N must be in 5-10 range!");
        exit(-1);
    }

    return  newRecord;
}