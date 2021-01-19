#include <iostream>
using namespace std  ;
#define max_size 1000
struct queue
{
    int arr[max_size];
    int rear;
        int front;
        int size;
};
void create_queue( queue *pt)
{
    pt->rear = -1;
    pt->front = -1;
    pt->size = 0;
}
void enqueue(int value, queue* pt)
{
    pt->arr[++pt->rear%max_size] = value;
    pt->size++;
    if (pt->front == -1)
    {
        pt->front++;
    }

}
int dequeue(queue* pt)
{
    int value_front = pt->arr[pt->front];
    pt->size--;
    pt->front = (pt->front + 1) % max_size;
    return value_front;
}
int peek(queue* pt)
{
    return pt->arr[pt->front];
}
int empty_queue(queue *pt)
{
    return !pt->size;
}
int queue_size(queue *pt)
{
    return pt->size;
}
int queue_full(queue* pt)
{
    return pt->size == max_size;

}
void clear_queue(queue* pt)
{
    pt->size = 0;
    pt->front = -1;
    pt->rear = -1;
}
void Display_queue(queue* pt)
{
    int pos = pt->front;

    while (pos != pt->rear)
    {
        cout << pt->arr[pos] << endl;
        pos = pos + 1 % max_size;
    }
    if (pt->size != 0)
    {
        cout << pt->arr[pos] << endl;
    }

}


int main()
{
    queue qq;
    create_queue(&qq);
}

