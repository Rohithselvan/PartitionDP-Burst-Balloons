# Burst Balloons – Interval DP (Recursive, Memoization, Tabulation)

This repository contains three implementations of the Burst Balloons problem (LeetCode 312). It is a well-known interval dynamic programming problem where the goal is to find the best order to burst balloons so that the total number of coins collected is maximized.

The challenge comes from the fact that bursting one balloon immediately changes its neighbors, which makes greedy approaches unreliable. The key idea is to think in reverse: instead of choosing the first balloon to burst, choose the last balloon to burst in a given interval. This naturally leads to a partition-based DP solution.

## 1. Recursive Approach (Exponential, TLE)

This version explores every possible way to pick the last balloon in each interval. The logic is correct, but the number of repeated subproblems grows too quickly. The time complexity is exponential, so this approach will time out on LeetCode.

It is still useful for understanding how the interval splits into left and right subproblems.

File: `recursive.cpp`

## 2. Memoization (Top-Down DP)

This version uses the same recursive structure but stores results of intervals in a dp table. This avoids recomputing the same ranges repeatedly.

Each interval `[i, j]` is solved once, and for every interval we try each possible last balloon. This brings the complexity down to O(n³), which is fast enough to pass all LeetCode test cases.

File: `memoization.cpp`

## 3. Tabulation (Bottom-Up DP)

The tabulation version builds solutions for smaller intervals first and then uses them to solve larger intervals. This removes recursion completely and gives a clean and predictable structure.

The dp definition is simple:  
`dp[i][j]` stores the maximum coins obtainable by bursting all balloons between indices `i` and `j`.

After padding the array with two 1's at the ends, the final answer is `dp[1][n-2]`.

This is the most optimal and most stable approach.

File: `tabulation.cpp`

## How the DP Works

We add a balloon with value 1 at the start and end of the array. For any interval `[i, j]`, we choose a balloon `k` to be the last one burst in that interval. The coins gained from bursting `k` last are:

~~~
nums[i-1] * nums[k] * nums[j+1]
+ dp[i][k-1]
+ dp[k+1][j]
~~~


This recurrence is used in all three approaches; the difference lies only in how the DP is implemented.

## Summary

The recursive version is good for building intuition but not efficient enough.

The memoized version is both clean and performant, suitable for interviews.

The tabulation version is the most optimized and avoids recursion overhead.

This repository shows the progression from a brute-force idea to an efficient dynamic programming solution.

