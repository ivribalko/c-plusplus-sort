#include <chrono>
#include <iostream>
#include <vector>

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

chrono::nanoseconds sort(
    vector<int> &array,
    vector<int> sorting(vector<int> array))
{
    auto start = chrono::high_resolution_clock::now();
    auto sorted = sorting(array);
    auto finish = chrono::high_resolution_clock::now();

    // for (int i = 0; i < sorted.size() - 1; i++)
    // {
    //     assert(sorted[i] <= sorted[i + 1]);
    // }

    return finish - start;
}

void test(vector<int> sorting(vector<int> array), string name)
{
    chrono::nanoseconds elapsed(0);

    for (int i = 0; i < 10; i++)
    {
        auto unsorted = getUnsortedArray(1000);

        elapsed += sort(unsorted, sorting);

        if (i != 0)
        {
            elapsed /= 2;
        }
    }

    cout << name
         << " algorithm took: "
         << fixed
         << (float)elapsed.count() / 1000000000
         << endl;
}

int main()
{
    test(bubbleSort, "bubble sort");
    test(insertionSort, "insertion sort");
}