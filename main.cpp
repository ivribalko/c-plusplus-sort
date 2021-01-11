#include <chrono>
#include <iostream>
#include <vector>
#include "sort.hpp"

// TODO vector -> array or rename array to vector

using namespace std;

vector<int> getUnsortedArray(int size)
{
    srand(time(NULL));

    vector<int> array(size);

    for (int i = 0; i < size; i++)
    {
        array[i] = i;
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
            auto unsortedCopy = unsorted;
            (*sorters[i]).sort(unsortedCopy);
        }
    }

    for (int i = 0; i < sorters.size(); i++)
    {
        // TODO is double (*sorters[i]) slow?
        cout << (*sorters[i]).name
             << " algorithm took: "
             << fixed
             << (float)(*sorters[i]).averageTime.count() / (1000 * 1000)
             << endl;
    }
}

int main()
{
    // TODO is there a generic way to do it?
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