#include "LeetCodeProblems.h"

using namespace std;

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
