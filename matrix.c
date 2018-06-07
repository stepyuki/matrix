#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main(int argc, char** argv)
{
 

  int n = 1;
  do{
    double* a = (double*)malloc(n * n * sizeof(double)); // Matrix A
    double* b = (double*)malloc(n * n * sizeof(double)); // Matrix B
    double* c = (double*)malloc(n * n * sizeof(double)); // Matrix C
    
    // Initialize the matrices to some values.
    int i, j,k;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	a[i * n + j] = i * n + j; // A[i][j]
	b[i * n + j] = j * n + i; // B[i][j]
	c[i * n + j] = 0; // C[i][j]
      }
    }

    double begin = get_time();
    
    /**************************************/
    /* Write code to calculate C = A * B. */
    /**************************************/
    double value;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	value = 0.0;
	for(k=0;k<n;k++){
	  value += a[i * n + k] * b[k * n + j];
	}
	c[i * n + j] = value;
      }
    }
        
    double end = get_time();
    printf("%d %.6lf\n",n, end - begin);
    n += 1;

    
    free(a);
    free(b);
    free(c);
  }while(n < 101);
  return 0;
}
