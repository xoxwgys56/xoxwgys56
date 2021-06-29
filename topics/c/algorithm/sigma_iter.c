#include <stdio.h>
#include <time.h>

typedef unsigned long long unlong;

int main()
{
	int num, cnt, i, k;
	unlong sum, prod;
	clock_t begin, end;
	
	while (1) {
		printf("<Sigma sum program by iteration>\n");
		printf("insert integer : ");
		scanf("%d", &num);
		if (num <= 0)
			break;
		printf("insert count : ");
		scanf("%d", &cnt);
		
		begin = clock();
		if (cnt <= 0)
			break;
		for (i = 1, sum = 0; i <= num; i++) {
			for (k = 0, prod = 1; k < cnt; k++) {
				prod *= i;
			}
			sum += prod;
			printf("%llu ", prod);
			if (i%5 == 0)
				printf("\n");
		}
		printf("\n");
		printf("sum of result : %llu\n", sum);
		end = clock();
		printf("[spent time is %f]\n", (double)(end - begin)/CLOCKS_PER_SEC);
	}
	return 0;
}
