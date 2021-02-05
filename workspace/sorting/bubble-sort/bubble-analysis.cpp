#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

int bubble_sort(int arr[], int size);

void bubble_best_cases(int num_cases, int min_size, int max_size);
void bubble_worst_cases(int num_cases, int min_size, int max_size);
void bubble_average_cases(int num_cases, int min_size, int max_size);

void generate_random_array(int arr[], int size);

int main()
{
    bubble_best_cases(20, 30, 500);
    bubble_worst_cases(20, 30, 500);
    bubble_average_cases(60, 30, 1000);

    return 0;
}

void bubble_best_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream best_case_file("bubble-best-case.csv");

    std::cout << "Best case for bubble sort\n";

    int count_cases = 0;
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;  
    std::cout << "size\t\tnumber of comparisions\n";
    best_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_arr = new int[size];

        generate_random_array(random_arr, size);
        std::sort(&random_arr[0], &random_arr[size]);   // sort in increasing order

        int num_comparisions = bubble_sort(random_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        best_case_file << size << "," << num_comparisions << "\n";

        delete[] random_arr;
    }

    best_case_file.close();
}

void bubble_worst_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream worst_case_file("bubble-worst-case.csv");

    std::cout << "Worst case for bubble sort\n";

    int count_cases = 0;
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;
    std::cout << "size\t\tnumber of comparisions\n";
    worst_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_arr = new int[size];

        generate_random_array(random_arr, size);
        std::sort(&random_arr[0], &random_arr[size], [](int a, int b) {return a > b;});

        int num_comparisions = bubble_sort(random_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        worst_case_file << size << "," << num_comparisions << "\n";

        delete[] random_arr;
    }

    worst_case_file.close();
}

void bubble_average_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream average_case_file("bubble-average-case.csv");

    std::cout << "Average case for bubble sort\n";

    int count_cases = 0;
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;
    std::cout << "size\t\tnumber of comparisions\n";
    average_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_arr = new int[size];

        generate_random_array(random_arr, size);

        int num_comparisions = bubble_sort(random_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        average_case_file << size << "," << num_comparisions << "\n";

        delete[] random_arr;
    }

    average_case_file.close();
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

void generate_random_array(int arr[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}
