#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};
class Solution{
    public:
    bool hasCycle(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            //Cycle detected
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    if(n<=0){
        return 0;
    }
    ListNode*head=NULL;
    ListNode*tail=NULL;
    ListNode*nodes[1000];
    cout<<"Enter node values: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode*newNode=new ListNode(x);
        nodes[i]=newNode;
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    int pos;
    cout<<"Enter cycle position (-1 for no cycle): ";
    cin>>pos;
    if(pos!=-1){
        tail->next=nodes[pos];
    }
    if(obj.hasCycle(head)){
        cout<<"Cycle Detected";
    }
    else{
        cout<<"No Cycle";
    }
    return 0;
}