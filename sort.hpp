#include <chrono>
#include <vector>
#include <string>

namespace Sort
{
    class Base
    {
    public:
        Base(std::string name);
        std::string name;
        std::chrono::nanoseconds averageTime;
        void sort(std::vector<int> array);

    protected:
        virtual std::vector<int> sorting(std::vector<int> &array) = 0;
    };

    class Bubble : public Base
    {
    public:
        Bubble();

    protected:
        std::vector<int> sorting(std::vector<int> &array) override;
    };

    class Insertion : public Base
    {
    public:
        Insertion();

    protected:
        std::vector<int> sorting(std::vector<int> &array) override;
    };

    class Selection : public Base
    {
    public:
        Selection();

    protected:
        std::vector<int> sorting(std::vector<int> &array) override;
    };
};