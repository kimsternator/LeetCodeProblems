#include "LeetCodeProblems.h"

int reverse(int x) {
    int sol = 0;

    while(x != 0) {
        int pop = x % 10;
        x /= 10;

        if(sol > INT_MAX / 10 || (sol == INT_MAX / 10 && pop > 7))
            return 0;
        if(sol < INT_MIN / 10 || (sol == INT_MIN / 10 && pop < -8))
            return 0;

        sol = sol * 10 + pop;
    }

    return sol;
}

