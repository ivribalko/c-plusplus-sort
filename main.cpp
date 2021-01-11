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
             << (float)(*sorters[i]).averageTime.count() / 1000000
             << endl;
    }
}

int main()
{
    auto sortBubble = Sort::Bubble();
    auto *sortBubblePtr = &sortBubble;

    auto sortSelection = Sort::Selection();
    auto *sortSelectionPtr = &sortSelection;

    auto sortInsertion = Sort::Insertion();
    auto *sortInsertionPtr = &sortInsertion;

    test(vector<Sort::Base *>{
        sortBubblePtr,
        sortSelectionPtr,
        sortInsertionPtr,
    });
}