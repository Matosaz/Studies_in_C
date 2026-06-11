#include <corecrt_search.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
    int size;
} Queue;

Node* newNo(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

Queue* newQueue(void){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

        
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue){
    return queue->size == 0;
}


void add(Queue* queue, int value){
    Node* node = newNo(value);
    if(isEmpty(queue)){
        queue->front = node;
        queue->rear = node;
    }else{
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

void removeQueue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return;
    }
    int value = queue->front->data;
    Node* node = queue->front;
    
    if(queue->front == queue->rear){
        queue-> front = NULL;
        queue-> rear = NULL;
    }else{
        queue->front = queue->front->next;
    }
    free(node);
    queue->size--;
}


int main(){
    Queue* queue = newQueue();
    add(queue, 10);
    add(queue, 20);
    add(queue, 30);
}