#include <stdio.h>
#include <time.h>

typedef unsigned long long unlong;

unlong product(int num, int prod) {
	if (prod <= 1 )
		return num;
	else
		return num*product(num, prod-1);
}

unlong sigma(int num, int prod) {
	static int cnt = 1;
	unlong sum = 0;
	sum = product(num, prod);
	printf("%llu ", sum);
	if (cnt%5 == 0)
		printf("\n");
	cnt++;
	if (num <= 1)
		return sum;
	else
		return sum + sigma(num-1, prod);
}

int main()
{
	int num, cnt, i, k;
	unlong sum = 0, prod;
	clock_t begin, end;
	while (1) {
		printf("<Sigma sum program by recursion>\n");
		printf("insert integer : ");
		scanf("%d", &num);
		if (num <= 0)
			break;
		printf("insert count : ");
		scanf("%d", &cnt);
		if (cnt <= -1)
			cnt = abs(cnt);//there is no minus value permission.
	
		begin = clock();
		sum = sigma(num, cnt);
		printf("\n");
		printf("sum of result : %llu\n", sum);
	
		end = clock();
		printf("[spent time is %f]\n", (double)(end - begin)/CLOCKS_PER_SEC);
	}
	return 0;
}
