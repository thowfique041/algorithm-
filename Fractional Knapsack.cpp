#include <bits/stdc++.h>

using namespace std;

struct Item {
    int weight;
    int value;
    double valuePerWeight;

};



double fractionalKnapsack(int capacity, vector<Item>& items,vector<pair<int ,float>>&v) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
    return a.valuePerWeight > b.valuePerWeight;
});

    double maxTotalValue = 0.0;
    for (const auto& item : items) {
        if (capacity == 0) {
            break;
        }

        int amountToAdd = min(item.weight, capacity);
        v.push_back(make_pair(item.weight,((float)amountToAdd/item.weight)));
       
        maxTotalValue += amountToAdd * item.valuePerWeight;
        capacity -= amountToAdd;
    }

    return maxTotalValue;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items;
    for (int i = 0; i < numItems; ++i) {
        int weight, value;
        cout << "Enter the weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        float x;
        x=value/weight;
     double valuePerWeight;
     valuePerWeight=x;


        items.push_back({weight, value,valuePerWeight});  
    }
    int knapsackCapacity;
    cout << "Enter the knapsack capacity: ";
    cin >> knapsackCapacity;
    vector<pair<int ,float>>v;

    double maxValue = fractionalKnapsack(knapsackCapacity, items,v);

    cout << "Maximum value in the knapsack: " << maxValue << endl;
    puts("uses value");
    for (const auto & p :  v) {
        cout<<p.second<<"*"<<p.first<<endl;
    }


    return 0;
}
