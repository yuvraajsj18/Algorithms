#include <iostream>
#include <cstdlib>
#include <ctime>


int randomized_partition(int arr[], int start, int end);
int partition(int arr[], int start, int end);
int randomized_select(int arr[], int start, int end, int i);

int main()
{
    std::cout << "Randomized Select\n";

    int size;
    std::cout << "Enter Array Size: ";
    std::cin >> size;

    int *arr = new int[size];

    std::cout << "Enter array: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
    
    int i;
    std::cout << "Enter i for ith order statistic: ";
    std::cin >> i;

    if (i > size)
    {
        std::cout << "Invalid i\n";
        return -1;
    }

    int element = randomized_select(arr, 0, size - 1, i);
    std::cout << "ith order statistic = " << element << "\n";

    delete[] arr;
    return 0;
}

int randomized_select(int arr[], int start, int end, int i)
{
    if (start == end)
        return arr[start];

    int pivot_position = randomized_partition(arr, start, end);
    // int k = pivot_position - start + 1;

    if (i - 1 == pivot_position)
        return arr[pivot_position];
    else if (i - 1 < pivot_position)
        return randomized_select(arr, start, pivot_position - 1, i);
    else 
        return randomized_select(arr, pivot_position + 1, end, i);
}

int randomized_partition(int arr[], int start, int end)
{
    srand(time(NULL));

    int random_element = (rand() % (end - start)) + start;
    std::swap(arr[random_element], arr[end]);

    return partition(arr, start, end);
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]);

    return i + 1;
}

/*
    Randomized Select
    Enter Array Size: 9
    Enter array: 26  18  45  61  72  81  19  23  33
    Enter i for ith order statistic: 2
    ith order statistic = 19

    -----------------------------------------------------------------

    Randomized Select
    Enter Array Size: 9
    Enter array: 26  18  45  61  72  81  19  23  33
    Enter i for ith order statistic: 7
    ith order statistic = 61
*/
