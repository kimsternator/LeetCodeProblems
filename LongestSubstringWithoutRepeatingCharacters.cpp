#include "LeetCodeProblems.h"

int lengthOfLongestSubstring(string s) {
    vector<char> substring;
    int maxLength = 0;

    for(int i = 0; i < s.length(); i++) {
        auto it = std::find(substring.begin(), substring.end(), s[i]);

        if(it != substring.end()) {
            if(maxLength < substring.size())
                maxLength = substring.size();
            it++;
            substring.erase(substring.begin(), it);
        }

        substring.push_back(s[i]);
    }

    if(maxLength < substring.size())
        maxLength = substring.size();

    return maxLength;
}

