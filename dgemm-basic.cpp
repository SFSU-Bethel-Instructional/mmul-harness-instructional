const char* dgemm_desc = "Basic implementation, three-loop dgemm.";

/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 */
void square_dgemm(int n, double* A, double* B, double* C)
{
   //Then add our triple for-loop
   for (int i = 0; i < n; i++){
     for(int j = 0; j < n; j++){
       C[j*n + i] = 0;
       for(int k = 0; k < n; k++){
         //
        //Row major order:
        //prod[i][j] += A[i][k] + B[k][j]
        //Column major order:
        //prod[i][j] += A[k][j] + B[i][k]
        C[j*n + i] = C[j*n + i] + A[k*n + i] * B[j*n + k];
       }
     }
   }

}
