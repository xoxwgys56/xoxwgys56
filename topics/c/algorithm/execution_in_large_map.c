#include <stdio.h>
#include <time.h>

#define M 100
#define N 100

int map[M][N];

long long num_path(int m, int n) {
	if (map[m][n] == 0)
		return 0;
	if (m == 0 && n == 0)
		return 1;
	
	return ( (m>0) ? num_path(m-1, n) : 0) + ( (n>0) ? num_path(m, n-1) : 0);
}

int work_place() {
	clock_t begin, end;
	int i, j;
	int m, n;
	
	printf("insert m : ");
	scanf("%d", &m);
	printf("insert n : ");
	scanf("%d", &n);
	
	begin = clock();
	if (m <= 0 || n <= 0) {
		return 1;
	}
	
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			//printf(":");
			map[i][j] = 1; //scanf("%d", &map[i][j]);
		}
	}
	printf("%lld\n", num_path(m-1, n-1));

	printf("[spent time is %f]\n", (double)(clock() - begin)/(double)(CLOCKS_PER_SEC));	

	return 0;
}

int main()
{
	int loop;
	while (loop != 1) {
		loop = work_place();
	}	
	
	printf("program exit..\n");
	
	return 0;
}
