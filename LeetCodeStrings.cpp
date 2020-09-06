#include "LeetCodeProblems.h"

using namespace std;

//Reverse String
void reverseString(vector<char>& s) {
    int len = s.size();

    for(int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

//Reverse Integer
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

//First Unique Character in a String
int firstUniqChar(string s) {
    unordered_map<char,int> chars;

    for(int i = 0; i < s.size(); i++) {
        if(chars[s[i]] == 0)
            chars[s[i]] = 1;
        else
            chars[s[i]] += 1;
    }

    for(int i = 0; i < s.size(); i++) {
        if(chars[s[i]] == 1)
            return i;
    }

    return -1;
}

//Valid Anagram
bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s == t)
        return true;

    return false;
}

//Valid Palindrome
bool isPalindrome(string s) {
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    string temp = s;
    reverse(temp.begin(), temp.end());

    if(s == temp)
        return true;

    return false;
}

//String to Integer (atoi)
int myAtoi(string str) {
    int i = 0;
    int sign = 1;
    int result = 0;

    if(str.length() == 0)
        return 0;

    while(i < str.length() && str[i] == ' ')
        i++;

    if(i < str.length() && (str[i] == '+' || str[i] == '-'))
        sign = (str[i++] == '-') ? -1 : 1;

    while(i < str.length() && str[i] >= '0' && str[i] <= '9') {
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
            return (sign == 1) ? INT_MAX : INT_MIN;

        result = result * 10 + (str[i++] - '0');
    }

    return result * sign;
}

//Implement strStr()
int strStr(string haystack, string needle) {
    if(needle.size() == 0)
        return 0;

    return haystack.find(needle);
}

//Count and Say
string countAndSay(int n) {
    string ans = "";

    if(n == 1) {
        return "1";
    }
    else {
        string last = countAndSay(n - 1);
        int counter = 0;

        while(counter < last.size()) {
            char val = last[counter];
            int frequency = 1;
            counter++;

            while(val == last[counter]) {
                frequency++;
                counter++;
            }

            ans += to_string(frequency) + val;


        }

        return ans;
    }
}

//Longest Common Prefix
string commonPrefix(string s1, string s2) {
    string prefix = "";

    for(int i = 0; i < s1.length() && i < s2.length(); i++) {
        if(s1[i] == s2[i])
            prefix += s1[i];
        else
            break;
    }

    return prefix;
}

string longestCommonPrefix(vector<string>& strs) {
    string longPrefix = "";

    if(strs.size() == 0)
        return longPrefix;
    else if(strs.size() == 1)
        return strs[0];
    else {
        longPrefix = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            longPrefix = commonPrefix(longPrefix, strs[i]);

            if(longPrefix == "")
                break;
        }
    }

    return longPrefix;
}





