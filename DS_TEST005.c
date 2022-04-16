#include<stdio.h>
#include<stdlib.h>

typedef struct OLNode {
	int row, col, num;
	struct OLNode* right, * down;
}OLNode;

typedef struct {
	OLNode* rhead[100], * chead[100];
	int t_row, t_col, len;
}CrossList;

void InitMatrix(CrossList* p, int row, int col) {
	p->t_row = row;
	p->t_col = col;
	p->len = 0;
	for (int i = 1; i <= row; i++) {
		p->rhead[i] = NULL;
	}
	for (int i = 1; i <= col; i++) {
		p->chead[i] = NULL;
	}
}

void AddMatrix(CrossList* a, int t) {
	OLNode* p, * q;
	for (int i = 1; i <= t; i++) {
		int row, col, num;
		scanf("%d %d %d", &row, &col, &num);
		int flag = 0;
		for (q = a->rhead[row]; q; q = q->right) {
			if (q->col == col) {
				q->num += num;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;

	
		p = (OLNode*)malloc(sizeof(OLNode));
		p->row = row;
		p->col = col;
		p->num = num;

	
		if (a->rhead[row] == NULL || a->rhead[row]->col > col) {
			p->right = a->rhead[row];
			a->rhead[row] = p;
		}
	
		else {
			for (q = a->rhead[row]; (q->right) && q->right->col < col; q = q->right);
			p->right = q->right;
			q->right = p;
		}

		if (a->chead[col] == NULL || a->chead[col]->row > row) {
			p->down = a->chead[col];
			a->chead[col] = p;
		}
		else {
			for (q = a->chead[col]; (q->down) && q->down->row < row; q = q->down);
			p->down = q->down;
			q->down = p;
		}
	}
}

void Output(CrossList* a) {
	OLNode* p;
	for (int i = 1; i <= a->t_row; i++) {
		if (a->rhead[i] == NULL) {
			continue;
		}
		p = a->rhead[i];
		while (p) {
			if (p->num == 0) {
				p = p->right;
				continue;
			}
			printf("%d %d %d\n", p->row, p->col, p->num);
			p = p->right;
		}
	}
}

int main() {
	CrossList* p = (CrossList*)malloc(sizeof(CrossList));
	int m, n, t1, t2;
	scanf("%d %d %d %d ", &m, &n, &t1, &t2);
	InitMatrix(p, m, n);
	AddMatrix(p, t1);
	AddMatrix(p, t2);
	Output(p);
	return 0;
}
