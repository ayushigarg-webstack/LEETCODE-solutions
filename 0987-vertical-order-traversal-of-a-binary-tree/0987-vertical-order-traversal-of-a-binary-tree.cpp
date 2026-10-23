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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       if(root==nullptr) return {};
       map<int, map<int, multiset<int> > > nodes;
       queue<pair<TreeNode*, pair<int,int> > > q;
       vector<vector<int>> ans;
       q.push({root, {0,0} });
       while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int horizDis = temp.second.first;
            int level = temp.second.second;
            nodes[horizDis][level].insert(frontNode->val);
            if(frontNode->left) {
                q.push({frontNode->left, {horizDis-1, level+1}});
            }    
            if(frontNode->right) {
                q.push({frontNode->right, {horizDis+1, level+1}});
            }    
       }
       
       for(auto i : nodes) {
        vector<int> smallAns;
            for(auto j : i.second) {
                for(auto k : j.second) {
                    smallAns.push_back(k);
                }    
            }
            ans.push_back(smallAns);
        }
        return ans;
    }
};