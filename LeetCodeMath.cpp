#include "LeetCodeProblems.h"

using namespace std;

//Fizz Buzz
vector<string> fizzBuzz(int n) {
    vector<string> nums;

    for(int i = 1; i <= n; i++) {
        if(i%5 == 0 && i%3 == 0)
            nums.push_back("FizzBuzz");
        else if(i%3 == 0)
            nums.push_back("Fizz");
        else if(i%5 == 0)
            nums.push_back("Buzz");
        else
            nums.push_back(to_string(i));
    }

    return nums;
}

//Count Primes
int countPrimes(int n) {
    vector<bool> primes;
    primes.push_back(true);
    primes.push_back(true);

    for(int i = 2; i < n; i++)
        primes.push_back(true);

    for(int i = 2; i*i < n; i++) {
        if(!primes[i])
            continue;
        for(int j = i*i; j < n; j += i)
            primes[j] = false;
    }

    int count = 0;

    for(int i = 2; i < n; i++)
        if(primes[i])
            count++;

    return count;
}

//Power of Three
bool isPowerOfThree(int n) {
    if(n <= 0){
        return false;
    }

    double ans = log10(n)/log10(3);

    return ceil(ans) == floor(ans);
}

//Roman to Integer
int romanToInt(string s) {
    int num = 0;
    int curr, next;

    unordered_map<char, int> romanMap = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
    };

    for(int i = 0; i < s.length(); i++) {
        curr = romanMap[s[i]];
        next = romanMap[s[i + 1]];

        if(next) {
            if(curr < next) {
                num += next - curr;
                i++;
            }
            else
                num += curr;
        }
        else
            num += curr;
    }

    return num;
}