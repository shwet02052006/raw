#include <stdio.h>
#include <stdlib.h>

struct Node {
    int bill;              // bill amount
    struct Node *next;     // pointer to next node
};

struct Node *head = NULL;

// Function to add a new bill at the end
void addBill(int amount) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bill = amount;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Bill of Rs %d added successfully.\n", amount);
}

// Display all bills
void displayBills() {
    if (head == NULL) {
        printf("No bills recorded today.\n");
        return;
    }

    struct Node *temp = head;
    printf("Bills of the Day: ");
    while (temp != NULL) {
        printf("%d  ", temp->bill);
        temp = temp->next;
    }
    printf("\n");
}

// Total sale of the day
void totalSale() {
    if (head == NULL) {
        printf("No sales today.\n");
        return;
    }

    int sum = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        sum += temp->bill;
        temp = temp->next;
    }

    printf("Total Sale of the Day: Rs %d\n", sum);
}

// Maximum bill
void maximumBill() {
    if (head == NULL) {
        printf("No bills available.\n");
        return;
    }

    int max = head->bill;
    struct Node *temp = head->next;

    while (temp != NULL) {
        if (temp->bill > max)
            max = temp->bill;
        temp = temp->next;
    }

    printf("Maximum Bill of the Day: Rs %d\n", max);
}

// Minimum bill
void minimumBill() {
    if (head == NULL) {
        printf("No bills available.\n");
        return;
    }

    int min = head->bill;
    struct Node *temp = head->next;

    while (temp != NULL) {
        if (temp->bill < min)
            min = temp->bill;
        temp = temp->next;
    }

    printf("Minimum Bill of the Day: Rs %d\n", min);
}

int main() {
    int ch, amount;

    while (1) {
        printf("\n--- Coffee Shop Sales Menu ---\n");
        printf("1. Add Bill\n");
        printf("2. Display All Bills\n");
        printf("3. Total Sale of the Day\n");
        printf("4. Maximum Bill of the Day\n");
        printf("5. Minimum Bill of the Day\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter bill amount: ");
                scanf("%d", &amount);
                addBill(amount);
                break;

            case 2:
                displayBills();
                break;

            case 3:
                totalSale();
                break;

            case 4:
                maximumBill();
                break;

            case 5:
                minimumBill();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
