#include <chrono>
#include <iostream>
#include <vector>
#include "sort.hpp"

using namespace std;

vector<int> getUnsortedArray(int size)
{
    srand(time(NULL));

    vector<int> array;

    for (int i = 0; i < size; i++)
    {
        array.push_back(i);
    }

    for (int i = 0; i < size; i++)
    {
        swap(array[i], array[rand() % size]);
    }

    return array;
}

vector<int> insertionSort(vector<int> array)
{
    int size = array.size();

    for (int i = 1; i < size; i++)
    {
        int element = array[i];
        int fromIndex = i;
        int toIndex = i;

        while (toIndex >= 1 && element < array[toIndex - 1])
        {
            toIndex--;
        }

        if (fromIndex != toIndex)
        {
            auto from = array.begin() + fromIndex;
            auto to = array.begin() + toIndex;
            rotate(to, from, from + 1);
        }
    }

    return array;
}

void test(vector<Sort::Base *> sorters)
{
    for (int i = 0; i < 10; i++)
    {
        auto unsorted = getUnsortedArray(1000);

        for (int i = 0; i < sorters.size(); i++)
        {
            (*sorters[i]).sort(unsorted);
        }
    }

    for (int i = 0; i < sorters.size(); i++)
    {
        cout << (*sorters[i]).name
             << " algorithm took: "
             << fixed
             << (float)(*sorters[i]).averageTime.count() / 1000000000
             << endl;
    }
}

int main()
{
    auto sortBubble = Sort::Bubble();
    auto *sortBubblePtr = &sortBubble;

    test(vector<Sort::Base *>{
        sortBubblePtr,
    });
}