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
