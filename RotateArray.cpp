#include "LeetCodeProblems.h"

void rotate(vector<int>& nums, int k) {
    int newK = k%nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + newK);
    reverse(nums.begin() + newK, nums.end());
}