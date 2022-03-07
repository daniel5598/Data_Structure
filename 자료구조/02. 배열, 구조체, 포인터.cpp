//1���� �迭�� �޾Ƽ� �迭�� ���� ����
#include <stdio.h>
#define MAX_SIZE 10

void sub(int var, int list[])
{
	var = 10;
	list[0] = 10;
}
void main()
{
	int var;
	int list[MAX_SIZE];
	var = 0;
	list[0] = 0;
	sub(var, list);
	printf("var=%d, list[0]=%d\n", var, list[0]);
}

//���׽��� �迭�� ǥ��
#include<stdio.h>
#define MAX_DEGREE 10
typedef struct { //���׽� ����ü Ÿ�� ����
	int degree; //���׽��� ����
	float coef[MAX_DEGREE]; //���׽��� ���
}polynominal;

void main()
{
	polynominal a = { 5,{3,6,0,0,0,10} };
	printf("%3d", a.degree);
	for (int i = 0; i < 6; i++) {
		printf("%3.0f", a.coef[i]);
	}
}

//���׽��� �迭�� ǥ���ϰ� ����
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
#define MAX_DEGREE 101

typedef struct { //���׽� ����ü Ÿ�� ����
	int degree; //���׽��� ����
	float coef[MAX_DEGREE]; //���׽��� ���
}polynominal;

//C=A+B ���⼭ A�� B�� ���׽��̴�.
polynominal poly_add1(polynominal A, polynominal B)
{
	polynominal C; //��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0; //�迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); //��� ���׽� ����

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { //A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { //A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else { //B�� > A��
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void main()
{
	polynominal a = { 5,{3,6,0,0,0,10} };
	polynominal b = { 4,{7,0,5,0,1} };

	polynominal c;
	c = poly_add1(a, b);

	printf("%3d", c.degree);
	for (int i = 0; i < 6; i++)
		printf("%3.0f", c.coef[i]);
}