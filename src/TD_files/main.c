#include <stdio.h>
#include <stdlib.h>


typedef struct s_queue {
    int value;
    struct s_queue *next;
} Queue;


Queue *queueCreate(void) {
    return NULL;
}

void queuePush(Queue **q, int v) {
    Queue *new_cell = (Queue *)malloc(sizeof(Queue));
    new_cell->value = v;
    new_cell->next = NULL;

    if (*q == NULL) {
        *q = new_cell;
        return;
    }

    Queue *curr = *q;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_cell;
}

Queue *queueRemove(Queue *q) {
    if (q == NULL) {
        return NULL;
    }

    Queue *n = q->next;
    free(q);
    return n;
}

void printTail(Queue *q) {
    if (q == NULL) {
        return;
    }

    printf("Tail : %d\n", q->value);
}

void printHead(Queue *q) {
    if (q == NULL) {
        return;
    }

    Queue *p = q;
    while (p->next != NULL) {
        p = p->next;
    }
    printf("Head : %d\n", p->value);
}

void printQueue(Queue *q) {
    if (q == NULL) {
        printf("File vide\n");
        return;
    }

    Queue *p = q;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    
    printf("\n");
}

int queueSize(Queue *q) {
    if (q == NULL) {
        return 0;
    }

    int i = 0;
    Queue *p = q;
    while (p != NULL) {
        p = p->next;
        i++;
    }

    return i;
}

int queueEmpty(Queue *q) {
    return queueSize(q) == 0;
}

int main(void) {

    Queue *q = queueCreate();

    printf("--- Ajout ---\n");

    queuePush(&q, 1);
    printQueue(q);
    queuePush(&q, 2);
    printQueue(q);
    queuePush(&q, 3);
    printQueue(q);
    queuePush(&q, 4);
    printQueue(q);

    printTail(q);
    printHead(q);

    printf("size : %d\n", queueSize(q));

    printf("---Suppression ---\n");

    printQueue(q);
    q = queueRemove(q);
    printQueue(q);
    q = queueRemove(q);
    printQueue(q);
    q = queueRemove(q);
    printQueue(q);
    q = queueRemove(q);
    printQueue(q);

    return 0;
}
