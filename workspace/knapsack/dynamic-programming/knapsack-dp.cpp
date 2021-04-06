#include <iostream>
#include <vector>

struct item {
    int item_no;
    int weight;
    int profit;
};

int knapsack_dp(int current_index, std::vector<item> &all_items, int knapsack_capacity, std::vector<std::vector<int>> &dp);

int main()
{
    std::vector<item> items;

    std::cout << "Knapsack Problem Using Dynamic Programming Strategy\n";

    bool more_items = true;
    do
    {
        item an_item;
        an_item.item_no = items.size() + 1;
        std::cout << "\nEnter Item " << an_item.item_no << ":\n";
        std::cout << "Enter Item Weight: ";
        std::cin >> an_item.weight;
        std::cout << "Enter Item Profit: ";
        std::cin >> an_item.profit;

        items.push_back(an_item);

        char choice;
        std::cout << "\nWant to add more items?[Y/n]: ";
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y')
            more_items = false;
    } while (more_items);

    int knapsack_capacity;
    std::cout << "\nEnter Knapsack Capacity: ";
    std::cin >> knapsack_capacity;

    std::vector<std::vector<int>> dp(items.size(), std::vector<int>(knapsack_capacity + 1, -1));
    int total_profit = knapsack_dp(0, items, knapsack_capacity, dp);

    std::cout << "Total Profit is " << total_profit << "\n";

    return 0;
}

int knapsack_dp(int current_index, std::vector<item> &all_items, int knapsack_capacity, std::vector<std::vector<int>> &dp)
{
    if (knapsack_capacity <= 0 || current_index >= all_items.size())
        return 0;

    if (dp[current_index][knapsack_capacity] != -1)
    {
        return dp[current_index][knapsack_capacity];
    }

    int profit1 = 0;
    if (all_items[current_index].weight <= knapsack_capacity) {
        profit1 = all_items[current_index].profit + knapsack_dp(current_index + 1,
                                                                all_items, knapsack_capacity - all_items[current_index].weight, dp);
    }

    int profit2 = knapsack_dp(current_index + 1, all_items, knapsack_capacity, dp);

    dp[current_index][knapsack_capacity] = std::max(profit1, profit2);
    return dp[current_index][knapsack_capacity];
}

/*
Knapsack Problem Using Dynamic Programming Strategy

Enter Item 1:
Enter Item Weight: 2
Enter Item Profit: 3

Want to add more items?[Y/n]: y

Enter Item 2:
Enter Item Weight: 3
Enter Item Profit: 4

Want to add more items?[Y/n]: y

Enter Item 3:
Enter Item Weight: 4
Enter Item Profit: 5

Want to add more items?[Y/n]: y

Enter Item 4:
Enter Item Weight: 5
Enter Item Profit: 6

Want to add more items?[Y/n]: n

Enter Knapsack Capacity: 5
Total Profit is 7
*/