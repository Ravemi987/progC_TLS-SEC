#include <stdio.h>
#include <stdlib.h>


typedef struct s_cell {
    int value;
    struct s_cell *next;
} Cell;

typedef struct s_queue {
    struct s_cell *head;
    struct s_cell *tail;
    int size;
} Queue;


Queue *queueCreate(void) {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void queueDelete(Queue **q) {
    if (*q == NULL) {
        return;
    }

    Cell *curr = (*q)->head;
    Cell *prev;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
        prev = NULL;
    }

    free(*q);
    *q = NULL;
}

void queuePush(Queue *q, int v) {
    Cell *new_cell = malloc(sizeof(Cell));
    new_cell->value = v;
    new_cell-> next = NULL;

    if (q->size == 0) {
        q->head = new_cell;
    } else {
        q->tail->next = new_cell;
    }

    q->tail = new_cell;
    q->size++;
}

void queuePop(Queue *q) {
    if (q->head == NULL) {
        return;
    }

    Cell *toRemove = q->head;
    q->head = q->head->next;
    free(toRemove);
    toRemove = NULL;

    q->size--;
}

int queueSize(Queue *q) {
    return q->size;
}

int queueEmpty(Queue *q) {
    return q->size = 0;
}

void queuePrintHead(Queue *q) {
    if (q->head == NULL) {
        return;
    }

    printf("Head : %d\n", q->head->value);
}

void queuePrintTail(Queue *q) {
    if (q->tail == NULL) {
        return;
    }

    printf("Tail", q->tail->value);
}

void printQueue(Queue *q) {
    if (q->size == 0) {
        printf("File vide\n");
        return;
    }

    for (Cell *curr = q->head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    
    printf("\n");
}

int main(void) {
    Queue *q = queueCreate();

    printf("--- Ajout ---\n");

    queuePush(q, 1);
    printQueue(q);
    queuePush(q, 2);
    printQueue(q);
    queuePush(q, 3);
    printQueue(q);
    queuePush(q, 4);
    printQueue(q);

    queuePrintHead(q);
    queuePrintTail(q);

    printf("size : %d\n", queueSize(q));

    printf("---Suppression ---\n");

    printQueue(q);
    queuePop(q);
    printQueue(q);
    queuePop(q);
    printQueue(q);
    queuePop(q);
    printQueue(q);
    queuePop(q);
    printQueue(q);

    queueDelete(&q);

    return 0;
}
