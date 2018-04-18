/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // recursively add
    void read(TreeNode* node, vector< vector<int> >& ret, int level = 0){
        if (ret.size() <= level){
            vector<int> temp = { node->val };
            ret.push_back(temp);
        } else {
            ret[level].push_back(node->val);
        }
            
        if(node->left){
            read(node->left, ret, ++level);
            --level;
        }
        if(node->right){
            read(node->right, ret, ++level);
            --level;
        }
    }

    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > ret;
        if (root)
            read(root, ret);
        
        vector< vector<int> > reverse_order(ret.rbegin(), ret.rend());
        return reverse_order;
    }
};

