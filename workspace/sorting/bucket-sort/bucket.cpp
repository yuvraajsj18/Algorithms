#include <iostream>
#include <deque>

void bucket_sort(float array[], int size);
void insertion_sort(std::deque<float>& array, int length);

int main()
{
    int length;

    std::cout << "Enter length of array: ";
    std::cin >> length;

    float *arr = new float[length];
    
    std::cout << "Enter array separated by spaces: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];

    bucket_sort(arr, length);

    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr;
    return 0;
}

void bucket_sort(float array[], int size)
{
    std::deque <float> *buckets = new std::deque<float>[size];

    for (int i = 0; i < size; i++)
    {
        int index = size * array[i];
        buckets[index].push_back(array[i]);
    }

    for (int i = 0; i < size; i++)
        insertion_sort(buckets[i], buckets[i].size());

    int i = 0;
    int j = 0;
    while (i < size)
    {
        while (!buckets[j].empty())
        {
            array[i] = buckets[j].front();
            buckets[j].pop_front();
            i++;
        }
        j++;
    }
}

void insertion_sort(std::deque<float>& array, int length)
{
    for(int i = 1; i < length; i++)
    {
        float key = array[i];
        
        int j = i - 1;
        while (j >= 0 && array[j] > key) 
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

/*
Enter length of array: 5
Enter array separated by spaces:  0.5 0.4 0.3 0.2 0.1
Sorted array: 0.1 0.2 0.3 0.4 0.5 
*/
