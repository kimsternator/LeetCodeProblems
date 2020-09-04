#include "LeetCodeProblems.h"

int paliLength(int left, int right, string s) {
    int len = 0;

    while(left >= 0 & right < s.size()) {
        if(s[left] == s[right]) {
            len = right - left + 1;
            left--;
            right++;
        }
        else {
            break;
        }
    }

    return len;
}

string longestPalindrome(string s) {
    int start = 0, end = 0;

    if(s.size() == 0) {
        return "";
    }
    else {
        for(int center = 0; center < s.size(); center++) {
            int len1 = paliLength(center, center, s);
            int len2 = paliLength(center, center + 1, s);

            if(len1 > (end-start)) {
                start = center - (len1 / 2);
                end = center + (len1 / 2);
            }

            if(len2 > (end-start)) {
                start = center + 1 - (len2 / 2);
                end = center + (len2 / 2);
            }
        }
    }

    return s.substr(start, end - start + 1);
}

