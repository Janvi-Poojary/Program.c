
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at front
void insert_front()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Insert at rear
void insert_rear()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

// Insert at specific position
void insert_position()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insert_front();
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete from front
void delete_front()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// Delete from rear
void delete_rear()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// Delete from specific position
void delete_position()
{
    struct node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL || pos < 1)
    {
        printf("Invalid position or empty list\n");
        return;
    }

    if (pos == 1)
    {
        delete_front();
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Count nodes
void count()
{
    struct node *temp;
    int c = 0;

    temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    printf("Number of nodes = %d\n", c);
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- LINKED LIST OPERATIONS ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Insert Position\n");
        printf("4. Delete Front\n");
        printf("5. Delete Rear\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Count\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert_front(); break;
            case 2: insert_rear(); break;
            case 3: insert_position(); break;
            case 4: delete_front(); break;
            case 5: delete_rear(); break;
            case 6: delete_position(); break;
            case 7: display(); break;
            case 8: count(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
