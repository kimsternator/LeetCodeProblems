#include "LeetCodeProblems.h"

using namespace std;

bool containsDups(vector<char>& rowCol) {
    unordered_map<char, int> dict;

    for(int i = 0; i < rowCol.size(); i++) {
        if(rowCol[i] == '.')
            continue;
        else if(dict[rowCol[i]] == 1)
            return true;
        else
            dict[rowCol[i]] = 1;
    }

    return false;
}

void printVec(const vector<char>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size() - 1; i++) {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.size() - 1] << "]\n";
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++) {
        if(containsDups(board[i])) {
            cout << "condition1" << endl;
            return false;
        }

        vector<char> column;

        for(int j = 0; j < 9; j++)
            column.push_back(board[j][i]);

        if(containsDups(column)) {
            cout << "condition2" << endl;
            return false;
        }

        column.clear();
    }

    for(int i = 1; i < 8; i+=3) {
        vector<char> square;

        for(int j = 1; j < 8; j+=3) {
            square.push_back(board[i - 1][j - 1]);
            square.push_back(board[i - 1][j]);
            square.push_back(board[i - 1][j + 1]);
            square.push_back(board[i][j - 1]);
            square.push_back(board[i][j]);
            square.push_back(board[i][j + 1]);
            square.push_back(board[i + 1][j - 1]);
            square.push_back(board[i + 1][j]);
            square.push_back(board[i + 1][j + 1]);

            if(containsDups(square))
                return false;

            square.clear();
        }
    }

    return true;
}