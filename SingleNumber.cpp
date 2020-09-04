#include "LeetCodeProblems.h"

using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> integers;
    for(int i = 0; i < nums.size(); i++) {
        if(integers[nums[i]] == 0) {
            integers[nums[i]] = 1;
        }
        else
            integers[nums[i]]++;
    }

    for(auto i = integers.begin(); i != integers.end(); i++) {
        if(i->second == 1) {
            return i->first;
        }
    }

    return -1;
}

