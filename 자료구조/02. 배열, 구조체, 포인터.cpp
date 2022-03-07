//1차원 배열을 받아서 배열의 내용 수정
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

//다항식을 배열로 표현
#include<stdio.h>
#define MAX_DEGREE 10
typedef struct { //다항식 구조체 타입 선언
	int degree; //다항식의 차수
	float coef[MAX_DEGREE]; //다항식의 계수
}polynominal;

void main()
{
	polynominal a = { 5,{3,6,0,0,0,10} };
	printf("%3d", a.degree);
	for (int i = 0; i < 6; i++) {
		printf("%3.0f", a.coef[i]);
	}
}

//다항식을 배열로 표현하고 덧셈
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
#define MAX_DEGREE 101

typedef struct { //다항식 구조체 타입 선언
	int degree; //다항식의 차수
	float coef[MAX_DEGREE]; //다항식의 계수
}polynominal;

//C=A+B 여기서 A와 B는 다항식이다.
polynominal poly_add1(polynominal A, polynominal B)
{
	polynominal C; //결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); //결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { //A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { //A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else { //B항 > A항
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