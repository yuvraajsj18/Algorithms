#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctime>

long insertion_sort(int array[], int length);
void generate_random_array(int random_array[], int length_array);
void insertion_best_cases(int num_cases, int min_size = 30, int max_size = 500);
void insertion_worst_case(int num_cases, int min_size = 30, int max_size= 500);
void insertion_average_case(int num_cases, int min_size = 30, int max_size = 1000);

int main()
{
    insertion_best_cases(20);
    insertion_worst_case(20);
    insertion_average_case(60);

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

/** Runs insertion sort for n best cases (increasing order) of size min_size to max_size
 *  and prints n vs comparisions.
 *  also generates a .csv file with size, comparisions.
*/
void insertion_best_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream best_case_file("best-case-insertion.csv");

    std::cout << "Best Cases For Insertion Sort\n";

    // intervals to skip for different sizes with 0 at first place.
    // Example - 30 50 70 90 ...
    int interval = (((max_size - min_size) / num_cases) / 10) * 10;   
    
    int count_cases = 0;
    std::cout << "size\t\tnumber of comparisions\n";
    best_case_file << "size, number of comparisions\n";
    for (int size = min_size; count_cases < num_cases; size += interval, count_cases++)
    {
        int *random_best_case_arr = new int[size];
        generate_random_array(random_best_case_arr, size);
        std::sort(&random_best_case_arr[0], &random_best_case_arr[size]);    // best case array is in increasing order

        long num_comparisions = insertion_sort(random_best_case_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        best_case_file << size << "," << num_comparisions << "\n";  // also writes to csv file
    
        delete[] random_best_case_arr;
    }

    best_case_file.close();
}

/** Runs insertion sort for n worst cases (decreasing order) of size min_size to max_size
 *  and prints n vs comparisions.
 *  also generates a .csv file with size, comparisions.
*/
void insertion_worst_case(int num_cases, int min_size, int max_size)
{
    std::ofstream worst_case_file("worst-case-insertion.csv");

    std::cout << "Worst Cases For Insertion Sort\n";

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
        std::sort(&random_worst_case_arr[0], &random_worst_case_arr[size], [](int a, int b) {return a > b;});    // worst case array is in decreasing order

        long num_comparisions = insertion_sort(random_worst_case_arr, size);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        worst_case_file << size << "," << num_comparisions << "\n";  // also writes to csv file
    
        delete[] random_worst_case_arr;
    }

    worst_case_file.close();
}

/** Runs insertion sort for n average cases of size min_size to max_size
 *  and prints n vs comparisions.
 *  also generates a .csv file with size, comparisions.
*/
void insertion_average_case(int num_cases, int min_size, int max_size)
{
    std::ofstream average_case_file("average-case-insertion.csv");

    std::cout << "Average Cases For Insertion Sort\n";

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

        long num_comparisions = insertion_sort(random_average_case_arr, size);

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
