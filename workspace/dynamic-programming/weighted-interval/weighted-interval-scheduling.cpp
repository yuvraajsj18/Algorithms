#include <iostream>
#include <algorithm>
#include <vector>

struct interval
{
    int interval_number;
    int start_time;
    int finish_time;
    int value;
};

int weighted_interval_scheduling(std::vector<interval> intervals, std::vector<interval>& selected_intervals);
std::vector<int> find_left_non_overlapping_intervals(std::vector<interval> intervals);
void forward_interval_scheduling(std::vector<interval> intervals, std::vector<int> p ,std::vector<int>& M);
void backtrack_for_solution_intervals(std::vector<interval> intervals, std::vector<interval>& selected_intervals, std::vector<int> M, std::vector<int> p, int interval_index);

int main()
{
    std::cout << "Weighted Interval Scheduling Using Dynamic Programming Strategy\n";

    std::vector<interval> intervals;
    std::cout << "Enter Intervals\n";

    bool more_intervals = true;
    do
    {
        interval an_interval;
        an_interval.interval_number = intervals.size() + 1;
        std::cout << "\nInterval " << an_interval.interval_number << ":\n";
        std::cout << "Enter start time: ";
        std::cin >> an_interval.start_time;
        std::cout << "Enter finish time: ";
        std::cin >> an_interval.finish_time;
        std::cout << "Enter value: ";
        std::cin >> an_interval.value;

        intervals.push_back(an_interval);

        char choice;
        std::cout << "\nWant to add more intervals: ";
        std::cin >> choice;
        more_intervals = (choice != 'y' && choice != 'Y') ? false : true;
    } while (more_intervals);
    
    std::vector<interval> selected_intervals;
    int total_value = weighted_interval_scheduling(intervals, selected_intervals);

    std::cout << "Total value is " << total_value << "\n";

    std::cout << "Selected intervals are:\n";
    for (interval x : selected_intervals)
        std::cout << "Interval " << x.interval_number << " from " << x.start_time << " to " << x.finish_time << "\n";

    return 0;
}

int weighted_interval_scheduling(std::vector<interval> intervals, std::vector<interval>& selected_intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](interval a, interval b) {return a.finish_time < b.finish_time;});

    std::vector<int> M(intervals.size(), 0);

    std::vector<int> left_non_overlapping_intervals = find_left_non_overlapping_intervals(intervals);

    forward_interval_scheduling(intervals, left_non_overlapping_intervals, M);
    backtrack_for_solution_intervals(intervals, selected_intervals, M, left_non_overlapping_intervals, intervals.size() - 1);

    int total_value = 0;
    for (interval x : selected_intervals)
        total_value += x.value;

    return total_value;
}

std::vector<int> find_left_non_overlapping_intervals(std::vector<interval> intervals)
{
    std::vector<int> left_non_overlapping_intervals(intervals.size(), -1);
    for (int i = 0; i < intervals.size(); i++)
    {
        int j = i - 1;
        for (; j >= 0 && intervals[i].start_time < intervals[j].finish_time; j--);
        
        left_non_overlapping_intervals[i] = j;
    }

    return left_non_overlapping_intervals;
}

void forward_interval_scheduling(std::vector<interval> intervals, std::vector<int> p ,std::vector<int>& M)
{
    M[0] = 0;

    for (int j = 1; j < intervals.size(); j++)
        M[j] = std::max(intervals[j].value + M[p[j]], M[j - 1]);
}

void backtrack_for_solution_intervals(std::vector<interval> intervals, std::vector<interval>& selected_intervals, std::vector<int> M, std::vector<int> p, int interval_index)
{
    if (interval_index < 0)
        return;

    if (intervals[interval_index].value + M[p[interval_index]] >= M[interval_index - 1])
    {
        selected_intervals.push_back(intervals[interval_index]);
        backtrack_for_solution_intervals(intervals, selected_intervals, M, p, p[interval_index]);
    }
    else
    {
        backtrack_for_solution_intervals(intervals, selected_intervals, M, p, interval_index - 1);
    }
}

/*
Weighted Interval Scheduling Using Dynamic Programming Strategy
Enter Intervals

Interval 1:
Enter start time: 0
Enter finish time: 6
Enter value: 10

Want to add more intervals: y

Interval 2:
Enter start time: 3
Enter finish time: 10
Enter value: 20

Want to add more intervals: y

Interval 3:
Enter start time: 7
Enter finish time: 11
Enter value: 5

Want to add more intervals: y

Interval 4:
Enter start time: 9
Enter finish time: 16
Enter value: 20

Want to add more intervals: y

Interval 5:
Enter start time: 13
Enter finish time: 20
Enter value: 15

Want to add more intervals: n
Total value is 35
Selected intervals are:
Interval 5 from 13 to 20
Interval 2 from 3 to 10

--------------------------------------------------------------

Weighted Interval Scheduling Using Dynamic Programming Strategy
Enter Intervals

Interval 1:
Enter start time: 3
Enter finish time: 10
Enter value: 20

Want to add more intervals: y

Interval 2:
Enter start time: 1
Enter finish time: 2
Enter value: 50

Want to add more intervals: y

Interval 3:
Enter start time: 6
Enter finish time: 19
Enter value: 100

Want to add more intervals: y

Interval 4:
Enter start time: 2
Enter finish time: 100
Enter value: 200

Want to add more intervals: n
Total value is 250
Selected intervals are:
Interval 4 from 2 to 100
Interval 2 from 1 to 2
*/