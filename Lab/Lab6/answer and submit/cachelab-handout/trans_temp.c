

{
    // int i,j,k,m,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;
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
