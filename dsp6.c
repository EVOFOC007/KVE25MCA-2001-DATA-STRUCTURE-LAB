#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *end = NULL;
int size = 0;

/* Insert at beginning */
void insert_head(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;
    else
        end = newnode;

    head = newnode;
    size++;
}

/* Insert at end */
void insert_end(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = end;

    if (end != NULL)
        end->next = newnode;
    else
        head = newnode;

    end = newnode;
    size++;
}

/* Insert at specific position */
void insert_pos(int data, int pos) {
    int count = 1;
    struct node *temp = head;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    while (count < pos && temp != NULL) {
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;
    else
        end = newnode;

    temp->next = newnode;
    size++;
}

/* Delete from beginning */
void delete_head() {
    if (head == NULL) {
        printf("\nLinked list is empty");
        return;
    }

    struct node *temp = head;
    printf("\nNode deleted: %d", temp->data);

    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        end = NULL;

    free(temp);
    size--;
}

/* Delete from end */
void delete_end() {
    if (end == NULL) {
        printf("\nLinked list is empty");
        return;
    }

    struct node *temp = end;
    printf("\nNode deleted: %d", temp->data);

    end = end->prev;

    if (end != NULL)
        end->next = NULL;
    else
        head = NULL;

    free(temp);
    size--;
}

/* Delete from specific position (FIXED) */
void delete_pos(int pos) {
    int count = 1;
    struct node *temp = head;

    if (pos == 1) {
        delete_head();
        return;
    }

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("\nInvalid position");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        end = temp->prev;

    printf("\nNode deleted: %d", temp->data);
    free(temp);
    size--;
}

/* Display forward */
void display_forward() {
    if (head == NULL) {
        printf("\nLinked list is empty");
        return;
    }

    struct node *temp = head;
    printf("\nList (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Display reverse */
void display_reverse() {
    if (end == NULL) {
        printf("\nLinked list is empty");
        return;
    }

    struct node *temp = end;
    printf("\nList (Reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

/* Search element */
void search() {
    if (head == NULL) {
        printf("\nLinked list is empty");
        return;
    }

    int key, pos = 1;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nElement %d found at position %d", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("\nElement not found");
}

/* Main function */
int main() {
    int ch, data, pos;
    
    do {
        printf("\nchoose");
        printf("\n1.Insert Head");
        printf("\n2.Insert End");
        printf("\n3.Insert Position");
        printf("\n4.Delete Head");
        printf("\n5.Delete End");
        printf("\n6.Delete Position");
        printf("\n7.Display Forward");
        printf("\n8.Display Reverse");
        printf("\n9.Search");
        printf("\n10.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to Store: ");
                scanf("%d", &data);
                insert_head(data);
                break;

            case 2:
                printf("Enter data to Store: ");
                scanf("%d", &data);
                insert_end(data);
                break;

            case 3:
                printf("Enter data to Store: ");
                scanf("%d", &data);
                printf("Enter position where you need to store (Head = 0 to End = %d): ", size);
                scanf("%d", &pos);

                if (pos < 0 || pos > size)
                    printf("\nInvalid position");
                else if (pos == 0)
                    insert_head(data);
                else if (pos == size)
                    insert_end(data);
                else
                    insert_pos(data, pos);
                break;

            case 4:
                delete_head();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter position where you need to delete(Head = 0 to End = %d): ", size);
                scanf("%d", &pos);

                if (pos < 1 || pos > size)
                    printf("\nInvalid position");
                else if (pos == size)
                    delete_end();
                else
                    delete_pos(pos);
                break;

            case 7:
                display_forward();
                break;

            case 8:
                display_reverse();
                break;

            case 9:
                search();
                break;

            case 10:
                printf("\nProgram exited successfully");
                break;

            default:
                printf("\nInvalid choice");
        }

    } while (ch != 10);

    return 0;
}
