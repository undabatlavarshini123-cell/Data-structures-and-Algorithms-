#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char page[50];
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
void insert()
{
    struct node *newnode;
    char name[50];
    printf("Enter page name: ");
    scanf("%s", name);
    newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->page, name);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else
    {
        newnode->prev = current;
        newnode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newnode;
        current->next = newnode;
        current = newnode;
    }
    printf("Page inserted successfully.\n");
}
void forward()
{
    if (current == NULL)
        printf("No pages available.\n");
    else if (current->next == NULL)
        printf("You are already at the last page.\n");
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}
void backward()
{
    if (current == NULL)
        printf("No pages available.\n");
    else if (current->prev == NULL)
        printf("You are already at the first page.\n");
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}
void deletePage()
{
    struct node *temp;
    char name[50];
    printf("Enter page to delete: ");
    scanf("%s", name);
    temp = head;
    while (temp != NULL && strcmp(temp->page, name) != 0)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Page not found.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }
    free(temp);
    printf("Page deleted successfully.\n");
}
void displayForward()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("No pages available.\n");
        return;
    }
    printf("Pages from first to last:\n");
    while (temp != NULL)
    {
        printf("%s", temp->page);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
void displayBackward()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("No pages available.\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("Pages from last to first:\n");
    while (temp != NULL)
    {
        printf("%s", temp->page);
        if (temp->prev != NULL)
            printf(" <-> ");
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Web Page History ---\n");
        printf("1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                deletePage();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
