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

    unordered_map<int,int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd){

        if(inStart > inEnd)
            return NULL;

        TreeNode* root =
        new TreeNode(preorder[preIndex++]);

        int pos = mp[root->val];

        root->left =
        solve(preorder,inorder,inStart,pos-1);

        root->right =
        solve(preorder,inorder,pos+1,inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;

        return solve(preorder,inorder,0,inorder.size()-1);
    }
};
