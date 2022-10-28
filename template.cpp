#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    vectors<int> ans;
    int Row = matrix.size();
    int Col = matrix[0].size();
    for (int col = 0; col < Col; col++)
    {
        if (col & 1)
        {
            // odd Index -> Bottom to top
            for (int row = 0; row < Row; row++)
            {
                ans.push_back(matrix[row][col]);
            }
        }
        else
        {
            for (int row = Row - 1; row >= 0; row--)
            {
                ans.push_back(matrix[row][col]);
            }
        }
    }
    for (int row = 0; row < 9; row++)
    {
        cout << ans[row];
        cout << endl;
    }

}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << endl
         << "Printing the array after rotation" << endl;

    rotate(matrix);
    // print

    return 0;
}
