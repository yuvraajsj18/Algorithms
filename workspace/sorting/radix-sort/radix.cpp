#include <iostream>

int max_arr(int arr[], int size);
void count_sort(int arr[], int size, int place);
void radix_sort(int arr[], int size);

int main()
{
    int length;

    std::cout << "Enter length of array: ";
    std::cin >> length;

    int *arr = new int[length];
    
    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];

    radix_sort(arr, length);

    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr;
    return 0;
}

void count_sort(int arr[], int size, int place)
{
    int *result = new int[size];
    int count_arr[10] = {0};

    for (int i = 0; i < size; i++)
        count_arr[(arr[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count_arr[i] += count_arr[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        result[count_arr[(arr[i] / place) % 10] - 1] = arr[i];
        count_arr[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = result[i];
}

void radix_sort(int arr[], int size)
{
    int max = max_arr(arr, size);

    for (int place = 1; max / place > 0; place *= 10)
        count_sort(arr, size, place);
}

int max_arr(int arr[], int size)
{
    int max_element = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] > max_element)
            max_element = arr[i];
    
    return max_element;
}

/*

Enter length of array: 5
Enter array separated by spaces: 5 4 3 2 1
Sorted array: 1 2 3 4 5 

*/