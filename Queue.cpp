#include <iostream>
using namespace std;

struct Queue
{
    int data;
    Queue* Link;
};

void Enqueue(Queue** Front, Queue** Rear, int data)
{
    Queue* NewNode, *tmp;
    if (*Front == NULL)
    {
        NewNode = new Queue;
        *Front = NewNode;
        *Rear = NewNode;
        NewNode->data = data;
        cout << "Push : " << NewNode->data << endl;
    }
    else
    {
        NewNode = new Queue;
        tmp = *Rear;
        tmp->Link = NewNode;
        *Rear = NewNode;
        NewNode->data = data;
        cout << "Push : " << NewNode->data << endl;
    }
}

void Dequeue(Queue** Front)
{
    Queue* tmp = *Front;
    *Front = tmp->Link;
    delete tmp;
}

void main()
{
    Queue* Front = NULL, * Rear = NULL;

    Enqueue(&Front, &Rear, 10);
    Enqueue(&Front, &Rear, 7);
    Enqueue(&Front, &Rear, 23);

    Dequeue(&Front);
    Dequeue(&Front);
    Dequeue(&Front);
}