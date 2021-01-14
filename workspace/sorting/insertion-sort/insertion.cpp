// Implement Insertion sort. Program should report the number of comparisons. Upload .cpp file
// Output in the end.

#include <iostream>

long insertion_sort(int array[], int length);

int main()
{
    int length;

    std::cout << "Enter length of array: ";
    std::cin >> length;

    int *arr = new int[length];
    
    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];

    long num_comps = insertion_sort(arr, length);

    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
    std::cout << "Total number of comparision: " << num_comps << "\n";

    delete[] arr;
    return 0;
}

/** Sort an array with insertion sort and return the number of comparistion */
long insertion_sort(int array[], int length)
{
    long num_comparisions = 0;

    for(int i = 1; i < length; i++)
    {
        int key = array[i];
        
        int j = i - 1;
        while (num_comparisions++, j >= 0 && array[j] > key) 
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }

    return num_comparisions;
}


/* OUTPUT
Enter length of array: 5
Enter array separated by spaces: 5 4 3 2 1
Sorted array: 1 2 3 4 5 
Total number of comparision: 14
*/