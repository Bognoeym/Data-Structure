#include <iostream>
using namespace std;

struct Stack
{
	int data;
	Stack* Link;
};

void Push(Stack** Top, int Data)
{
	Stack* newNode;

	newNode = new Stack;
	newNode->Link = *Top;
	newNode->data = Data;
	*Top = newNode;
}

void Pop(Stack** Top)
{
	Stack* tmp;
	tmp = *Top;
	*Top = tmp->Link;
	delete tmp;
}

void main()
{
	Stack* Top = NULL;

	Push(&Top, 10);
	Push(&Top, 7);
	Push(&Top, 23);

	Pop(&Top);
	Pop(&Top);
	Pop(&Top);
}