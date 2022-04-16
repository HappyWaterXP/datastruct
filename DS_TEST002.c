#include <stdio.h>
#include <malloc.h>

typedef struct NODE {
	int data;
	struct NODE* pre;
	struct NODE* next;
}Node, *LinkList;

void CreatList(LinkList L, int n) {
	Node* p = L;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		Node* temp = (Node*)malloc(sizeof(Node));
		if (flag == 1) {
			temp->data = 1;
			flag = 0;
		}
		else
			temp->data = 0;
		
		
		p->next = temp;
		temp->pre = p;
		p = temp;
		
	}
	p->next = L;
	L->pre = p;
}


void PiDivide(Node* head, int n) {

	int temp = 0;
	Node* p = head->next;
	while (p != head) {
		temp = (p->data) % n;
		p->data = (p->data) / n;
		(p->next)->data = (p->next)->data + 10 * temp;
		p = p->next;
	}
}

void PiMultiply(Node* head, int n) {

	int Cin = 0;
	Node* p = head->pre;
	while (p != head) {
		p->data = (p->data) * n + Cin;
		Cin = (p->data) / 10;
		p->data = (p->data) % 10;
		p = p->pre;
	}
}



void MulList(LinkList L, int n) {
	int carry = 0;


	Node* p = L->pre;

	while (p != L) {
		
		int temp = p->data * n + carry;
		carry = temp / 10;
		p->data = temp % 10;
		//p->pre->data = p->pre->data + carry;
		p = p->pre;
	}
}

void DivList(LinkList L, int n) {
	int borrow;


	Node* p = L->next;

	while (p != L) {
		borrow = p->data % n;
		p->data = p->data / n;
		p->next->data = p->next->data + 10 * borrow;
		p = p->next;
	}
}

void AddList(LinkList Lans, LinkList Lr) {
	
	Node* pans = Lans->pre;
	Node* pr = Lr->pre;

	int carry = 0;

	while (pr != Lr) {
		int temp = pans->data + pr->data + carry;
		pans->data = temp % 10;
		carry = temp / 10;
		
		pr = pr->pre;
		pans = pans->pre;
	}
}

void PrintList(LinkList L, int n) {
	int flag = 1;
	Node* p = L->next;

	for (int i = 0; i <= n; i++) {
		printf("%d", p->data);
		if (flag == 1) {
			printf(".");
			flag = 0;
		}
		p = p->next;
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);

	LinkList Lans = (Node*)malloc(sizeof(Node));
	LinkList Lr = (Node*)malloc(sizeof(Node));
	Lans->next = Lans->pre = NULL;
	Lr->next = Lr->pre = NULL;

	CreatList(Lans, 1000);
	CreatList(Lr, 1000);

	for (int i = 1; i < 10000; i++) {
		MulList(Lr, i);
		//PiMultiply(Lr, i);
		DivList(Lr, i * 2 + 1);
		//PiDivide(Lr, i * 2 + 1);
		//MulList(Lr, i);

		AddList(Lans, Lr);
	}//Lans==pi/2

	//PiMultiply(Lans, 2);
	MulList(Lans, 2);
	//Lans==pi

	PrintList(Lans, n);

}