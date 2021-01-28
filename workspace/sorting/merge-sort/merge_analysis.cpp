#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctime>


int merge_sort(int arr[], int start, int end);
int merge(int arr[], int start, int mid, int end);
void generate_random_array(int random_array[], int length_array);
void merge_best_cases(int num_cases, int min_size, int max_size);
void merge_average_case(int num_cases, int min_size, int max_size);

int main()
{
    merge_best_cases(20, 30, 500);
    merge_average_case(80, 30, 1000);

    return 0;
}


int merge_sort(int arr[], int start, int end)
{
    if (start >= end)
        return 0;

    int mid = (start + end) / 2;
    return (
        merge_sort(arr, start, mid) +
        merge_sort(arr, mid + 1, end) +
        merge(arr, start, mid, end)
    );
}


int merge(int arr[], int start, int mid, int end)
{
    int sizeL = mid - start + 1;
    int sizeR = end - mid;
    int *arrL = new int[sizeL + 1];
    int *arrR = new int[sizeR + 1];

    for (int i = 0; i < sizeL; i++)
    {
        arrL[i] = arr[start + i];
    }

    for (int i = 0; i < sizeR; i++)
    {
        arrR[i] = arr[mid + i + 1];
    }

    arrL[sizeL] = INT_MAX;
    arrR[sizeR] = INT_MAX;
    int num_comparisions = 0;
    for (int i = 0, j = 0, k = start; k <= end; num_comparisions++, k++)
    {
        if (arrL[i] <= arrR[j])
        {
            arr[k] = arrL[i];
            i++;
        }
        else
        {
            arr[k] = arrR[j];
            j++;   
        }
    }

    delete[] arrL;
    delete[] arrR;

    return num_comparisions;
}


void merge_best_cases(int num_cases, int min_size, int max_size)
{
    std::ofstream best_case_file("best-case-merge.csv");

    std::cout << "Best Cases For Merge Sort\n";

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

        long num_comparisions = merge_sort(random_best_case_arr, 0, size - 1);

        std::cout << size << "\t\t\t" << num_comparisions << "\n"; 
        best_case_file << size << "," << num_comparisions << "\n";  // also writes to csv file
    
        delete[] random_best_case_arr;
    }

    best_case_file.close();
}

void merge_average_case(int num_cases, int min_size, int max_size)
{
    std::ofstream average_case_file("average-case-merge.csv");

    std::cout << "Average Cases For Merge Sort\n";

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

        long num_comparisions = merge_sort(random_average_case_arr, 0, size - 1);

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
