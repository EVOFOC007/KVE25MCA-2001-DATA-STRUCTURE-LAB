//stack operation using array
#include <stdio.h>

int stack[100], choice, n, top = -1, x, i;

/* Function declarations */
void push(void);
void pop(void);
void display(void);

int main()
{
    printf("\n\t Enter the Size of Stack: ");
    scanf("%d", &n);

    printf("______________________________________________________________\n");
    printf("|________________STACK_OPERATIONS_USING_ARRAY________________|\n");
    printf("|______________________________________________________________|\n");
    printf("|_____________1.PUSH___2.POP___3.DISPLAY___4.EXIT______________|\n");
    printf("|______________________________________________________________|\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n\t EXIT POINT\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

/* Push Operation */
void push(void)
{
    if (top >= n - 1)
        printf("Stack is FULL\n");
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

/* Pop Operation */
void pop(void)
{
    if (top == -1)
        printf("Stack is EMPTY\n");
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

/* Display Operation */
void display(void)
{
    if (top >= 0)
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
    else
        printf("Stack is EMPTY\n");
}
