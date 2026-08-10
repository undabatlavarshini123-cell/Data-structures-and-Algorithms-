#include <stdio.h>

int main()
{
    int n, i, key, found = 0;

    printf("What is the array size? ");
    scanf("%d", &n);

    int a[n];

    printf("Start entering array values:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key element: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
        if (a[i] == key)
        {
            found = 1;
            break;
        }

    if (found)
        printf("%d found at location: %d", key, i + 1);
    else
        printf("Value not found");

    return 0;
}