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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode *> order;
        TreeNode *root=new TreeNode(preorder[0]);
        order.push(root);
        
        TreeNode *ptr=NULL;
        TreeNode *prev=NULL;
        for(int i=1;i<preorder.size();i++){
            TreeNode *cur=new TreeNode(preorder[i]);
            ptr=order.top();
             
            if(cur->val<ptr->val){
                ptr->left=cur;
            }
            else{
                while(!order.empty() && ptr->val<cur->val){
                    prev=order.top();
                    order.pop();
                    if(!order.empty())
                        ptr=order.top();
                }
                prev->right=cur;
            }
            order.push(cur);
        }
        return root;
    }
};