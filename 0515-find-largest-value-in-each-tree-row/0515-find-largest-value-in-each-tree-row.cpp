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
    vector<int> largestValues(TreeNode* root) {
        vector<int> vals;

        if(!root)
            return vals;

        queue<TreeNode*> q;
        q.push(root);
        int maxV = INT_MIN;;
        
        q.push(0);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(!root) {
                vals.emplace_back(maxV);
                maxV = INT_MIN;
                if(q.empty()) break;
                q.push(0);
                continue;
            }
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            maxV = max(root->val, maxV);
        }

        return vals;
    }
};