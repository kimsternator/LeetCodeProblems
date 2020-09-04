#include "LeetCodeProblems.h"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> combined = nums1;
    combined.insert(combined.end(), nums2.begin(), nums2.end());
    sort(combined.begin(), combined.end());

    if(combined.size() % 2 != 0) {
        return (double) combined[combined.size()/2];
    }
    else {
        double left = combined[(combined.size()-1) / 2];
        double right = combined[(combined.size()+1) / 2];
        return (left + right) / 2;
    }
    return -1.0;
}

