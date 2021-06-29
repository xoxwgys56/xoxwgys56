#include <stdio.h>
#include <stdlib.h>

///Let's make a queue~ 

/* �ȵǴ� �ڵ忡 ���Ͽ� ���� �����÷ο쿡 ������ �÷ȴ���, ���� ������ ��������, 
 ���� ������ ���� ����� �̾߱⸸ ������Ƿ� ������� �ʱ�� �Ѵ�.*/

typedef struct NODE{
	int key;
	struct NODE *next;//�� ���� ��, �׸��� ���� ���� �� �Ʒ��� �ֱ� ������ next���� prev���� �����Ͽ���. 
}NODE;

void work_place();
NODE* insert_node(NODE *head, NODE* cur_pos);
NODE* dequeue(NODE *head, NODE *cur_pos, int sel);
NODE* find_head(NODE *cur_pos);

int main()
{
	work_place();
	
	return 0;
}

void work_place() {
	NODE *head, *cur_pos;
	int sel = 0;
	
	head = NULL;
	cur_pos = NULL;
	
	while( sel != 4) {
		printf("1.insert  2.delete  3.print  4.exit\n:");
		scanf("%d", &sel);
		
		switch(sel) {
			case 1 : cur_pos = insert_node(head, cur_pos);
					head = find_head(cur_pos);
				break;
			case 2 : cur_pos = dequeue(head, cur_pos, 1);
					head = find_head(cur_pos);
				break;
			case 3 : cur_pos = dequeue(head, cur_pos, 2);
				break;
			case 4 :
				printf("exit the program..\n");
				break;
			default :
				printf("error:wrong order.\n");
		}
	}
	
	return ;
}

NODE* find_head(NODE *cur_pos) {
	NODE *search_node = NULL;
	NODE *head = NULL;
	
	search_node = cur_pos;
	/*if (searhc_node == NULL) {
		return NULL;
	}*/
	while (search_node != NULL) {
		head = search_node;
		search_node = search_node->next;
	}
	
	return head;
}

NODE* insert_node(NODE *head, NODE* cur_pos) {
	int value = 0;
	NODE *new_node = NULL;
	
	printf("insert the value : ");
	scanf("%d", &value);
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node->key = value;	
	
	if (head == NULL) {
		head = new_node;
		cur_pos = new_node;
		new_node->next = NULL;
	}else {
		new_node->next = cur_pos;
		cur_pos = new_node;
	}
	
	return cur_pos;
}

NODE* dequeue(NODE *head, NODE *cur_pos, int sel) {
	NODE *search_node = NULL;
	NODE *buf_head = NULL, *buf_cur_pos = NULL;
	NODE *new_node = NULL;
	NODE *temp_node = NULL;
	//if, there is no value to push out.
	if (head == NULL) {
		printf("error:there is no value.\n");
		return NULL;
	}
	//if, there is only one value.
	if (cur_pos == head && sel == 1) {
		temp_node = cur_pos;
		free(temp_node);
		cur_pos = NULL;
		head = NULL;
		return cur_pos;
	}
	//if, there is only two value.
	if (cur_pos->next == head && sel == 1) {
		temp_node = cur_pos;
		cur_pos = cur_pos->next;
		free(temp_node);
		head = cur_pos;
		cur_pos = head;
		return cur_pos;
	}
	
	//copy
	search_node = cur_pos;
	while (search_node != NULL) {
		new_node = (NODE*)malloc(sizeof(NODE));
		new_node->key = search_node->key;
		
		if (buf_head == NULL) {
			buf_head = new_node;
			buf_cur_pos = new_node;
			buf_head->next = NULL;
		}else {
			new_node->next = buf_cur_pos;
			buf_cur_pos = new_node;
		}
		
		search_node = search_node->next;
	}
	
	//delete source stack
	search_node = cur_pos;
	while (search_node != NULL) {
		temp_node = search_node;
		search_node = search_node->next;
		free(temp_node);//delete!
	}
	head = NULL;
	cur_pos = NULL;
		
	/*delete value of goal*/
	if (sel == 1) {
		temp_node = buf_cur_pos;
		buf_cur_pos = buf_cur_pos->next;
		free(temp_node);
	}
	
	/*print_all_value*/
	if (sel == 2) {
		search_node = buf_cur_pos;
		while (search_node != NULL) {
			printf("%d ", search_node->key);
			search_node = search_node->next;
			//printf("%x\n", search_node->next);
		}
		printf("\n");
	}

	//return to the source stack
	search_node = buf_cur_pos;
	while (search_node != NULL) {
		new_node = (NODE*)malloc(sizeof(NODE));
		new_node->key = search_node->key;
		
		if (head == NULL) {
			head = new_node;
			cur_pos = new_node;
			head->next = NULL;
		}else {
			new_node->next = cur_pos;
			cur_pos = new_node;
		}
		
		search_node = search_node->next;
	}
	
	//delete buffer stack
	search_node = buf_cur_pos;
	while (search_node != NULL) {
		temp_node = search_node;
		search_node = search_node->next;
		free(temp_node);//delete!
	}
	buf_head = NULL;
	buf_cur_pos = NULL;
	
	return cur_pos;
}
