#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctime>

int heap_sort(int arr[], int size);
int build_max_heap(int arr[], int size);
int max_heapify(int arr[], int size, int i);

void generate_random_array(int random_array[], int length_array);
void heap_best_cases(int num_cases, int min_size, int max_size);
void heap_worst_case(int num_cases, int min_size, int max_size);
void heap_average_case(int num_cases, int min_size, int max_size);

int main()
{
    heap_best_cases(20, 30, 500);
    heap_worst_case(20, 30, 500);
    heap_average_case(60, 30, 1000);

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

void heap_best_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream best_case_file("best-case-heap.csv");

    std::cout << "Best Cases For Heap Sort\n";

    int interval = (((max_size - min_size) / num_cases) / 10) * 10;   
    
    int count_cases = 0;
    std::cout << "size\t\tnumber of comparisions\n";
    best_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_best_case_arr = new int[size];
        generate_random_array(random_best_case_arr, size);
        std::sort(&random_best_case_arr[0], &random_best_case_arr[size], [](int a, int b) {return a > b;});   

        int num_comparisions = heap_sort(random_best_case_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        best_case_file << size << "," << num_comparisions << "\n";  
    
        delete[] random_best_case_arr;
    }

    best_case_file.close();
}

void heap_worst_case(int num_cases, int min_size, int max_size)
{
    std::ofstream worst_case_file("worst-case-heap.csv");

    std::cout << "Worst Cases For Heap Sort\n";

    int interval = (((max_size - min_size) / num_cases) / 10) * 10;   
    
    int count_cases = 0;
    std::cout << "size\t\tnumber of comparisions\n";
    worst_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_worst_case_arr = new int[size];
        generate_random_array(random_worst_case_arr, size);
        std::sort(&random_worst_case_arr[0], &random_worst_case_arr[size]);  

        int num_comparisions = heap_sort(random_worst_case_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        worst_case_file << size << "," << num_comparisions << "\n"; 
    
        delete[] random_worst_case_arr;
    }

    worst_case_file.close();
}

void heap_average_case(int num_cases, int min_size, int max_size)
{
    std::ofstream average_case_file("average-case-heap.csv");

    std::cout << "Average Cases For Heap Sort\n";

    int interval = (((max_size - min_size) / num_cases) / 10) * 10;   
    
    int count_cases = 0;
    std::cout << "size\t\tnumber of comparisions\n";
    average_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_average_case_arr = new int[size];
        generate_random_array(random_average_case_arr, size);

        long num_comparisions = heap_sort(random_average_case_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        average_case_file << size << "," << num_comparisions << "\n";  // also writes to csv file
    
        delete[] random_average_case_arr;
    }

    average_case_file.close();
}

void generate_random_array(int random_array[], int length_array)
{
    srand(time(NULL));

    for (int i = 0; i < length_array; i++)
    {
        random_array[i] = rand() % 100;  // 0 - 99
    }
}
