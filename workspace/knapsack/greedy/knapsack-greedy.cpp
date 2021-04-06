#include <iostream>
#include <vector>
#include <algorithm>

struct item {
    int item_no;
    int weight;
    int profit;
};

std::vector<item> knapsack_greedy(std::vector<item> all_items, int knapsack_capacity);

int main()
{
    std::vector<item> items;

    std::cout << "Knapsack Problem Using Greedy Strategy\n";

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

    std::vector<item> selected_items = knapsack_greedy(items, knapsack_capacity);

    std::cout << "Selected Items Are:\n";
    int total_profit = 0;
    for (item x : selected_items)
    {
        std::cout << "Item " << x.item_no << " with weight " << x.weight << " and profit " << x.profit << "\n";
        total_profit += x.profit;
    }

    std::cout << "Total Profit is " << total_profit << "\n";

    return 0;
}

std::vector<item> knapsack_greedy(std::vector<item> all_items, int knapsack_capacity)
{
    std::sort(all_items.begin(), all_items.end(), [](item a, item b) {return a.profit > b.profit;});

    std::vector<item> selected_items;

    for (item x : all_items) {
        if (x.weight <= knapsack_capacity)
        {
            selected_items.push_back(x);
            knapsack_capacity -= x.weight;
        }
    }

    return selected_items;
}

/*
Knapsack Problem Using Greedy Strategy

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
Selected Items Are:
Item 4 with weight 5 and profit 6
Total Profit is 6
*/
