#include <stdio.h>

///find max or min value

int get_min(int n1, int n2, int n3);
int get_max(int n1, int n2, int n3);

int main()
{
	int minN = 0, maxN = 0;	
	
	minN = get_min(1, 2, 3);
	maxN = get_max(1, 2, 3);
	
	printf("Max number : %d, Min number : %d\n", maxN, minN);
	
	return 0;
}

int get_min(int n1, int n2, int n3) {
	if (n1 < n2 && n1 < n3)
		return n1;
	if (n2 < n1 && n2 < n3)
		return n2;
	if (n3 < n1 && n3 < n2)
		return n3;
}

int get_max (int n1, int n2, int n3) {
	if (n1 > n2 && n1 > n3)
		return n1;
	if (n2 > n1 && n2 > n3)
		return n2;
	if (n3 > n1 && n3 > n2)
		return n3;	
}
