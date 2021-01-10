#include <chrono> // TODO don't include in h
#include <vector>
#include <string>
#include "sort.hpp"

using namespace std;

namespace Sort
{
    Base::Base() : averageTime(chrono::nanoseconds(0)),
                   name("undefined") {}

    void Base::sort(vector<int> array)
    {
        auto start = chrono::high_resolution_clock::now();
        auto sorted = sorting(array);
        auto finish = chrono::high_resolution_clock::now();

        for (int i = 0; i < sorted.size() - 1; i++)
        {
            assert(sorted[i] <= sorted[i + 1]);
        }

        if (averageTime.count() == 0) // TODO ternary
        {
            averageTime += finish - start;
        }
        else
        {
            averageTime += finish - start;
            averageTime /= 2;
        }
    }

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
} // namespace Sort
