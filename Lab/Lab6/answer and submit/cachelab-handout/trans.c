/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, k, m, x;
    int temp[8], tempp;
    if(M == 32 && N == 32)
        for(i = 0; i < 32; i = i + 8)
            for(j = 0; j < 32; j++){
                for (k = 0; k < 8; k++)
                    temp[k] = A[j][i + k];
                for (k = 0; k < 8; k++)
                    B[i + k][j] = temp[k];
            }
                

    if(M == 64 && N == 64)
        for (i = 0; i < 64;i += 8)
            for (j = 0; j < 64; j += 8) {
                for (k = i; k < i + 4; ++k) {
                    for (x = 0; x < 8; x++)
                        temp[x] = A[k][j + x];

                    for (x = 0; x < 4; x++)
                        B[j + x][k] = temp[x];

                    for (x = 0; x < 4; x++)
                        B[j + x][k + 4] = temp[7 - x];
                }
                for (m = 0; m < 4; ++m) {
                    for (x = 0; x < 4; x++)
                        temp[x] = A[i + 4 + x][j + 3 - m];
                    for (x = 4; x < 8; x++)
                        temp[x] = A[i + x][j + 4 + m];

                    for (x = 0; x < 4; x++)
                        B[j + 4 + m][i + x] = B[j + 3 - m][i + 4 + x];

                    for (x = 0; x < 4; x++)
                        B[j + 3 - m][i + 4 + x] = temp[x];
                    for (x = 4; x < 8; x++)
                        B[j + 4 + m][i + x] = temp[x];
                }
            }

    if(M == 61 && N == 67)
        for(i = 0; i < 61; i = i + 16)
            for(j = 0; j < 67; j = j + 16)
                for(k = j; k < j + 16 && k < 67; ++k)
                    for(m = i; m < i + 16 && m < 61; ++m){
                        tempp = A[k][m];
                        B[m][k] = tempp;
                    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

