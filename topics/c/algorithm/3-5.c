#include <stdio.h>

int cnt = 0;

void print_arr(int bits[], int set_size) {
   int i;
   
   for (i=0; i<set_size; i++)
      printf("%d ", bits[i]);
   printf("cnt:%d\n", cnt);
   
   return ;
}

void comb2(int bits[], int n, int k, int index) {
   int i;
   
   if (k == 0) {
      for (i=index; i<n; i++)
         bits[i] = 0;
      print_arr(bits, n);
      printf("k==0::\t\tindex:%d,k:%d\n", index, k);
   }else if (index == n) {
      printf("index==0::\tindex:%d,k:%d\n", index, k);
      print_arr(bits, n);
      return ;
   }else {
      
      printf("else::\t\tindex:%d,k:%d\n", index, k);
      print_arr(bits, n);
      
      bits[index] = 0;
      printf("  <in> k, index+1\n");
      comb2(bits, n, k, index + 1);
      printf("  <out> k, index+1\n");
      bits[index] = 1;
      printf("\t\tindex:%d,k:%d\n", index, k);
      printf(" <in> k-1, index+1\n");
      comb2(bits, n, k-1, index+1);
      printf(" <out> k-1, index+1\n");
   }
   
   printf("end func::\tindex:%d,k:%d\n", index, k);
   print_arr(bits, n);
   cnt++;
   
   return ;
}

#define MAXN 100

int main()
{
   int set[MAXN] = {0}, n, k;
   
   printf("input n :");//how many bits are
   scanf("%d", &n);
   printf("input k :");//how many 1 is
   scanf("%d", &k);
   
   if (n < k) {
      printf("error::n must be bigger than k...\n");
   }else {
      comb2(set, n, k, 0);
   }
   
   return 0;
}

