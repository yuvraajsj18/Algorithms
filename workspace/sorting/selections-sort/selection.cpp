#include <iostream>

int selection_sort(int arr[], int size);

int main()
{
    std::cout << "Selection Sort\n";

    int size;
    std::cout << "Enter Size: ";
    std::cin >> size;

    int *arr = new int[size];

    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];

    int num_comparisions = selection_sort(arr, size);

    std::cout << "Number of comparisions = " << num_comparisions << "\n";
    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr; 

    return 0;
}

int selection_sort(int arr[], int size)
{
    int num_comparisions = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < size; j++)
        {
            if (num_comparisions++, arr[j] < arr[smallest])
                smallest = j;
        }

        if (smallest != i)
            std::swap(arr[i], arr[smallest]);
    }

    return num_comparisions;
}
