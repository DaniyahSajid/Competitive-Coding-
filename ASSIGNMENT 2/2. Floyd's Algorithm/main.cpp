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

        //Initialize slow and fast pointers
        ListNode*slow=head;
        ListNode*fast=head;

        //Traverse the linked list
        while(fast!=NULL&&fast->next!=NULL){

            //Move slow pointer by one step
            slow=slow->next;

            //Move fast pointer by two steps
            fast=fast->next->next;

            //If both pointers meet, cycle exists
            if(slow==fast){
                return true;
            }
        }

        //No cycle found
        return false;
    }
};

int main(){

    Solution obj;

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    if(n<=0){
        cout<<"Invalid number of nodes";
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

    if(pos>=0&&pos<n){
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