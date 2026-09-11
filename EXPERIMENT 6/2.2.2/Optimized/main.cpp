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
    TreeNode*inorderSuccessor(TreeNode*root,TreeNode*p){
        TreeNode*successor=NULL;
        while(root!=NULL){
            //Current node is smaller than or equal to p
            if(p->val>=root->val){
                root=root->right;//Move right
            }
            //Current node is greater than p
            else{
                successor=root;//Store possible successor
                root=root->left;//Search for a smaller greater value
            }
        }
        return successor;
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