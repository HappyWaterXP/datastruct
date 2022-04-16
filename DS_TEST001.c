#include <stdio.h>
#include<malloc.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}Node, *LinkList;

void CreatList(LinkList L, int n) {
	Node *p = L;
	for (int i = 0; i < n; i++) {
		Node* q = (Node*)malloc(sizeof(Node));
		
		int temp;
		scanf("%d", &temp);
		
		q->data = temp;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}

void PrintList(LinkList L) {
	Node *p = L->next;
	while (p) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

void MergeList(LinkList L, LinkList L1, LinkList L2) {
	Node* p = L;
	Node* p1 = L1->next;
	Node* p2 = L2->next;
	while (p1 && p2) {

		Node* temp = (Node*)malloc(sizeof(Node));
		if (p1->data >= p2->data) {
			temp->data = p2->data;
			p->next = temp;
			p = temp;
			p2 = p2->next;

			//p->next = p2;
			//p = p2;
			//p2 = p2->next;  ֱ
		}
		else {
			temp->data = p1->data;
			p->next = temp;
			p = temp;
			p1 = p1->next;
		}
	}

	while (p1) {
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = p1->data;
		p->next = temp;
		p = temp;
		p1 = p1->next;
	}
	while (p2) {
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = p2->data;
		p->next = temp;
		p = temp;
		p2 = p2->next;
	}
	p->next = NULL;
}

int main() {
	LinkList L = (Node*)malloc(sizeof(Node));
	LinkList L1 = (Node*)malloc(sizeof(Node));
	LinkList L2 = (Node*)malloc(sizeof(Node));

	L->next = NULL;
	L1->next = NULL;
	L2->next = NULL;
	

	int n, m;
	scanf("%d", &n);
	CreatList(L1, n);
	scanf("%d", &m);
	CreatList(L2, m);


	MergeList(L, L1, L2);
	PrintList(L);
	
	return 0;
}