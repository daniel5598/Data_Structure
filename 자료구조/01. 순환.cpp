//순환에 대하여 알아봅시다
#include<stdio.h>
void main()
{			
	printf("안녕");
	main();
}

//1씩 감소된 값을 매개변수에 전달
#include<stdio.h>
void KK(int a) 
{
	if (a == 0)return;
	KK(a - 1);
	printf("%3d", a);
}
void main() 
{
	KK(3);
}

//1씩 증가된 값을 매개변수에 전달
#include<stdio.h>
void DispNum(int a)
{
	if (a == 3)return;
	DispNum(a + 1);
	printf("%3d", a);
}
void main()
{
	DispNum(0);
}

//1~10까지의 수를 재귀함수로 출력
#include<iostream>
#include<stdlib.h>
#include<time.h>
void recursive(int n) 
{
	if (n != 1)recursive(n - 1);
	printf("%d ", n);
}
void main(void)
{
	recursive(10);
}

//10~1까지의 수를 재귀함수로 출력
#include<iostream>
#include<stdlib.h>
#include<time.h>
void recursive(int n)
{
	printf("%d ", n);
	if (n != 1)recursive(n - 1);
}
void main(void)
{
	recursive(10);
}

//팩토리얼 값을 반환하는 factoiral 함수
#include<stdio.h>
int Factorial(int n)
{
	if (n == 0)return 1;
	else return n * Factorial(n - 1);
}
void main(void)
{
	printf("1!=%d \n", Factorial(1));
	printf("2!=%d \n", Factorial(2));
	printf("3!=%d \n", Factorial(3));
	printf("4!=%d \n", Factorial(4));
	printf("5!=%d \n", Factorial(5));
}

//n거듭제곱 값을 구하는 함수
#include<stdio.h>
double power(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}
void main()
{
	printf("2의 10제곱값: %f\n", power(2, 10));
}

//피보나치 수열
#include<stdio.h>
int Fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}
void main(void)
{
	int i;
	for (i = 1; i < 15; i++)
		printf("%d ", Fibo(i));
}

//숫자로 된 각 자릿수를 문자단어로 변경
#include<stdio.h>
#include<string.h>
char str[10];
char* getword(int n) {
	switch (n % 10) {
	case 0:strcpy(str, "zero "); break;
	case 1:strcpy(str, "one "); break;
	case 2:strcpy(str, "two "); break;
	case 3:strcpy(str, "three "); break;
	case 4:strcpy(str, "four "); break;
	case 5:strcpy(str, "five "); break;
	case 6:strcpy(str, "six "); break;
	case 7:strcpy(str, "seven "); break;
	case 8:strcpy(str, "eight "); break;
	case 9:strcpy(str, "nine "); break;
	}
	return str;
}
void dispword(int n)
{
	if (n < 10)printf("%s", getword(n));
	else
	{
		dispword(n / 10);
		printf("%s", getword(n));
	}
}
void main()
{
	int n;
	printf("정수 입력: ");
	scanf("%d", &n);
	dispword(n);
}

#include <stdio.h>
void KK1(int N)
{
	if (N == 0) return;
	KK1(N - 1);
	printf("%3d", N);
}
void KK2(int a, int N)
{
	printf("%3d", a);
	if (a == N)return;
	KK2(a + 1, N);
	printf("%3d", a);
}
void main()
{
	KK1(3);
	printf("\n");
	KK2(1, 3);
	printf("\n");
}

#include<stdio.h>
void Disp1(int a, int b)
{
	if (a > b)return;
	printf("%3d", a);
	Disp1(a + 1, b);
}
void Disp2(int a, int b)
{
	if (a < b)return;
	printf("%3d", a);
	Disp2(a - 1, b);
}
void Disp(int a, int b)
{
	if (b > a)
		Disp1(a, b);
	else
		Disp2(a, b);
	printf("\n");
}
void main()
{
	int a=1, b=3;
	Disp(a, b);
	Disp(b, a);
}

#include<iostream>
#include<stdlib.h>
#include<time.h>
int sum(int n)
{
	printf("%d , ", n);
	if (n < 1)
		return 0;
	else
		return n + sum(n - 1);
}
void main(void)
{
	printf("%d ", sum(5));
}

#include<iostream>
#include<stdlib.h>
#include<time.h>
int recursive(int n)
{
	printf("%d , ", n);
	if (n < 1) return 2;
	else return (2 * recursive(n - 1) + 1);
}
void main(void)
{
	printf("%d ", recursive(5));
}

#include<iostream>
#include<stdlib.h>
#include<time.h>
int recursive(int n)
{
	printf("%d , ", n);
	if (n < 1) return-1;
	else return(recursive(n - 3) + 1);
}
void main(void)
{
	printf("%d ", recursive(10));
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
int sub(int n)
{
	printf("%d , ", n);
	if (n < 0) return 0;
	return n + sub(n - 3);
}
void main(void)
{
	printf("%d ", sub(10));
}

#include<stdio.h>
int Sum1(int N)
{
	return (N <= 1 ? N : N + Sum1(N - 1));
}
int Sum(int a, int N)
{
	return (N <= a ? a : N + Sum(a, N - 1));
}
int Pow(int a, int N)
{
	return (N <= 1 ? a : a * Pow(a, N - 1));
}
int Fac(int N)
{
	return (N <= 1 ? 1 : N * Fac(N - 1));
}
void main()
{
	printf("%d\n", Sum1(3));
	printf("%d\n", Sum(1, 3));
	printf("%d\n", Pow(2, 3));
	printf("%d\n", Fac(3));
}

#include<stdio.h>
void BubbleSort(int ary[], int len);
int main(void) 
{
	int arr[4] = { 3,2,1,4 };
	int i;
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
void BubbleSort(int ary[], int len)
{
	int i, j;
	int temp;

	for (int i = 0; i < len - 1; i++) 
	{
		for (j = 0; j < (len - i) - 1; j++) 
		{
			if (ary[j] < ary[j + 1]) 
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}

#include<iostream>
#include<stdlib.h>
#include<time.h>
int sub(int n)
{
	printf("%d ", n);
	if (n < 0)
		return 0;
	return n + sub(n - 3);
}
void main(void)
{
	printf("%d ", sub(10));
}