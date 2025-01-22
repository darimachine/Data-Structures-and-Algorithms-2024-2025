#pragma once
#include<vector>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void buildTree(TreeNode*& currRoot, const std::vector<int>& nums, int low, int high)
    {
        if (low > high)
            return;

        int mid = low + (high - low) / 2;
        currRoot = new TreeNode(nums[mid]);
        buildTree(currRoot->left, nums, low, mid - 1);
        buildTree(currRoot->right, nums, mid + 1, high);
    }
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        int size = nums.size();
        int rootVal = size / 2;
        TreeNode* toReturn = nullptr;
        buildTree(toReturn, nums, 0, size - 1);
        return toReturn;
    }
};