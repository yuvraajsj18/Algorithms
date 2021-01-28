#include <iostream>
#include <cstdlib>
#include <ctime>

void quick_sort(int arr[], int start, int end, int& comparisions);
int partition(int arr[], int start, int end, int& comparisions);

int main()
{
    std::cout << "Quick Sort\n";

    int length;
    std::cout << "Enter length of array: ";
    std::cin >> length;

    int *arr = new int[length];
    
    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];

    int comparisions = 0;
    quick_sort(arr, 0, length - 1, comparisions);

    std::cout << "Number of comparisions: " << comparisions << "\n";
    std::cout << "Sorted Array: ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}

void quick_sort(int arr[], int start, int end, int& comparisions)
{
    if (start >= end)
        return;

    int pivot_position = partition(arr, start, end, comparisions);
    quick_sort(arr, start, pivot_position - 1, comparisions);
    quick_sort(arr, pivot_position + 1, end, comparisions);
}

int partition(int arr[], int start, int end, int& comparisions)
{
    srand(time(NULL));

    int random_element = (rand() % (end - start)) + start;
    std::swap(arr[random_element], arr[end]);

    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (comparisions++, arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]);

    return i + 1;
}
