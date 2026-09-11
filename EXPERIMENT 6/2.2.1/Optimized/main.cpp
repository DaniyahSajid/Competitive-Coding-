#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
class Solution{
    public:
    TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        //Return if tree is empty or current node is p or q
        if(root==NULL||root==p||root==q){
            return root;
        }
        //Search for p or q in the left subtree
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        //Search for p or q in the right subtree
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        //Both nodes found in different subtrees
        if(left!=NULL&&right!=NULL){
            return root;
        }
        //Return the side where a node was found
        if(left!=NULL){
            return left;
        }
        return right;
    }
};
int main(){
    Solution obj;
    //Create sample binary tree
    TreeNode*root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    int pValue,qValue;
    cout<<"Enter value of p: ";
    cin>>pValue;
    cout<<"Enter value of q: ";
    cin>>qValue;
    TreeNode*p=NULL;
    TreeNode*q=NULL;
    //Find nodes p and q
    vector<TreeNode*>nodes;
    nodes.push_back(root);
    for(int i=0;i<nodes.size();i++){
        TreeNode*current=nodes[i];
        if(current->val==pValue){
            p=current;
        }
        if(current->val==qValue){
            q=current;
        }
        if(current->left!=NULL){
            nodes.push_back(current->left);
        }
        if(current->right!=NULL){
            nodes.push_back(current->right);
        }
    }
    TreeNode*lca=obj.lowestCommonAncestor(root,p,q);
    cout<<"Lowest Common Ancestor: "<<lca->val;
    return 0;
}