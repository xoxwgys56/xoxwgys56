#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*there is an error on dev-cpp that IDE can't execute program when uses MILLION macro*/

#define MILLION 1000000
#define HUNDRED_THOUSAND 100000
#define TEN_THOUSAND 10000
#define THOUSAND 1000
#define MSIZE HUNDRED_THOUSAND

//Too much long time
int max_consecutive_sum(int s[], int n) {
   int i, j, k, sum, max_sum = s[0];
   clock_t begin = clock();
   
   for (i=0; i<n; i++) {
      for (j=0; j<n; j++) {
         sum = 0;
         for (k=i; k<=j; k++)
            sum += s[k];
         if (sum > max_sum)
            max_sum = sum;
        
        printf("(top loop i=%d, mid loop j=%d, bottom loop k=%d)\t", i, j, k);
      	printf("[current spent time is %f]\n", ((double)(clock() - begin))/(double)CLOCKS_PER_SEC );
    	}
   }
   
   printf("[total spent time is %f]\n", ((double)(clock() - begin))/(double)CLOCKS_PER_SEC );
   return max_sum;
}

//Too much long time
int max_consecutive_sum2(int s[], int n) {
   int i, j , sum, max_sum = s[0];
   clock_t begin = clock();
   
   for (i=0; i<n; i++) {
      sum = 0;
      for (j=i; j<n; j++) {
         sum += s[j];
         if (sum > max_sum)
            max_sum = sum;
            
        printf("(top loop i=%d, bottom loop j=%d)\t", i, j);
        printf("[current spent time is %f]\n", ((double)(clock() - begin))/(double)CLOCKS_PER_SEC );
	  }
   }
   
   printf("[total spent time is %f]\n", ((double)(clock() - begin))/(double)CLOCKS_PER_SEC );
   return max_sum;
}

int max(int n1, int n2){
   if (n1 > n2)
      return n1;
   else
      return n2;
}

//OverFlow
int max_sum2(int s[], int n) {
   static int cnt2 = 0;
   printf("call %d times max_sum2()\n", cnt2++);
   
   if (n == 1)
      return s[0];
   
   return max(max_sum2(s, n-1) + s[n-1], s[n-1]);
}

//OverFlow
int max_sum1(int s[], int n) {
   static int cnt1 = 0;
   printf("call %d times max_sum1()\n", cnt1++);
   
   if (n == 1)
      return s[0];
   
   return max(max_sum2(s, n), max_sum1(s, n-1));
}

int c[MSIZE];

void calculate_max_consecutive_sum(int s[], int n) {
   int i;
   
   c[0] = s[0];
   for (i=1; i<n; i++)
      c[i] = max(s[i], s[i] + c[i-1]);
}

//OverFlow
int find_max_consecutive_sum(int s[], int n) {
   static int cnt3 = 0;
   printf("call %d times find_max_consecutive_sum()\n", cnt3++);
   
   if (n == 1)
      return s[0];
   
   return max(c[n-1], find_max_consecutive_sum(s, n-1));
}

int find_max_consecutive_sum2(int s[], int n) {
   int max_sum, i;
   
   max_sum = 0;
   for (i=0; i<n; i++) {
      if (c[i] > max_sum)
         max_sum = c[i];
   }
   
   return max_sum;
}

int main()
{
   int arr[MSIZE], i;
   int max_sum;
   srand( (unsigned)time(NULL));
   
   for (i=0; i<MSIZE; i++) {
      arr[i] = rand()%45;
   }
   printf("<array setting clear>\n");
   
   calculate_max_consecutive_sum(arr, MSIZE);
   
   //printf("max_sum = %d\n", max_consecutive_sum(arr, MSIZE));
   //printf("max_sum = %d\n", max_consecutive_sum2(arr, MSIZE));
   //printf("max_sum = %d\n", max_sum2(arr, MSIZE));
   //printf("max_sum = %d\n", max_sum1(arr, MSIZE));
   //printf("max_sum = %d\n", find_max_consecutive_sum(arr, MSIZE));
   printf("max_sum = %d\n", find_max_consecutive_sum2(arr, MSIZE));
   
   return 0;
}
