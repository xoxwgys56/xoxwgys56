#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///let's make a Joshepus problem by iterating

typedef struct person {
	int key;
	struct person *next;
}person;

person* killing_loop(person *pos);

int main()
{
	int num = 0, i, cnt = 0;
	person *new_person = NULL;
	person *head = NULL, *pos = NULL, *temp = NULL;
	clock_t begin, end;
	
	while (1) {
		printf("<Joshepus problem :: Recursion>\n");
		printf("insert numbers of person : ");
		scanf("%d", &num);
		//error::number is too small to count.
		if ( num < 2) {
			printf("[no one dead.]\n");
			return 0;
		}
		begin = clock();
		//make people node, circular structure.
		for (i = 1; i <= num; i++) {
			new_person = (person*)malloc(sizeof(person));
			new_person->next = NULL;
			new_person->key = i;
			if (head == NULL) {
				head = new_person;
			}else {
				pos->next = new_person;
			}
			pos = new_person;
		}
		pos->next = head;
		
		pos = head;
		//start killing
		pos = killing_loop(pos);
		printf("\n");
		printf("%d man is survived..\n", pos->key);
	
		temp = pos;
		free(temp);
		head = NULL;
		pos = NULL;
		temp = NULL;
	
		end = clock();
		printf("[spent time is %f]\n", (double)(end - begin)/CLOCKS_PER_SEC);
	}
	
	return 0;
}

//Recursion function
person* killing_loop(person *pos) {
	static int cnt = 0;
	person *temp = NULL;
	
	temp = pos->next;
	printf("%d\t", temp->key);
	
	if (pos->next->next == pos) {
		printf("%d\t", pos->key);
		return pos;
	}
		
	pos->next = pos->next->next;
	pos = pos->next;
	free(temp);
	
	cnt++;
	if (cnt%5 == 0)
		printf("\n");
	
	return killing_loop(pos);
}
