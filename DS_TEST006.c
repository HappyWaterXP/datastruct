#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int row, col;   
	int data;      
}Triple;

typedef struct
{
	Triple elem[100];   
	int row, col, len;        
}TSMatrix;

TSMatrix InitMatrix(int m, int n)
{
	TSMatrix Mat;
	Mat.row = m;
	Mat.col = n;
	Mat.len = 0;
	return Mat;
}

void CreateMatrix(TSMatrix* mat)
{   
	int tmp_row, tmp_col, tmp_data;
	int i = 0;
	while (1) {
		scanf("%d%d%d", &tmp_row, &tmp_col, &tmp_data);
		if (tmp_row == 0 && tmp_col == 0 && tmp_data == 0) {
			break;
		}
		mat->elem[i].row = tmp_row;
		mat->elem[i].col = tmp_col;
		mat->elem[i].data = tmp_data;
		mat->len++;
		i++;
	}
}


void MulMatrix(TSMatrix* a, TSMatrix* b, TSMatrix* c)
{
	int cnt = -1, sum = 0, tmp_a = 0, tmp_b = 0;
	c->len = 0;
	for (int i = 1; i <= a->row; i++) {
		for (int j = 1; j <= b->col; j++) {
			sum = 0;
			for (int k = 1; k <= a->col; k++) {
				
				for (int m = 0; m < a->len; m++) {
					
					if (a->elem[m].row == i
						&& a->elem[m].col == k) {
						tmp_a = a->elem[m].data;
					}
				}
				for (int n = 0; n < b->len; n++) {
					
					if (b->elem[n].row == k
						&& b->elem[n].col == j) {
						tmp_b = b->elem[n].data;
					}
				}
				sum += tmp_a * tmp_b;
				tmp_a = 0, tmp_b = 0;
			}
			if (sum != 0) {
				cnt++;
				c->elem[cnt].data = sum;
				c->elem[cnt].row = i;
				c->elem[cnt].col = j;
				c->len++;
			}
		}
	}
}


void PrintMatrix(TSMatrix* c)
{  
	for (int i = 0; i < c->len; i++) {
		printf("%d %d %d\n", c->elem[i].row, c->elem[i].col, c->elem[i].data);
	}
}
int main()
{
	int m1, m2, n1, n2;
	scanf("%d%d", &m1, &n1);
	TSMatrix a = InitMatrix(m1, n1);
	CreateMatrix(&a);
	scanf("%d%d", &m2, &n2);
	TSMatrix b = InitMatrix(m2, n2);
	CreateMatrix(&b);
	TSMatrix c = InitMatrix(m1, n2);
	MulMatrix(&a, &b, &c);
	PrintMatrix(&c);
	return 0;
}