#include "LeetCodeProblems.h"

using namespace std;

void moveZeroes(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
    }
    cout << endl;

    int pointer = 0, zeroEndPointer = 0;
    while(pointer < nums.size() - 1 && pointer < nums.size() - zeroEndPointer) {
        if(nums[pointer] == 0) {
            rotate(nums.begin() + pointer, nums.begin() + pointer + 1, nums.end());
            zeroEndPointer++;
            cout << "rotato" << endl;
        }
        else {
            pointer++;
        }

        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << ", ";
        }
        cout << endl;
    }
}
