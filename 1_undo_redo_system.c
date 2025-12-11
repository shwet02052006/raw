#include <stdio.h>
#include <stdlib.h>

#define N 10

char text[N];
char redoStack[N];
int topText = -1;
int topRedo = -1;

void pushText(char ch)
{
    if (topText < N - 1)
    {
        text[++topText] = ch;
    }
    else
    {
        printf("Text buffer full\n");
    }
}

char popText()
{
    if (topText > -1)
    {
        return text[topText--];
    }
    return '\0';
}

void pushRedo(char ch)
{
    if (topRedo < N - 1)
    {
        redoStack[++topRedo] = ch;
    }
    else
    {
        printf("Redo stack overflow\n");
    }
}

char popRedo()
{
    if (topRedo > -1)
    {
        return redoStack[topRedo--];
    }
    return '\0';
}

void displayText()
{
    printf("Current Text: ");
    for (int i = 0; i <= topText; i++)
    {
        printf("%c", text[i]);
    }
    printf("\n");
}

int main()
{
    char ch;
    int choice;
    printf("---- Menu Choice ---- ");

    while (1)
    {
        printf("\n1. Push\n2. Undo\n3. Redo\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter character to push: ");
                scanf(" %c", &ch);
                pushText(ch);
                topRedo = -1;  // Clear redo stack
                break;

            case 2:
                if (topText > -1)
                {
                    char undoChar = popText();
                    pushRedo(undoChar);
                    printf("Undo: Removed %c\n", undoChar);
                }
                else
                {
                    printf("Nothing to undo.\n");
                }
                break;

            case 3:
                if (topRedo >= 0)
                {
                    char redoChar = popRedo();
                    pushText(redoChar);
                    printf("Redo: Restored %c\n", redoChar);
                }
                else
                {
                    printf("Nothing to redo.\n");
                }
                break;

            case 4:
                displayText();
                break;

            case 5:
                printf("Exited");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}


























// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 50
// char undoStack[MAX][200];
// int undoTop = -1;
// char redoStack[MAX][200];
// int redoTop = -1;
// void push(char s[][200], int *top, const char *str)
// {
//     if (*top >= MAX - 1)
//     {
//         printf("Stack full\n");
//         return;
//     }
//     strcpy(s[++(*top)], str);
// }
// char *pop(char s[][200], int *top)
// {
//     if (*top == -1)
//         return NULL;
//     return s[(*top)--];
// }
// void performAction(const char *action)
// {
//     push(undoStack, &undoTop, action);
//     // clear redo stack when new action is performed
//     redoTop = -1;
//     printf("Action performed: %s\n", action);
// }
// void doUndo()
// {
//     char *a = pop(undoStack, &undoTop);
//     if (a == NULL)
//     {
//         printf("Nothing to undo!\n");
//         return;
//     }
//     push(redoStack, &redoTop, a);
//     printf("Undo: %s\n", a);
// }
// void doRedo()
// {
//     char *a = pop(redoStack, &redoTop);
//     if (a == NULL)
//     {
//         printf("Nothing to redo!\n");
//         return;
//     }
//     push(undoStack, &undoTop, a);
//     printf("Redo: %s\n", a);
// }
// int main()
// {
//     int choice;
//     char input[200];
//     // Sample interactive loop (for demo we will simulate a few actions)
//     printf("1. Perform Action\n2. Undo\n3. Redo\n4. Exit\n");
//     // In real run user enters choices; sample run below demonstrates sequence
//     printf("Enter choice: 1\n");
//     printf("Enter action: Type 'First action'\n");
//     performAction("First action");
//     printf("\nEnter choice: 1\n");
//     printf("Enter action: Type 'Second action'\n");

//     performAction("Second action");
//     printf("\nEnter choice: 2\n");
//     doUndo();
//     printf("\nEnter choice: 2\n");
//     doUndo();
//     printf("\nEnter choice: 3\n");
//     doRedo();
//     printf("\nEnter choice: 4\n");
//     printf("Exiting.\n");
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define MAX 100
// #define SIZE 10

// char text[MAX] = "";

// char undoStack[SIZE][MAX];
// char redoStack[SIZE][MAX];
// int undoTop = -1;
// int redoTop = -1;

// void push(char stack[][MAX], int *top, const char *value) {
//     if (*top >= SIZE - 1) {
//         for (int i = 0; i < SIZE - 1; ++i) {
//             strcpy(stack[i], stack[i + 1]);
//         }
//         strcpy(stack[SIZE - 1], value);
//         *top = SIZE - 1;
//     } else {
//         (*top)++;
//         strcpy(stack[*top], value);
//     }
// }

// char* pop(char stack[][MAX], int *top) {
//     if (*top < 0) return NULL;
//     return stack[(*top)--];
// }

// void clearStack(int *top) {
//     *top = -1;
// }

// void typeText() {
//     char newText[MAX];
//     printf("Enter new text: ");
//     scanf(" %[^\n]", newText);

//     push(undoStack, &undoTop, text);
//     clearStack(&redoTop);
//     strncpy(text, newText, MAX - 1);
//     text[MAX - 1] = '\0';
// }

// void undo() {
//     char *prev;
//     if (undoTop < 0) {
//         printf("Nothing to undo!\n");
//         return;
//     }
//     push(redoStack, &redoTop, text);
//     prev = pop(undoStack, &undoTop);
//     if (prev) strcpy(text, prev);
//     else text[0] = '\0';
// }

// void redo() {
//     char *next;
//     if (redoTop < 0) {
//         printf("Nothing to redo!\n");
//         return;
//     }
//     push(undoStack, &undoTop, text);
//     next = pop(redoStack, &redoTop);
//     if (next) strcpy(text, next);
//     else text[0] = '\0';
// }

// int main() {
//     int choice;
//     while (1) {
//         printf("\nCurrent Text: \"%s\"\n", text);
//         printf("1. Type Text\n2. Undo\n3. Redo\n4. Exit\n");
//         printf("Enter choice: ");
//         if (scanf("%d", &choice) != 1) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF) {}
//             continue;
//         }
//         switch (choice) {
//             case 1: typeText(); break;
//             case 2: undo(); break;
//             case 3: redo(); break;
//             case 4: printf("Exiting\n"); return 0;
//             default: printf("Invalid choice\n");
//         }
//     }
// }
