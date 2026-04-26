#include <iostream>
using namespace std;
template <typename T>
T add(T a, T b)
{
    return a + b;
}
template <typename T>
T subtract(T a, T b)
{
    return a - b;
}
template <typename T>
class Calculator
{
public:
    T add(T a, T b)
    {
        return a + b;
    }
    T subtract(T a, T b)
    {
        return a - b;
    }
};
int main()
{
    cout << add(5, 7) << endl;
    cout << add(5.3, 7.9) << endl;
    cout << subtract(5.3, 7.9) << endl;
    Calculator<int> intCalculator;
    cout << intCalculator.add(5, 8) << endl;
    cout << intCalculator.subtract(5, 8) << endl;
    Calculator<float> floatCalculator;
    cout << floatCalculator.add(7982.2, 79300.0) << endl;
}