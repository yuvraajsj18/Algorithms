#include <iostream>

int heap_sort(int arr[], int size);
int build_max_heap(int arr[], int size);
int max_heapify(int arr[], int size, int i);

int main()
{
    int length;

    std::cout << "Enter length of array: ";
    std::cin >> length;

    int *arr = new int[length];
    
    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];

    long num_comps = heap_sort(arr, length);

    std::cout << "Total number of comparision: " << num_comps << "\n";
    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
    delete[] arr;
    return 0;
}

int heap_sort(int arr[], int size)
{
    int num_comparisions = build_max_heap(arr, size);

    for (int i = size - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        size--;
        num_comparisions += max_heapify(arr, size, 0);
    }
    
    return num_comparisions;
}

int build_max_heap(int arr[], int size)
{
    int num_comparisions = 0;
    for (int i = size / 2; i >= 0; i--)
        num_comparisions += max_heapify(arr, size, i);

    return num_comparisions;
}

int max_heapify(int arr[], int size, int i)
{
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    int largest = i;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        return (max_heapify(arr, size, largest) + 1);
    }

    return 1;
}
