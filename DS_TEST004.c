#include<stdio.h>
#include <stdlib.h>

typedef struct Triple
{
	int row;
	int col;
	int value;
}Triple;
typedef struct
{
	Triple data[1000];
}Matrix;

void CreatMatrix(Matrix* p, int t){
	for (int i = 0; i < t; i++)
		scanf("%d %d %d", &p->data[i].row, &p->data[i].col, &p->data[i].value);
}
void AddMatrix(Matrix* p1, Matrix* p2, Matrix* p, int* t1, int* t2){
	for (int i = 0; i < *t1; i++){
		p->data[i].row = p1->data[i].row;
		p->data[i].col = p1->data[i].col;
		p->data[i].value = p1->data[i].value;
	}

	for (int i = 0; i < *t2; i++){
		for (int j = 0; j < *t1; j++)
		{
			if (p->data[j].row == p2->data[i].row && p->data[j].col == p2->data[i].col)
			{
				p->data[j].value = p->data[j].value + p2->data[i].value;
				for (int k = i; k < *t2; k++)
				{
					p2->data[k].row = p2->data[k + 1].row;
					p2->data[k].col = p2->data[k + 1].col;
					p2->data[k].value = p2->data[k + 1].value;
				}
				(*t2)--;
				i--;
				break;
			}
		}
	}

	int t = *t1;
	for (int i = 0; i < *t2; i++, t++){
		p->data[t].row = p2->data[i].row;
		p->data[t].col = p2->data[i].col;
		p->data[t].value = p2->data[i].value;
	}

	for (int i = 0; i < *t1 + *t2 - 1; i++)
		for (int j = 0; j < *t1 + *t2 - 1 - i; j++)
			if ((p->data[j].row > p->data[j + 1].row) || (p->data[j].row == p->data[j + 1].row && p->data[j].col > p->data[j + 1].col))
			{
				int temp;
				temp = p->data[j].row, p->data[j].row = p->data[j + 1].row, p->data[j + 1].row = temp;
				temp = p->data[j].col, p->data[j].col = p->data[j + 1].col, p->data[j + 1].col = temp;
				temp = p->data[j].value, p->data[j].value = p->data[j + 1].value, p->data[j + 1].value = temp;
			}
	t = *t1 + *t2;
	for (int i = 0; i < t; i++)
	{
		if (p->data[i].value == 0) //����0��Ԫ��ɾ��
		{
			for (int k = i; k < t; k++)
			{
				p->data[k].row = p->data[k + 1].row;
				p->data[k].col = p->data[k + 1].col;
				p->data[k].value = p->data[k + 1].value;
			}
			(*t2)--;
			t--;

		}
	}

}
void PrintMatrix(Matrix* n, int j)//�������.j��Ԫ��
{
	for (int i = 0; i < j; i++)
	{
		printf("%d ", n->data[i].row);
		printf("%d ", n->data[i].col);
		printf("%d ", n->data[i].value);
		printf("\n");

	}
}
int main()
{
	int m, n, k1, k2;
	scanf("%d %d %d %d", &m, &n, &k1, &k2);
	Matrix* p1, * p2, * p;
	p1 = (Matrix*)malloc(sizeof(Matrix));
	p2 = (Matrix*)malloc(sizeof(Matrix));
	p = (Matrix*)malloc(sizeof(Matrix));
	CreatMatrix(p1, k1);
	CreatMatrix(p2, k2);
	AddMatrix(p1, p2, p, &k1, &k2);
	PrintMatrix(p, k1 + k2);
	return 0;
}