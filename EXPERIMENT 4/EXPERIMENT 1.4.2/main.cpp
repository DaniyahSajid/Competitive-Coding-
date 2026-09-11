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
    ListNode*oddEvenList(ListNode*head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        //Create dummy nodes for odd and even lists
        ListNode*oddDummy=new ListNode(0);
        ListNode*evenDummy=new ListNode(0);
        //Pointers to build odd and even lists
        ListNode*oddTail=oddDummy;
        ListNode*evenTail=evenDummy;
        //Pointer to traverse the original list
        ListNode*temp=head;
        //Position starts from 1
        int position=1;
        while(temp!=NULL){
            //Store odd position nodes
            if(position%2!=0){
                oddTail->next=new ListNode(temp->val);
                oddTail=oddTail->next;
            }
            //Store even position nodes
            else{
                evenTail->next=new ListNode(temp->val);
                evenTail=evenTail->next;
            }
            temp=temp->next;
            position++;
        }
        //Connect odd list with even list
        oddTail->next=evenDummy->next;
        //Return head of rearranged list
        return oddDummy->next;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    if(n==0){
        cout<<"Linked List is empty";
        return 0;
    }
    ListNode*head=NULL;
    ListNode*tail=NULL;
    cout<<"Enter node values: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode*newNode=new ListNode(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    ListNode*result=obj.oddEvenList(head);
    cout<<"Odd Even Linked List: ";
    while(result!=NULL){
        cout<<result->val<<" ";
        result=result->next;
    }
    return 0;
}