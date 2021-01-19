
#include <iostream>
using namespace std;
struct node {
    node* next;
    int data;
};
struct queue {
    node* front;
    node* rear;
    int size;
};

void create_queue(queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
    
}
void enqueue(int value,queue *pq)
{
    node* pt = new node;
    pt->next = NULL;
    pt->data = value;

    if (pq->rear==NULL)
    {
        pq->front = pt;

    }
    else
    {
        pq->rear->next = pt;
    }
    pq->rear = pt;
    pq->size++;
}
int queue_size(queue* pq)
{

    return pq->size;
}
int dequeue(queue* pq)
{
    node* pt = pq->front;
    pq->front = pq->front->next;
    int value = pt->data;
    if (pq->front == NULL)
    {
        pq->rear = NULL;
    }
    delete pt;
    pq->size--;
    return value;
}
void display(queue *pq)
{
    node* pt = pq->front;
    while (pt != pq->rear)
    {
        cout << pt->data << " ";
        pt = pt->next;
    }
    if (pq->rear != NULL)
    {
        cout << pt->data;
    }
}
void clear_queue(queue* pq)
{
    node* pt = pq->front;
    node* temp = pt;
    while (pt != pq->rear)
    {
        pt = pt->next;
        delete temp;
        temp = pt;

    }
    if (pq->rear != NULL)
    {
        delete pt;
    }
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
int peek(queue* pq)
{
    return pq->front->data;
}
bool queue_empty(queue* pq)
{
    return !pq->size;
}

int main()
{
    queue qu;
    create_queue(&qu);
    enqueue(4, &qu);
    enqueue(8, &qu);
    enqueue(5, &qu);
    enqueue(12, &qu);
    clear_queue(&qu);

}