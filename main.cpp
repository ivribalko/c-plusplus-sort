#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

vector<int> getUnsortedArray(int count)
{
    vector<int> array;

    for (int i = 0; i < count; i++)
    {
        array.push_back(i);
    }

    for (int i = 0; i < count; i++)
    {
        swap(array[i], array[rand() % count]);
    }

    return array;
}

vector<int> bubbleSort(vector<int> array)
{
    int swappedCountBefore = 0;
    int swappedCountAfter = 0;
    int size = array.size();
    do
    {
        swappedCountAfter = swappedCountBefore;

        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swappedCountAfter++;
            }
        }
    } while (swappedCountBefore != swappedCountAfter);

    return array;
}

int main()
{
    auto unsorted = getUnsortedArray(1000);

    auto start = chrono::high_resolution_clock::now();
    auto sorted = bubbleSort(unsorted);
    auto finish = chrono::high_resolution_clock::now();

    cout << "Bubble sort took: " << (finish - start).count() / 1000 << endl;

    for (int i = 0; i < sorted.size() - 1; i++)
    {
        assert(sorted[i] <= sorted[i + 1]);
    }
}