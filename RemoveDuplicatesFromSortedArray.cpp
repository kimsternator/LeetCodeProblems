#include "LeetCodeProblems.h"

int removeDuplicates(vector<int>& nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
}

