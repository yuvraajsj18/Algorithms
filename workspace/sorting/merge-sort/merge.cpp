#include <iostream>
#include <climits>

int merge_sort(int arr[], int start, int end);
int merge(int arr[], int start, int mid, int end);

int main()
{
    std::cout << "Merge Sort\n";

    int length;
    std::cout << "Enter length of array: ";
    std::cin >> length;

    int *arr = new int[length];
    
    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];

    int num_comps = merge_sort(arr, 0, length - 1);

    std::cout << "Number of comparisions = " << num_comps << "\n";
    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

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
