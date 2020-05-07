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
//     define height(depth) og the node
    int depth(TreeNode* root,int a,int height){
        if(root==NULL) return 0;
        if(root->val==a) return height;
        int temp=depth(root->left,a,height+1);
        if(temp) return temp;
        return depth(root->right,a,height+1);
    }
//     check their are same parent or not
    bool check(TreeNode* root,int x,int y){
        if(root==NULL)return 0;
        if(root->left && root->right){
            if((root->left->val==x &&root->right->val==y)|| (root->left->val==y &&root->right->val==x))
                return true;
        }
        return ((check(root->left,x,y))||(check(root->right,x,y)));
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        return (depth(root,x,1)==depth(root,y,1) && !(check(root,x,y)));
    }
};