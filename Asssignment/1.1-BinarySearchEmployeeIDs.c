#include <stdio.h>
int main() {
    int n, i;
    int emp[100];
    int key;
    int low, high, mid;
    int found = 0;
    int comparisons = 0;
    printf("Enter the number of employee IDs: ");
    scanf("%d", &n);
    printf("Enter %d employee IDs in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &emp[i]);
    }
    printf("Enter the employee ID to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high) {
        comparisons++;
        mid = (low + high) / 2;
        if(emp[mid] == key) {
            found = 1;
            break;
        }
        else if(key < emp[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(found)
        printf("Employee ID found at position %d\n", mid + 1);
    else
        printf("Employee ID not found.\n");

    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}
