#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <ctime>

void randomised_quick_sort(int arr[], int start, int end, int& comparisions);
void simple_quick_sort(int arr[], int start, int end, int& comparisions);
int randomised_partition(int arr[], int start, int end, int& comparisions);
int partition(int arr[], int start, int end, int& comparisions);

void quick_worst_cases(int num_cases, int min_size, int max_size);
void quick_average_cases(int num_cases, int min_size, int max_size);
void generate_random_array(int random_array[], int length_array);

int main()
{
    quick_worst_cases(20, 30, 500);
    quick_average_cases(80, 30, 1000);

    return 0;
}

void quick_worst_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream worst_case_file("worst-case-merge.csv");

    std::cout << "Worst Case For Quick Sort\n";
    // intervals to skip for different sizes with 0 at first place.
    // Example - 30 50 70 90 ...
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;   
    
    int count_cases = 0;
    std::cout << "size\t\tnumber of comparisions\n";
    worst_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_worst_case_arr = new int[size];
        generate_random_array(random_worst_case_arr, size);
        std::sort(&random_worst_case_arr[0], &random_worst_case_arr[size]);   

        int num_comparisions = 0;
        simple_quick_sort(random_worst_case_arr, 0, size - 1, num_comparisions);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        worst_case_file << size << "," << num_comparisions << "\n";  // also writes to csv file
    
        delete[] random_worst_case_arr;
    }

    worst_case_file.close();
}

void quick_average_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream average_case_file("average-case-merge.csv");

    std::cout << "Worst Case For Quick Sort\n";
    // intervals to skip for different sizes with 0 at first place.
    // Example - 30 50 70 90 ...
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;   
    
    int count_cases = 0;
    std::cout << "size\t\tnumber of comparisions\n";
    average_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_average_case_arr = new int[size];
        generate_random_array(random_average_case_arr, size);  

        int num_comparisions = 0;
        randomised_quick_sort(random_average_case_arr, 0, size - 1, num_comparisions);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        average_case_file << size << "," << num_comparisions << "\n";  // also writes to csv file
    
        delete[] random_average_case_arr;
    }

    average_case_file.close();
}

void randomised_quick_sort(int arr[], int start, int end, int& comparisions)
{
    if (start >= end)
        return;

    int pivot_position = randomised_partition(arr, start, end, comparisions);
    randomised_quick_sort(arr, start, pivot_position - 1, comparisions);
    randomised_quick_sort(arr, pivot_position + 1, end, comparisions);
}

void simple_quick_sort(int arr[], int start, int end, int& comparisions)
{
    if (start >= end)
        return;

    int pivot_position = partition(arr, start, end, comparisions);
    simple_quick_sort(arr, start, pivot_position - 1, comparisions);
    simple_quick_sort(arr, pivot_position + 1, end, comparisions);
}

int randomised_partition(int arr[], int start, int end, int& comparisions)
{
    srand(time(NULL));

    int random_element = (rand() % (end - start)) + start;
    std::swap(arr[random_element], arr[end]);

    return partition(arr, start, end, comparisions);
}

int partition(int arr[], int start, int end, int& comparisions)
{
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

void generate_random_array(int random_array[], int length_array)
{
    srand(time(NULL));

    for (int i = 0; i < length_array; i++)
    {
        random_array[i] = rand() % 100;  // 0 - 99
    }
}
