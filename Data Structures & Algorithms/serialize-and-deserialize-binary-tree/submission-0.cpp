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

class Codec {
public:

    // Encodes a tree to a single string.
  void helper(TreeNode* root,string &s){

        if(root==NULL){
            s+="N,";
            return;
        }

        s+=to_string(root->val)+",";

        helper(root->left,s);
        helper(root->right,s);
    }

    string serialize(TreeNode* root){

        string s="";

        helper(root,s);

        return s;
    }

    TreeNode* build(vector<string> &v,int &i){

        if(v[i]=="N"){
            i++;
            return NULL;
        }

        TreeNode* root=new TreeNode(stoi(v[i]));
        i++;

        root->left=build(v,i);
        root->right=build(v,i);

        return root;
    }

    TreeNode* deserialize(string data){

        vector<string> v;

        string temp="";

        for(char c:data){

            if(c==','){
                v.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }

        int i=0;

        return build(v,i);
    }
};
