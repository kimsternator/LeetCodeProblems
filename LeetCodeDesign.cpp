#include "LeetCodeProblems.h"

using namespace std;

//Shuffle an Array
class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
        shuffled = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;

    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < shuffled.size(); i++) {
            int swapIndex = rand() % shuffled.size();
            swap(shuffled[i], shuffled[swapIndex]);
        }

        return shuffled;
    }

private:
    vector<int> original, shuffled;
};

//Min Stack
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(long x) {
        if(s.empty()) {
            s.push(x);
            minVal = x;
        }
        else {
            if(x < minVal) {
                s.push(2*x - minVal);
                minVal = x;
            }
            else
                s.push(x);
        }
    }

    void pop() {
        if(s.empty())
            return;

        if(s.top() < minVal)
            minVal = 2*minVal - s.top();

        s.pop();
    }

    int top() {
        long long val = -1;
        if(s.empty())
            return -1;

        if(s.top() < minVal)
            return minVal;
        else
            return s.top();
    }

    int getMin() {
        if(s.empty())
            return -1;

        return minVal;
    }

private:
    stack<long> s;
    long minVal;
};

