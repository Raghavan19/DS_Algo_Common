#include "stdio.h"
#include "stdlib.h"
#include <string.h>

typedef struct stackDS
{
	int top;
	int size;
	char * data;
} stackDS_t;


int push(stackDS_t *stack, char *item)
{
	int top = stack->top;
	char data = *item;
        printf("Push %c \n",*item);
	if(stack->top >= stack->size)
		return 0;
	*(stack->data+top) = data;
	printf("Pushed %c\n",*(stack->data+top));
	top++;
	stack->top = top;

}

int pop(stackDS_t *stack)
{
	if(stack->top == 0)
		return 0;
//	*(stack->data) = '0';
	stack->top--;
}

char* peek(stackDS_t *stack)
{
	int top = stack->top;
	return (stack->data+top);
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
	printf("The stack top is %d\n ",charStack.top);
	for(int j = charStack.top; j >= 0; j--)
	{
		printf("%c\n",*(peek(&charStack)));
		pop(&charStack);
	}



}

