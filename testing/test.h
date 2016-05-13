//
//  test.h
//  testing
//
//  Created by Nhan Nguyen on 5/12/16.
//  Copyright © 2016 Nhan Nguyen. All rights reserved.
//

#ifndef test_h
#define test_h

#include <math.h>

int fibonaci1(int n) {
    if(n<1)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return (fibonaci1(n-1) + fibonaci1(n-2));
}


int fibonaci(int n) {
    if(n<=2)
        return n;
    int un1=1,un2=2;
    for (int i=3; i<=n; i++){
        un2 += un1;
        un1 = un2 - un1;
    }
    return un2;
}

/****** Priority Queue ********
 *  Interface:
 *  1. Init a queue
    2. Determine if a queue is empty
    3. Determine queue's size
    4. Add an element to a queue
    5. Pop an element at front.
    5. Remove an element from queue at front.
    6. Traverse from front to end of queue
    7. Clear queue
    8. Destroy queue
 *
 */
typedef struct Node_ {
    int priority;
    struct Node_ *next;
} Node;

typedef struct p_queue {
    int size;
    Node *front;
} P_Queue;

P_Queue *init_queue() {
    P_Queue *queue = (P_Queue*) malloc(sizeof(P_Queue));
    queue->size = 0;
    queue->front = NULL;
    return queue;
}

bool is_queue_empty(P_Queue *q){
    return !(q->size);
}

int qSize(P_Queue *q){
    return q->size;
}

void qAppend(P_Queue *q, int prior){
    Node *node = (Node*)malloc(sizeof(Node));
    node->priority = prior;
    node->next = NULL;
    if(!q->front){
        q->front = node;
        q->size++;
        return;
    } else {
        if(q->front->priority < prior){
            node->next = q->front->next;
            q->front = node;
            q->size++;
            return;
        }
    }
    //
    Node *p = q->front, *r = q->front;
    while(p != NULL || p->priority >= prior){
        r = p;
        p = p->next;
    }
    r->next = node;
    node->next = p;
    q->size++;
};

Node qPop(P_Queue *q){
    return *q->front;
}

void removeAtFront(P_Queue *q){
    if(q->front == NULL)
        return;
    Node *p = q->front;
    q->front = q->front->next;
    free(p);
    q->size--;
}

void traverse(P_Queue *q){
    Node *p = q->front;
    while(p!=NULL){
        printf("prior value: %d\n", p->priority);
        p = p->next;
    }
}

void clear(P_Queue *q){
    while(q->front != NULL){
        removeAtFront(q);
    }
}

void destroy(P_Queue *q){
    clear(q);
    free(q);
}

int Triangular(int n) {
    float t1 = sqrt(n = sqrt(2*n));
    float t2 = sqrt(n);
    printf("t1: %f t2: %f\n", t1, t2);
    bool t = t1*t2 == n;
    if(t) printf ("true: n = %d\n", n);
    else printf ("false: n = %d\n", n);
    return t;
}

#endif /* test_h */
