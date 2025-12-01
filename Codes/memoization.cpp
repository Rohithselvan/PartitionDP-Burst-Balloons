#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            int coins = nums[i - 1] * nums[ind] * nums[j + 1] + maxCoinsHelper(i, ind - 1, nums, dp) + maxCoinsHelper(ind + 1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return maxCoinsHelper(1, n - 2, nums, dp);
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
