#include "LeetCodeProblems.h"

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int length = matrix.size();
    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][length - j - 1];
            matrix[i][length - j - 1] = temp;
        }
    }
}