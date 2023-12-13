#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> findPowerSet(vector<int> &nums)
{
    int bits = nums.size();

    // Sort to avoid adding permutation of the substring
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    // To store subset as a list to avoid adding exact duplicates
    vector<string> list;

    // subset_num 000..0 to 111..1
    for (int subset_num = 0; subset_num < (1<<bits); subset_num++)
    {
        vector<int> subset;
        string temp = "";

        // Check for the current bit in the subset_num
        for (int j = 0; j < bits; j++)
        {
            if (subset_num & (1 << j))
            {
                subset.push_back(nums[j]);
                temp += to_string(nums[j]);
            }
        }

        if (find(list.begin(), list.end(), temp) == list.end())
        {
            ans.push_back(subset);
            list.push_back(temp);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr{10, 12, 12};

    vector<vector<int>> power_set = findPowerSet(arr);

    for (int i = 0; i < power_set.size(); i++)
    {
        for (int j = 0; j < power_set[i].size(); j++)
            cout << power_set[i][j] << " ";
        cout << endl;
    }
    return 0;
}