#include "stdio.h"
#include "stdlib.h"
#include <string.h>

typedef struct stackDS
{
	int top;
	int size;
	char *data;
} stackDS_t;


int push(stackDS_t *stack, char *item)
{
	if(stack->top >= stack->size)
		return 0;
	*(stack->data+stack->top) = *item;
	stack->top++;
}

int pop(stackDS_t *stack)
{
	if(stack->top == 0)
		return 0;
	*(stack->data+stack->top) = '0';
	stack->top--;
}

char* peek(stackDS_t *stack)
{
	if((stack->top) == 0)
		return 0;
	return (stack->data+stack->top);

}


void main()
{

	stackDS_t charStack;
	charStack.size = 10;
        charStack.data = (char *)malloc(charStack.size);
	charStack.top = 0;

	char testString[] = "abcde";

	for(int i = 0; i < strlen(testString); i++)
	{
		push(&charStack, testString+i);
	}
	
	printf("The string is\n");
	printf("The stack top is%d",charStack.top);
	for(int j = charStack.top; j >= 0; j--)
	{
		printf("%c",*(peek(&charStack)));
		pop(&charStack);
	}



}

