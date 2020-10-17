#include "LeetCodeProblems.h"

using namespace std;

//Climbing stairs
int climbStairs(int n) {
    if(n == 1)
        return 1;

    vector<int> steps;
    steps.push_back(0);
    steps.push_back(1);
    steps.push_back(2);

    for(int i = 3; i <= n; i++) {
        steps.push_back(steps[i - 1] + steps[i - 2]);
    }

    return steps[n];
}

//Best Time to buy and sell Stock
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int min;

    if(prices.size() == 0 || prices.size() == 1)
        return maxProfit;

    min = prices[0];

    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] < min)
            min = prices[i];
        else if(prices[i] - min > maxProfit)
            maxProfit = prices[i] - min;
    }

    return maxProfit;
}

//Maximum SubArray
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currSum = 0;

    for(auto i = nums.begin(); i != nums.end(); i++) {
        if(currSum < 0)
            currSum = 0;

        currSum += *i;
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

//House Robber
int rob(vector<int>& nums) {
    if(nums.empty())
        return 0;
    if(nums.size() == 1)
        return nums[0];

    vector<int> totals;
    totals.push_back(nums[0]);
    totals.push_back(max(nums[0], nums[1]));

    for(int i = 2; i < nums.size(); i++) {
        totals.push_back(max(totals[i - 2] + nums[i], totals[i - 1]));
    }

    return totals[totals.size() - 1];
}

//Medium
//Jump Game
enum Memo {Good, Bad, Default};

//     bool canJump(vector<int>& nums) {
//         vector<Memo> memo;

//         for(int i = 0; i < nums.size(); i++)
//             memo.push_back(Memo::Default);

//         memo[memo.size() - 1] = Memo::Good;

//         for(int i = nums.size() - 2; i >= 0; i--) {
//             int furthestJump = min(i + nums[i], (int) nums.size() - 1);

//             for(int j = i + 1; j <= furthestJump; j++) {
//                 if(memo[j] == Memo::Good) {
//                     memo[i] = Memo::Good;
//                     break;
//                 }
//             }
//         }

//         return memo[0] == Memo::Good;
//     }

bool canJump(vector<int>& nums) {
    int lastPos = nums.size() - 1;

    for(int i = lastPos; i >= 0; i--)
        if(i + nums[i] >= lastPos)
            lastPos = i;

    return lastPos == 0;
}

//Unique Paths
int uniquePaths(int m, int n) {
    if(m == 0)
        return 0;

    vector< vector<int> > matrix(m, vector<int> (n, 0));

    for(int i = 0; i < m; i++)
        matrix[i][0] = 1;
    for(int j = 0; j < n; j++)
        matrix[0][j] = 1;

    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];

    return matrix[m - 1][n - 1];
}


