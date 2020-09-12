#include "LeetCodeProblems.h"

using namespace std;

//Number of 1 Bits
int hammingWeight(uint32_t n) {
    unsigned int mask = 0x01;
    unsigned int count = 0;

    for(int i = 0; i < 32; i++) {
        if(n & mask)
            count++;

        n = n >> 1;
    }

    return count;
}

//hammering Distance
int hammingDistance(int x, int y) {
    int count = 0;
    int mask = 1;
    int z = x^y;

    for(int i = 0; z; i++) {
        if(z & mask)
            count++;

        z = z >> 1;
    }

    return count;
}

//Reverse Bits
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0, power = 31;

    while(n) {
        ans += (n & 1) << power;
        n = n >> 1;
        power--;
    }

    return ans;
}

//Pascal's Triangle
vector<vector<int>> generate(int numRows) {
    vector< vector<int> > triangle;
    if(numRows <= 0)
        return triangle;

    triangle.push_back({1});
    if(numRows == 1)
        return triangle;

    triangle.push_back({1, 1});
    if(numRows == 2)
        return triangle;

    for(int i = 2; i < numRows; i++) {
        int left, right;
        vector<int> row = {1};

        for(int j = 0; j < i; j++) {
            if(j != i - 1) {
                left = triangle[i - 1][j];
                right = triangle[i - 1][j + 1];
                row.push_back(left + right);
            }
            else
                row.push_back(1);
        }

        triangle.push_back(row);
    }

    return triangle;
}

//Valid Parentheses
unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

bool isValid(string s) {
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
            continue;
        }

        if(st.empty())
            return false;

        if(pairs[s[i]] == st.top())
            st.pop();
        else
            return false;
    }

    if(st.empty())
        return true;

    return false;
}

//Missing Number
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    if(nums[nums.size() - 1] != nums.size())
        return nums.size();

    if(nums[0] != 0)
        return 0;

    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] + 1 != nums[i + 1])
            return nums[i] + 1;
    }

    return -1;
}