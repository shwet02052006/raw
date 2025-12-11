#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int val) {
    if (top1 == MAX - 1) {
        printf("Stack1 Overflow\n");
        return;
    }
    stack1[++top1] = val;
}

void push2(int val) {
    if (top2 == MAX - 1) {
        printf("Stack2 Overflow\n");
        return;
    }
    stack2[++top2] = val;
}

int pop1() {
    if (top1 == -1) return -1;
    return stack1[top1--];
}

int pop2() {
    if (top2 == -1) return -1;
    return stack2[top2--];
}

void enqueue(int val) {
    push1(val);
    printf("Enqueued: %d\n", val);
}

int dequeue() {
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    int val = pop2();
    if (val == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    printf("Dequeued: %d\n", val);
    return val;
}

void displayQueue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    // First print stack2 (front of queue)
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    // Then print stack1 (back of queue)
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            displayQueue();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
