#include <stdio.h>

int main()
{
    int low, high, key, n, found = 0, mid, i;

    printf("Array size: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array values: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter search element: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (key == a[mid])
        {
            found = 1;
            break;
        }
        else if (key < a[mid])
            high = mid - 1;
        else if (key > a[mid])
            low = mid + 1;
    }

    if (found)
        printf("Element found at location %d", mid);
    else
        printf("Not found");

    return 0;
}