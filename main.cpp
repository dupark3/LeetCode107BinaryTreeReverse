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
    void read(TreeNode* node, vector< vector<int> >& vec, int level = 0){
        if (vec.size() <= level)
            vec.push_back( { node->val } );
        else
            vec[level].push_back(node->val);
            
        if(node->left)
            read(node->left, vec, level + 1);
        if(node->right)
            read(node->right, vec, level + 1);
        
    }

    vector< vector<int> > levelOrderBottom(TreeNode* root) {
        vector< vector<int> > forward_order;
        if (root) 
            read(root, forward_order);
        
        vector< vector<int> > reverse_order(forward_order.rbegin(), forward_order.rend());
        return reverse_order;
    }
};

