#include <stdio.h>
#include <stdlib.h>
#include "06_1. Ω∫≈√_ArrayStack.h"

void main()
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", is_empty());
}