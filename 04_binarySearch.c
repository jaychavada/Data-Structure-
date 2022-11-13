// Note:: For binary search array must be sorted....Also we have to maintain low,mid,high....
#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // Start searching (keep searching until low <= high converges)
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Searching Ends
    return -1;
}
int main()
{   // Note:: here this array is sorted....
    int arr[] = {1, 2, 3, 4, 5, 6, 45, 56, 60, 70, 120, 150, 200, 444, 789};
    int size = sizeof(arr) / sizeof(int);
    int element = 5;
    int searchIndex = binarySearch(arr, size, 5);
    printf("The Element %d was found at index %d \n", element, searchIndex);

    return 0;
}