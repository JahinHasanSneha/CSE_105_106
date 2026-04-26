#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<double>> points = {{-1, -2}, {0, 0}, {1, 2}, {2, 3}};

    double res = minDistance(points);

    // Output the result with 6 decimal places
    cout << fixed << setprecision(6) << res << endl;

    return 0;
}