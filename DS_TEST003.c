#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Triple {
	int row, col;
	int num;
}Triple;

typedef struct Matrix {
	Triple data[1000];
	int t_row, t_col, len;
}Matrix;

Matrix* InitMatrix() {
	Matrix* p = (Matrix*)malloc(sizeof(Matrix));
	p->t_row = 0;
	p->t_col = 0;
	p->len = 0;
	return p;
}

void Insert(Matrix* p, int row, int col, int num, int i) {
	p->data[i].row = row;
	p->data[i].col = col;
	p->data[i].num = num;
	p->len = p->len + 1;
}

void BuildMatrix(Matrix* p) {
	int i = 0, col, row, num;
	while (1) {
		scanf("%d %d %d", &row, &col, &num);
		if (row == 0 && col == 0 && num == 0)
			break;

		else {
			Insert(p, row, col, num, i);
			i++;
		}
	}
}

void PrintMatrix(Matrix* p) {
	for (int i = 0; i < p->len; i++) {
		printf("%d %d %d \n", p->data[i].row, p->data[i].col, p->data[i].num);
	}
}

void Transposition(Matrix* p1, Matrix* p2) {
	int* num, * position, tmp_col, tmp_position;
	int tmp_col_n = p1->t_col + 1;
	num = (int*)malloc(sizeof(int) * tmp_col_n);
	position = (int*)malloc(sizeof(int) * tmp_col_n);
	p2->t_row = p1->t_col;
	p2->t_col = p1->t_row;
	p2->len = p1->len;
	for (int i = 0; i < p1->t_col; i++) {

		num[i] = 0;
	}
	for (int i = 0; i < p1->len; i++) {
		
		num[p1->data[i].col]++;
	}
	position[0] = 0;
	for (int i = 1; i < p1->t_col; i++) {

		position[i] = position[i - 1] + num[i - 1];
	}
	for (int i = 0; i < p1->len; i++) {

		tmp_col = p1->data[i].col;
		tmp_position = position[tmp_col];
		p2->data[tmp_position].row = p1->data[i].col;
		p2->data[tmp_position].col = p1->data[i].row;
		p2->data[tmp_position].num = p1->data[i].num;
		position[tmp_col]++;
	}

}

int main() {
	Matrix* p1 = InitMatrix();
	Matrix* p2 = InitMatrix();
	int row, col;
	scanf("%d%d", &row, &col);
	p2->t_row = p1->t_col = row;
	p2->t_col = p1->t_row = col;

	BuildMatrix(p1);
	Transposition(p1, p2);
	PrintMatrix(p2);
	return 0;
}
