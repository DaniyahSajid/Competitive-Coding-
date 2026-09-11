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
    //Store nodes in in-order sequence
    void inorder(TreeNode*root,vector<TreeNode*>&order){
        if(root==NULL){
            return;
        }
        inorder(root->left,order);//Visit left subtree
        order.push_back(root);//Store current node
        inorder(root->right,order);//Visit right subtree
    }
    TreeNode*inorderSuccessor(TreeNode*root,TreeNode*p){
        vector<TreeNode*>order;
        //Generate sorted in-order sequence
        inorder(root,order);
        //Find p and return the next node
        for(int i=0;i<order.size();i++){
            if(order[i]==p){
                if(i+1<order.size()){
                    return order[i+1];
                }
                return NULL;//p is the largest node
            }
        }
        return NULL;
    }
};
int main(){
    Solution obj;
    //Create sample BST
    TreeNode*root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->left->left->left=new TreeNode(1);
    int pValue;
    cout<<"Enter value of p: ";
    cin>>pValue;
    TreeNode*p=NULL;
    //Find node p
    vector<TreeNode*>nodes;
    nodes.push_back(root);
    for(int i=0;i<nodes.size();i++){
        TreeNode*current=nodes[i];
        if(current->val==pValue){
            p=current;
            break;
        }
        if(current->left!=NULL){
            nodes.push_back(current->left);
        }
        if(current->right!=NULL){
            nodes.push_back(current->right);
        }
    }
    TreeNode*successor=obj.inorderSuccessor(root,p);
    if(successor!=NULL){
        cout<<"In-order Successor: "<<successor->val;
    }
    else{
        cout<<"In-order Successor: NULL";
    }
    return 0;
}