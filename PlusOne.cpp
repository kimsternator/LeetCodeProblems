#include "LeetCodeProblems.h"

using namespace std;

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

