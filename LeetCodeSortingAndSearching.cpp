#include "LeetCodeProblems.h"

using namespace std;

//Merge Sorted Array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;

    while(i < m && j < n) {
        if(nums1[i] < nums2[j]) {
            nums1.push_back(nums1[i]);
            i++;
        }
        else {
            nums1.push_back(nums2[j]);
            j++;
        }
    }

    while(j < n) {
        nums1.push_back(nums2[j]);
        j++;
    }

    while(i < m) {
        nums1.push_back(nums1[i]);
        i++;
    }

    nums1.erase(nums1.begin(), nums1.begin() + m + n);
}

//First Bad Version
int firstBadVersion(int n) {
    int left = 0, right = n;

    while(left < right) {
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

//Medium
//Sort Colors
void sortColors(vector<int>& nums) {
    int red = nums.size(), white = nums.size(), blue = nums.size();
    int origSize = nums.size();

    for(int i = 0; i < origSize; i++) {
        if(nums[i] == 0) {
            nums.insert(nums.begin() + red, 0);
            red++; white++; blue++;
        }
        else if(nums[i] == 1) {
            nums.insert(nums.begin() + white, 1);
            white++; blue++;
        }
        else if(nums[i] == 2) {
            nums.insert(nums.begin() + blue, 2);
            blue++;
        }
    }

    nums.erase(nums.begin(), nums.begin() + origSize);
}

//Top K Frequent elements
class compareFreq {
public:
    bool operator() (pair<int, int> one, pair<int, int> two) {
        if(one.second == two.second)
            return one.first < two.first;

        return one.second < two.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreq;
        priority_queue< pair<int, int>, vector< pair<int, int> >, compareFreq> pairs;
        vector<int> kFreq;

        for(int i = 0; i < nums.size(); i++)
            numFreq[nums[i]] += 1;

        for(auto i = numFreq.begin(); i != numFreq.end(); i++)
            pairs.push(make_pair(i->first, i->second));

        for(int i = 0; i < k; i++) {
            kFreq.push_back(pairs.top().first);
            pairs.pop();
        }

        return kFreq;
    }
};

//Kth Largest Element in an Array
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>> sortedNums;

    for(int i = 0; i < nums.size(); i++)
        sortedNums.push(nums[i]);

    for(int i = 1; i < k; i++)
        sortedNums.pop();

    return sortedNums.top();
}

//Find Peak Element
int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while(l < r) {
        int mid = (l + r) / 2;

        if(nums[mid] > nums[mid + 1])
            r = mid;
        else l = mid + 1;
    }

    return l;
}

//Search for a Range
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> sol;
    auto lower = lower_bound(nums.begin(), nums.end(), target);
    auto upper = upper_bound(nums.begin(), nums.end(), target);
    int lower_int = lower - nums.begin();
    int upper_int = upper - nums.begin() - 1;

    if(upper - lower != 0) {
        sol.push_back(lower_int);
        sol.push_back(upper_int);
    }
    else {
        sol.push_back(-1);
        sol.push_back(-1);
    }

    return sol;
}

//Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty())
        return intervals;

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        if(merged.back()[1] >= intervals[i][0]) {
            if (merged.back()[1] <= intervals[i][1]) {
                int x = merged.back()[0];
                merged.pop_back();
                merged.push_back({x, intervals[i][1]});
            }
        }
        else
            merged.push_back(intervals[i]);
    }

    return merged;
}

//Search in Rotated Sorted Array
int search(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;
    else if(nums.size() == 1) {
        if(nums[0] == target)
            return 0;
    }

    int back = nums.back();

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target)
            return i;
        else {
            if(nums[i] > target && target > back)
                return -1;
        }
    }

    return -1;
}

//Search a 2D Matrix II
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();

    if(rows == 0)
        return false;

    int cols = matrix[0].size();

    if(cols == 0)
        return false;

    int i = 0, j = cols - 1;

    while(i < rows && j >= 0) {
        if( target > matrix[i][j] )
            i++;
        else if ( target < matrix[i][j] )
            j--;
        else
            return true;
    }

    return false;
}
