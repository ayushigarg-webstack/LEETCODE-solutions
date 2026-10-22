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
    bool checkSymmetry(TreeNode* lRoot, TreeNode* rRoot) {
        if(lRoot == nullptr && rRoot == nullptr) return true;
        if(lRoot == nullptr || rRoot == nullptr) return false;
        if(lRoot->val != rRoot->val) return false;
        bool checkLeft = checkSymmetry(lRoot->left, rRoot->right);
        bool checkRight = checkSymmetry(lRoot->right, rRoot->left);
        return checkLeft && checkRight;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        bool check = checkSymmetry(root->left, root->right);
        return check;
    }
};