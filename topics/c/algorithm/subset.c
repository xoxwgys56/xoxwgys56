#include <stdio.h>
#include <time.h>

void print_arr(int bits[], int set_size) {
   int i;
   
   for (i=0; i<set_size; i++)
      printf("%d ", bits[i]);
      
   return ;
}

void subset(int set[], int set_size, int n, int index) {
   if (index == n) {
      //print_arr(set, set_size);
      return ;
   }
   set[set_size] = index;
   subset(set, set_size+1, n, index+1);
   
   subset(set, set_size, n, index+1);
}

#define MAXN 100

int main()
{
   int set[MAXN] = {0}, n;
   clock_t begin;
   
   printf("input n : ");
   scanf("%d", &n);
   
   begin = clock();
   subset(set, 0, n, 0);
   
   printf("[execution time : %f]", (double)(clock() - begin)/(double)CLOCKS_PER_SEC );
   
   return 0;
}
