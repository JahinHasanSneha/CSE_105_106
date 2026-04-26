#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;
void dfs(vector<vector<int>> &image, int i, int j, int newColor, int orgColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != orgColor || image[i][j] == newColor)
    {
        return;
    }
    image[i][j] = newColor;
    dfs(image, i - 1, j, newColor, orgColor);
    dfs(image, i + 1, j, newColor, orgColor);
    dfs(image, i, j - 1, newColor, orgColor);
    dfs(image, i, j + 1, newColor, orgColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
}
void printImage(const vector<vector<int>> &image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    // Example image (2D vector)
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1;       // starting row
    int sc = 1;       // starting column
    int newColor = 2; // color to fill

    cout << "Original Image:" << endl;
    printImage(image);

    // Call floodFill
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "\nImage after Flood Fill:" << endl;
    printImage(result);

    return 0;
}