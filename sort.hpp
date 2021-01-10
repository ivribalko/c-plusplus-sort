#include <chrono> // TODO don't include in h
#include <vector>
#include <string>

namespace Sort
{
    class Base
    {
    public:
        Base();
        std::string name;
        std::chrono::nanoseconds averageTime;
        void sort(std::vector<int> array);

    protected:
        virtual std::vector<int> sorting(std::vector<int> &array) = 0;
    };

    class Bubble : public Base
    {
    protected:
        std::vector<int> sorting(std::vector<int> &array) override;
    };
}; // namespace Sort

// namespace Sort
