#include <stdio.h>
#include <stdlib.h>

///let's make a linked list

struct node{
   int key;
   struct node *next;
};

typedef struct node node_t;

node_t *head = NULL, *tail = NULL;

void insert_node(int n);
int delete_node();
void print_node();

int main()
{
   int sel = 0, value = 1;
   int dest = 0;
   
   while (1) {
      
      printf("menu::1.insert  2.delete  3.print::\n");
      scanf("%d", &sel);
      
      switch (sel) {
         case 1 : 
            //printf("insert value : ");
            //scanf("%d", &value);//���� ���� ����ڿ��� �ް� �ʹٸ� �̿��Ѵ�. 
            insert_node(value++);
            break;
         case 2 : dest = delete_node();
         		if (dest != -1)
         			printf("%d deleted.\n", dest);//������ ���� -1�� �ƴ� ��  ����Ѵ�. 
            break;
         case 3 : print_node();
            break;
         default :
            printf("error::wrong choose\n");
      }
   }
   return 0;
}

void print_node() {
   node_t *pos = head;
   
   if (head == NULL) {
      printf("error:there is no key value\n");
      return ;   
   }
   
   while (1) {
      printf("myAdd:%x\t%d\tmyPrevAdd:%x\n",pos, pos->key, pos->next);
      if (pos->next == NULL)
         break;
      pos = pos->next;
   }
   printf("\n");
}

void insert_node(int n) {
   node_t *new_node = (node_t *)malloc(sizeof(node_t));
   
   new_node->key = n;
   new_node->next = NULL;
   if (head == NULL) {//��尡 �������� ���� �� ���� ������� ��带 ���� �����Ѵ�. 
      head = new_node;
      tail = new_node;
   } else {
      tail->next = new_node;//�ܹ��⼺���� ���� ���� ���� �������� ������ ��带 ����Ų��.
      tail = new_node;
   }
}

int delete_node() {
   node_t *node;
   int r;
   
   if (head == NULL) {
		printf("error:there is no key to print.\n");//�ƹ� ���� ���� �� ���� ������ �� �� ������ ������ش�.
    	return -1;
	}
   node = head;
   head = head->next;
   if (head == NULL)
      tail = NULL;
   
   r = node->key;
   free(node);
   return r;//������ ���� ��ȯ�Ѵ�. 
}
