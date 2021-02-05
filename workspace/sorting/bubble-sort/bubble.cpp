#include <iostream>

int bubble_sort(int arr[], int size);

int main()
{
    std::cout << "Bubble Sort\n";

    int size;
    std::cout << "Enter Size: ";
    std::cin >> size;

    int *arr = new int[size];

    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    int num_comparisions = bubble_sort(arr, size);

    std::cout << "Number of comparisions = " << num_comparisions << "\n";
    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr; 

    return 0;
}

int bubble_sort(int arr[], int size)
{
    int num_comparisions = 0;
    bool swapped;
    do
    {
        swapped = false;

        for (int i = 0; i < size - 1; i++)
        {
            if (num_comparisions++, arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        size--;
    } while (swapped);

    return num_comparisions;
}
