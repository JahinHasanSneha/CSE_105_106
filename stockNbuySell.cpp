#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &price)
{
    int n = price.size();
    int maxPro = 0;
    int bestBuy = price[0];
    for (int i = 0; i < n; i++)
    {
        maxPro = max(maxPro, price[i] - bestBuy);
        if (price[i] < bestBuy)
        {
            bestBuy = price[i];
        }
    }
    return maxPro;
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4}; // Static input

    int profit = maxProfit(price);

    cout << "Maximum Profit = " << profit << endl;

    return 0;
}