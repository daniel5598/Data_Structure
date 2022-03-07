#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "06_4. Ω∫≈√_LinkedListStack.h"

void main() {
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}