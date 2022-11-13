// Note:: linear search is possible with Array Traversal and it can works for both sorted and unsorted arrays.....

#include <stdio.h>
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 55, 66, 7, 99, 4, 69, 56, 789};
    int size = sizeof(arr) / sizeof(int);
    int element = 44;
    int searchIndex = linearSearch(arr, size, 44);
    printf("The Element %d was found at index %d \n", element, searchIndex);

    return 0;
}