/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> diameterFast(TreeNode* root) {
        if(root==nullptr) return {0,0};
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        return {(max(op1, max(op2, op3))), (max(left.second, right.second)+1)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        return diameterFast(root).first;
    }
};