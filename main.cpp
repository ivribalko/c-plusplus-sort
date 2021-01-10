#include <iostream>
#include <vector>

using namespace std;

vector<int> getRandomNumbers(int count)
{
    vector<int> numbers;

    for (int i = 0; i < count; i++)
    {
        numbers.push_back(i);
    }

    for (int i = 0; i < count; i++)
    {
        swap(numbers[i], numbers[rand() % count]);
    }

    return numbers;
}

int main()
{
    vector<int> numbers = getRandomNumbers(1000);
}