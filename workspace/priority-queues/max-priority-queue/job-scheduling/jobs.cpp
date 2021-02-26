/*
 * Implement Job Scheduling using Max Priority Queues. 
 * The node of the priority queue will be a class having Job number 
 * and priority. Priority should be the key value. It should be a 
 * menu driven program that provides following options :
 * a. Insert a new job (Input will be job no and priority)
 * b. delete an existing job 
 * c. increase priority of existing job (input- job no and new priority)
 * d. decrease priority of existing job (input- job no and new priority)
 * e. extract job with highest priority.
 */

#include <iostream>
#include <stdexcept>
#include <climits>

class Jobs;

// A node for the jobs priority queue
class JobNode
{
    private:
        int job_number;
        int priority;

        friend class Jobs;

    public:
        JobNode(int job_number = 0, int priority = 0)
            : job_number(job_number), priority(priority) {}
};

// A max priority queue with key as job node priority
class Jobs
{
    private:
        int array_size;    // number of total elements that can be stored in heap
        int heap_size; // number of elements currently present in the heap
        JobNode *heap_array;

        int parent(int index)
        {
            return (index - 1) / 2;
        }

        int search_index(int job_number);

    protected:
        void max_heapify(int i); 
        void heap_increase_key(int index, int new_key);
        void heap_decrease_key(int index, int new_key);
        void max_heap_insert(int job_number, int priority);
        int heap_extract_max();
        int heap_delete(int index);

    public:
        Jobs(int array_size = 10)
        {
            this->heap_size = -1;
            this->array_size = array_size;
            this->heap_array = new JobNode[array_size];
        }

        ~Jobs()
        {
            delete[] heap_array;
        }

        void insert(int job_number, int priority);
        int remove(int job_number);
        void increase_priority(int job_number, int new_priority);
        void decrease_priority(int job_number, int new_priority);
        int extract_max();

        void print();
};

int main()
{
    int size;
    std::cout << "Enter maximum number of jobs = ";
    std::cin >> size;

    Jobs jobs(size);

    while (true)
    {
        std::cout << "\n\nJob Scheduling with Max Priority Queue\n";

        std::cout << "Choose an option:\n"
                    << "1. Insert a new Job\n"
                    << "2. Delete a job\n"
                    << "3. Increase priority\n"
                    << "4. Decrease priority\n"
                    << "5. Extract job with highest priority\n"
                    << "6. Print jobs\n"
                    << "7. Exit\n";

        int choice;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int job_number;
                int priority;
                std::cout << "Job Number: ";
                std::cin >> job_number;
                std::cout << "Priority: ";
                std::cin >> priority;
                try
                {
                    jobs.insert(job_number, priority);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }

                break;
            case 2:
            {
                int job_number;
                std::cout << "Job Number: ";
                std::cin >> job_number;
                try
                {
                    jobs.remove(job_number);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
                break;
            case 3:
            {
                int job_number;
                int new_priority;
                std::cout << "Job Number: ";
                std::cin >> job_number;
                std::cout << "Priority: ";
                std::cin >> new_priority;
                try
                {
                    jobs.increase_priority(job_number, new_priority);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
                break;
            case 4:
            {
                int job_number;
                int new_priority;
                std::cout << "Job Number: ";
                std::cin >> job_number;
                std::cout << "Priority: ";
                std::cin >> new_priority;
                try
                {
                    jobs.decrease_priority(job_number, new_priority);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
                break;
            case 5:
            {
                int max_job_number;
                try
                {
                    max_job_number = jobs.extract_max();
                    std::cout << "Max Priority Job Extract, job number = " << max_job_number << "\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
            }

                break;
            case 6:
                jobs.print();
                break;
            case 7:
                std::cout << "Exiting...";
                std::exit(0);
                break;
            default:

                break;
        }
    }

    return 0;
}

void Jobs::max_heapify(int i)
{
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    int largest = i;
    if (left < heap_size && heap_array[left].priority > heap_array[largest].priority)
        largest = left;
    if (right < heap_size && heap_array[right].priority > heap_array[largest].priority)
        largest = right;

    if (largest != i)
    {
        std::swap(heap_array[i], heap_array[largest]);
        return max_heapify(largest);
    }
}

void Jobs::max_heap_insert(int job_number, int priority)
{
    if (this->heap_size >= this->array_size)
        throw std::runtime_error("Heap Overflow");

    this->heap_size++;
    this->heap_array[this->heap_size] = JobNode(job_number, INT_MIN);
    heap_increase_key(this->heap_size, priority);
}

void Jobs::heap_increase_key(int index, int new_key)
{
    if (new_key < this->heap_array[index].priority)
        throw std::runtime_error("New key is smaller than current key");

    this->heap_array[index].priority = new_key;

    while (index > 0 && this->heap_array[parent(index)].priority < this->heap_array[index].priority)
    {
        std::swap(this->heap_array[index], this->heap_array[parent(index)]);
        index = parent(index);
    }
}

void Jobs::heap_decrease_key(int index, int new_key)
{
    if (new_key > this->heap_array[index].priority)
        throw std::runtime_error("New key is bigger than current key");

    this->heap_array[index].priority = new_key;
    max_heapify(index);
}

int Jobs::heap_extract_max()
{
    if (this->heap_size < 0)
        throw std::runtime_error("Heap underflow");

    unsigned int max_job_number = this->heap_array[0].job_number;
    this->heap_array[0] = this->heap_array[this->heap_size];
    this->heap_size--;
    max_heapify(0);

    return max_job_number;
}

int Jobs::heap_delete(int index)
{
    if (this->heap_size < 0)
        throw std::runtime_error("Heap underflow");

    int job_number = this->heap_array[index].job_number;
    this->heap_array[index] = this->heap_array[this->heap_size];
    this->heap_size--;

    while (index > 0 && this->heap_array[parent(index)].priority < this->heap_array[index].priority)
    {
        std::swap(this->heap_array[index], this->heap_array[parent(index)]);
        index = parent(index);
    }

    max_heapify(index);

    return job_number;
}

void Jobs::print()
{
    std::cout << "Job Number\t\tPriority\n";
    for (int i = 0; i <= this->heap_size; i++)
        std::cout << this->heap_array[i].job_number << "\t\t\t" << this->heap_array[i].priority << "\n";
}

void Jobs::insert(int job_number, int priority)
{
    max_heap_insert(job_number, priority);
}

int Jobs::remove(int job_number)
{
    int index = search_index(job_number);

    if (index == -1)
        throw std::runtime_error("Job not found");
    
    return heap_delete(index);
}

void Jobs::increase_priority(int job_number, int new_priority)
{
    int index = search_index(job_number);

    if (index == -1)
        throw std::runtime_error("Job not found");
    
    heap_increase_key(index, new_priority);
}

void Jobs::decrease_priority(int job_number, int new_priority)
{
    int index = search_index(job_number);

    if (index == -1)
        throw std::runtime_error("Job not found");
    
    heap_decrease_key(index, new_priority);
}

int Jobs::extract_max()
{
    return heap_extract_max();
}

int Jobs::search_index(int job_number)
{
    int index = -1;
    for (int i = 0; i <= this->heap_size; i++)
        if (heap_array[i].job_number == job_number)
        {
            index = i;
            break;
        }

    return index;
}
