#include <chrono>
#include <vector>
#include <string>
#include "sort.hpp"

using namespace std;

namespace Sort
{
    Base::Base(string name) : averageTime(chrono::nanoseconds(0)),
                              name(name) {}

    void Base::sort(vector<int> &array)
    {
        auto start = chrono::high_resolution_clock::now();
        auto sorted = sorting(array);
        auto finish = chrono::high_resolution_clock::now();

        // TODO how to strip from release build?
        for (int i = 0; i < sorted.size() - 1; i++)
        {
            assert(sorted[i] <= sorted[i + 1]);
        }

        averageTime = averageTime.count() == 0
                          ? finish - start
                          : (averageTime + finish - start) / 2;
    }

    Bubble::Bubble() : Base("Bubble") {}

    vector<int> Bubble::sorting(vector<int> &array)
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

    Insertion::Insertion() : Base("Insertion") {}

    vector<int> Insertion::sorting(vector<int> &array)
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

    Selection::Selection() : Base("Selection") {}

    vector<int> Selection::sorting(vector<int> &array)
    {
        vector<int> sorted; // TODO nn for copy just swap

        for (int i = 0; i < array.size(); i++)
        {
            int index = 0;
            int minimum = array[index];
            for (int j = 1; j < array.size(); j++)
            {
                int element = array[j];
                if (element < minimum)
                {
                    index = j;
                    minimum = element;
                }
            }
            array.erase(array.begin() + index);
            sorted.push_back(minimum);
        }

        return sorted;
    }
}
