#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

int selection_sort(int arr[], int size);

void selection_best_cases(int num_cases, int min_size, int max_size);
void selection_worst_cases(int num_cases, int min_size, int max_size);
void selection_average_cases(int num_cases, int min_size, int max_size);

void generate_random_array(int arr[], int size);

int main()
{
    selection_best_cases(20, 30, 500);
    selection_worst_cases(20, 30, 500);
    selection_average_cases(60, 30, 1000);

    return 0;
}

void selection_best_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream best_case_file("selection-best-case.csv");

    std::cout << "Best case for selection sort\n";

    int count_cases = 0;
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;  
    std::cout << "size\t\tnumber of comparisions\n";
    best_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_arr = new int[size];

        generate_random_array(random_arr, size);
        std::sort(&random_arr[0], &random_arr[size]);   // sort in increasing order

        int num_comparisions = selection_sort(random_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        best_case_file << size << "," << num_comparisions << "\n";

        delete[] random_arr;
    }

    best_case_file.close();
}

void selection_worst_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream worst_case_file("selection-worst-case.csv");

    std::cout << "Worst case for selection sort\n";

    int count_cases = 0;
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;
    std::cout << "size\t\tnumber of comparisions\n";
    worst_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_arr = new int[size];

        generate_random_array(random_arr, size);
        std::sort(&random_arr[0], &random_arr[size], [](int a, int b) {return a > b;});

        int num_comparisions = selection_sort(random_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        worst_case_file << size << "," << num_comparisions << "\n";

        delete[] random_arr;
    }

    worst_case_file.close();
}

void selection_average_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream average_case_file("selection-average-case.csv");

    std::cout << "Average case for selection sort\n";

    int count_cases = 0;
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;
    std::cout << "size\t\tnumber of comparisions\n";
    average_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_arr = new int[size];

        generate_random_array(random_arr, size);

        int num_comparisions = selection_sort(random_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        average_case_file << size << "," << num_comparisions << "\n";

        delete[] random_arr;
    }

    average_case_file.close();
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

void generate_random_array(int arr[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}
