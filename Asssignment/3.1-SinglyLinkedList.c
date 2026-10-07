#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int roll)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    return newNode;
}
void display()
{
    struct Node *temp = head;
    printf("Updated List: ");
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}
void insertBeginning(int roll)
{
    struct Node *newNode = createNode(roll);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", roll);
    display();
}
void insertEnd(int roll)
{
    struct Node *newNode = createNode(roll);
    struct Node *temp;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", roll);
    display();
}
void search(int roll)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Roll number %d found.\n", roll);
            return;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found.\n", roll);
}
void deleteNode(int roll)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Roll number %d not found. Cannot delete.\n", roll);
        display();
        return;
    }
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("Roll number %d deleted.\n", roll);
    display();
}

int main()
{
    int n, i, roll, choice;
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter roll numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &roll);
        insertEnd(roll);
    }
    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteNode(roll);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
