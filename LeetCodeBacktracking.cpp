#include "LeetCodeProblems.h"

using namespace std;

//Medium
//Letter Combinations of a Phone Number
unordered_map<string, string> buttons = {
        {"2", "abc"},
        {"3", "def"},
        {"4", "ghi"},
        {"5", "jkl"},
        {"6","mno"},
        {"7","pqrs"},
        {"8","tuv"},
        {"9","wxyz"},
};

void backtrack(string combination, string next, vector<string> &combos) {
    if(next.length() == 0)
        combos.emplace_back(combination);
    else {
        string digit = next.substr(0, 1);
        string letters = buttons[digit];

        for(int i = 0; i < letters.length(); i++) {
            char letter = letters[i];
            backtrack(combination + letter, next.substr(1), combos);
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combos;

    if(digits.length() == 0)
        return combos;

    backtrack("", digits, combos);

    return combos;
}

//Generate Parentheses
void backtrack(vector<string> &sol, string curr, int open, int closed, int max) {
    if(curr.length() == max * 2) {
        sol.emplace_back(curr);
        return;
    }

    if(open < max)
        backtrack(sol, curr + "(", open + 1, closed, max);
    if(closed < open)
        backtrack(sol, curr + ")", open, closed + 1, max);
}

vector<string> generateParenthesis(int n) {
    vector<string> sol;
    backtrack(sol, "", 0, 0, n);

    return sol;
}

//Permutations
vector<vector<int>> permute(vector<int>& nums) {
    vector< vector<int> > sol;
    sort(nums.begin(), nums.end());
    sol.push_back(nums);

    while(next_permutation(nums.begin(), nums.end())) {
        sol.push_back(nums);
    }

    return sol;
}

//Subsets
void backtrack(vector< vector<int> > &sol, vector<int> &curr, vector<int> &nums, int start, int size) {
    if(curr.size() == size)
        sol.push_back(curr);

    for(int i = start; i < nums.size(); i++) {
        if(find(curr.begin(), curr.end(), nums[i]) != curr.end())
            continue;

        curr.push_back(nums[i]);
        backtrack(sol, curr, nums, i + 1, size);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector< vector<int> > sol;
    vector<int> curr;

    for(int i = 0; i <= nums.size(); i++)
        backtrack(sol, curr, nums, 0, i);

    return sol;
}

//Word Search
bool onBoard(vector< vector<char> > &board, int i, int j, string word, int index) {
    if(index == word.length())
        return true;

    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;

    if(word[index] != board[i][j])
        return false;

    char temp = board[i][j];
    board[i][j] = '-';

    if(onBoard(board, i + 1, j, word, index + 1) ||
       onBoard(board, i - 1, j, word, index + 1) ||
       onBoard(board, i, j + 1, word, index + 1) ||
       onBoard(board, i, j - 1, word, index + 1))
        return true;

    board[i][j] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == word[0] && onBoard(board, i, j, word, 0))
                return true;
        }
    }

    return false;
}