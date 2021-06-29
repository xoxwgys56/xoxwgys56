#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///let's make a Joshepus problem by iterating

typedef struct person {
	int key;
	struct person *next;
}person;

int main()
{
	int num = 0, i, cnt = 1;
	person *new_person = NULL;
	person *head = NULL, *pos = NULL, *temp = NULL;
	clock_t begin, end;
	while (1) {
		printf("<Joshepus problem :: iterate>\n");
		printf("insert numbers of person : ");
		scanf("%d", &num);
		//error::number is too small to count.
		if ( num < 2) {
			printf("[no one dead.]\n");
			break;
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
		cnt = 0;
		while (pos != pos->next) {
			temp = pos->next;
			printf("%d\t", temp->key);
			pos->next = pos->next->next;
			pos = pos->next;
			free(temp);
		
			cnt += 1;
			if (cnt%5 == 0)
				printf("\n");
		}
		printf("\n");
		printf("%d\n%d man is survived..\n", pos->key, pos->key);
		
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
