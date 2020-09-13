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

//Binary Tree Inorder Traversal
void helper(TreeNode* root, vector<int> &order) {
    if(root == nullptr)
        return;

    if(root->left != nullptr)
        helper(root->left, order);

    order.push_back(root->val);

    if(root->right != nullptr)
        helper(root->right, order);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> order;
    helper(root, order);

    return order;
}


//Binary Tree Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> order;
    queue<TreeNode*> q;
    queue<TreeNode*> next;
    int row = 1;

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

            if(row%2 == 0)
                values.insert(values.begin(), node->val);
            else
                values.push_back(node->val);

            q.pop();
        }

        row++;
        order.emplace_back(values);
        q = move(next);
    }

    return order;
}

//Construct Binary Tree from Preorder and Inorder Traversal
unordered_map<int, int> map;
int index = 0;

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end) {
    if(start > end)
        return nullptr;

    TreeNode* root = new TreeNode(preorder[index]);
    int position = map[preorder[index++]];

    root->left = helper(preorder, inorder, start, position - 1);
    root->right = helper(preorder, inorder, position + 1, end);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty())
        return nullptr;

    for(int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }

    return helper(preorder, inorder, 0, inorder.size() - 1);
}

//Populating Next Right Pointers in Each Node
Node* connect(Node* root) {
    if(root == nullptr)
        return nullptr;

    Node** rootHead = &root;
    queue<Node*> q;
    queue<Node*> next;
    q.push(root);

    while(!q.empty()) {
        while(!q.empty()) {
            Node* curr = q.front();

            if(curr->left != nullptr)
                next.push(curr->left);
            if(curr->right != nullptr)
                next.push(curr->right);

            q.pop();
            if(q.size() == 0)
                curr->next = nullptr;
            else
                curr->next = q.front();
        }

        q = move(next);
    }

    return *rootHead;
}

//Kth Smallest Element in a BST
vector<int> inorder(TreeNode* root, vector<int> &nums) {
    if(root == nullptr)
        return nums;

    inorder(root->left, nums);
    nums.emplace_back(root->val);
    inorder(root->right, nums);

    return nums;
}

int kthSmallest(TreeNode* root, int k) {
    if(root == nullptr)
        return -1;

    vector<int> nums;
    inorder(root, nums);

    return nums[k - 1];
}