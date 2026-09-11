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
    //Find path from root to target node
    bool findPath(TreeNode*root,int target,vector<TreeNode*>&path){
        if(root==NULL){
            return false;
        }
        path.push_back(root);//Add current node to path
        //Target found
        if(root->val==target){
            return true;
        }
        //Search in left or right subtree
        if(findPath(root->left,target,path)||findPath(root->right,target,path)){
            return true;
        }
        path.pop_back();//Remove node if target not found
        return false;
    }
    TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        //Find path from root to p
        findPath(root,p->val,path1);
        //Find path from root to q
        findPath(root,q->val,path2);
        TreeNode*lca=NULL;
        int i=0;
        //Compare both paths
        while(i<path1.size()&&i<path2.size()&&path1[i]==path2[i]){
            lca=path1[i];//Store last common node
            i++;
        }
        return lca;
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
    //Find the nodes p and q
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