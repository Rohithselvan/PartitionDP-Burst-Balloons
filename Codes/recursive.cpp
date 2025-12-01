#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int maxCoinsHelper(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;
        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            int coins = nums[j + 1] * nums[ind] * nums[i - 1] + maxCoinsHelper(i, ind - 1, nums) + maxCoinsHelper(ind + 1, j, nums);
            maxi = max(maxi, coins);
        }
        return maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return maxCoinsHelper(1, nums.size() - 2, nums);
    }
};

int main()
{
    int n;
    cout << "Enter number of balloons: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the balloon values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    int result = sol.maxCoins(nums);
    cout << "Maximum coins you can collect: " << result << endl;
    return 0;
}
