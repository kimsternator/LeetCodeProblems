#include "LeetCodeProblems.h"

using namespace std;

//Maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    int maxLen = 0;

    if(root == nullptr)
        return maxLen;
    else {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

}

//Validate Binary Search Tree
bool helper(TreeNode* root, long min, long max) {
    if(root == nullptr)
        return true;
    else {
        if(root->val > min && root->val < max)
            return (helper(root->left, min, root->val) &&
                    helper(root->right, root->val, max));
    }

    return false;
}

bool isValidBST(TreeNode* root) {
    if(root == nullptr)
        return true;

    return helper(root, LONG_MIN, LONG_MAX);
}

//Symmetric Tree
bool isMirror(TreeNode* left, TreeNode* right) {
    if(left == nullptr && right == nullptr)
        return true;
    else if(left == nullptr || right == nullptr)
        return false;

    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    vector<int> row;

    if(root == nullptr)
        return true;

    return isMirror(root, root);
}

//Binary Tree Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> order;
    queue<TreeNode*> q;
    queue<TreeNode*> next;

    if(root == nullptr)
        return order;
    else
        q.push(root);

    while(q.size() > 0) {
        vector<int> values;

        while(!q.empty()) {
            auto node = q.front();

            if(node->left != nullptr)
                next.push(node->left);
            if(node->right != nullptr)
                next.push(node->right);

            values.push_back(node->val);
            q.pop();
        }

        order.emplace_back(values);
        q = move(next);
    }

    return order;
}

//Convert Sorted Array into binary tree
TreeNode* tree(vector<int>& nums, int leftIndex, int rightIndex) {
    if(leftIndex > rightIndex)
        return nullptr;

    int midIndex = (leftIndex + rightIndex) / 2;
    TreeNode* root = new TreeNode(nums[midIndex]);

    root->left = tree(nums, leftIndex, midIndex - 1);
    root->right = tree(nums, midIndex + 1, rightIndex);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty())
        return nullptr;

    return tree(nums, 0, nums.size() - 1);
}