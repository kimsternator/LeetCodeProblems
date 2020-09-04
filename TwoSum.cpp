#include "LeetCodeProblems.h"

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            cout << nums[i] << " + " << nums[j] << endl;

            if(nums[i] + nums[j] == target) {
                vector<int> solution = {i, j};
                return solution;
            }
        }
    }

    vector<int> solution = {-1, -1};
    return solution;
}
