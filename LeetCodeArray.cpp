#include "LeetCodeProblems.h"

using namespace std;

//Easy
//Remove Duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    return nums.size();
}

//Best Time to buy and sell stock II
int maxProfit(vector<int>& prices) {
    int minVal = prices[0], maxVal = prices[0], profit = 0, counter = 0;
    int length = (signed int) prices.size() - 1;

    while(counter < length) {
        while(counter < length && prices[counter] >= prices[counter + 1])
            counter++;

        minVal = prices[counter];

        while(counter < length && prices[counter] <= prices[counter + 1])
            counter++;

        maxVal = prices[counter];
        profit += maxVal - minVal;
    }

    return profit;
}

//Rotate Array
void rotate(vector<int>& nums, int k) {
    int newK = k%nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + newK);
    reverse(nums.begin() + newK, nums.end());
}

//Contains Duplicates
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() == 0)
        return false;

    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    for(int i = 0; i < temp.size() - 1; i++) {
        if(temp[i] == temp[i + 1])
            return true;
    }

    return false;
}

//Single Number
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

//Intersection of Two Array II
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> intersection;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int iter1 = 0, iter2 = 0;

    while(iter1 < nums1.size() && iter2 < nums2.size()) {
        if(nums1[iter1] == nums2[iter2]) {
            intersection.push_back(nums1[iter1]);
            iter1++;
            iter2++;
        }
        else {
            if(nums1[iter1] < nums2[iter2])
                iter1++;
            else if(nums1[iter1] > nums2[iter2])
                iter2++;
        }
    }

    return intersection;
}

//Plus One
vector<int> plusOne(vector<int>& digits) {
    digits[digits.size() - 1] += 1;

    if(digits[digits.size() - 1] == 10) {
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 10) {
                if(i == 0) {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
                else {
                    digits[i] = 0;
                    digits[i - 1] += 1;
                }
            }
        }
    }

    return digits;
}

//Move Zeros
void moveZeroes(vector<int>& nums) {
    int pointer = 0, zeroEndPointer = 0;
    while(pointer < nums.size() - 1 && pointer < nums.size() - zeroEndPointer) {
        if(nums[pointer] == 0) {
            rotate(nums.begin() + pointer, nums.begin() + pointer + 1, nums.end());
            zeroEndPointer++;
        }
        else {
            pointer++;
        }
    }
}

//Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                vector<int> solution = {i, j};
                return solution;
            }
        }
    }

    vector<int> solution = {-1, -1};
    return solution;
}

//Valid Sudoku
bool containsDups(vector<char>& rowCol) {
    unordered_map<char, int> dict;

    for (int i = 0; i < rowCol.size(); i++) {
        if (rowCol[i] == '.')
            continue;
        else if (dict[rowCol[i]] == 1)
            return true;
        else
            dict[rowCol[i]] = 1;
    }

    return false;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        if(containsDups(board[i])) {
            cout << "condition1" << endl;
            return false;
        }

        vector<char> column;

        for(int j = 0; j < 9; j++)
            column.push_back(board[j][i]);

        if(containsDups(column)) {
            cout << "condition2" << endl;
            return false;
        }

        column.clear();
    }

    for(int i = 1; i < 8; i+=3) {
        vector<char> square;

        for(int j = 1; j < 8; j+=3) {
            square.push_back(board[i - 1][j - 1]);
            square.push_back(board[i - 1][j]);
            square.push_back(board[i - 1][j + 1]);
            square.push_back(board[i][j - 1]);
            square.push_back(board[i][j]);
            square.push_back(board[i][j + 1]);
            square.push_back(board[i + 1][j - 1]);
            square.push_back(board[i + 1][j]);
            square.push_back(board[i + 1][j + 1]);

            if(containsDups(square))
                return false;

            square.clear();
        }
    }

    return true;
}

//Rotate Image
void rotate(vector<vector<int>>& matrix) {
    int length = matrix.size();
    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][length - j - 1];
            matrix[i][length - j - 1] = temp;
        }
    }
}

//Medium
//3Sum
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector< vector<int> > validSums;

    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = nums.size() - 1;

        while(left < right) {
            int tempSum = nums[i] + nums[left] + nums[right];

            if(tempSum > 0)
                right--;
            else if(tempSum < 0)
                left++;
            else {
                validSums.push_back({nums[i], nums[left], nums[right]});
                left++;

                while(nums[left] == nums[left - 1] && left < right)
                    left++;
            }
        }
    }

    return validSums;
}

//Set Matrix Zeroes
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstCol = false;

    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0)
            firstCol = true;

        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++)
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if(matrix[0][0] == 0)
        for(int j = 1; j < cols; j++)
            matrix[0][j] = 0;

    if(firstCol)
        for(int i = 0; i < rows; i++)
            matrix[i][0] = 0;
}

//Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector< vector<string> > groups;
    unordered_map<string, vector<string>> groupDict;

    for(string s: strs) {
        string temp = s;
        sort(temp.begin(), temp.end());

        groupDict[temp].push_back(s);
    }

    for(auto i = groupDict.begin(); i != groupDict.end(); i++) {
        groups.push_back(i->second);
    }

    return groups;
}

//Increasing Triplet Subsequence
bool increasingTriplet(vector<int>& nums) {
    int num1 = INT_MAX, num2 = INT_MAX;

    for(auto i = nums.begin(); i != nums.end(); i++) {
        if(*i < num1)
            num1 = *i;
        else if(*i > num1 && *i < num2)
            num2 = *i;
        else if(*i > num2)
            return true;
    }

    return false;
}

//


