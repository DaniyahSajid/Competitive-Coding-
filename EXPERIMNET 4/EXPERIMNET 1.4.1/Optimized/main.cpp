#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Solution{
    public:
    bool isPalindrome(Node* head){
        if(head==NULL || head->next==NULL){
            return true;
        }
        // Find the middle node
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // Reverse the second half
        Node* prev=NULL;
        Node* curr=slow->next;
        while(curr!=NULL){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        // Compare both halves
        Node* first=head;
        Node* second=prev;
        while(second!=NULL){
            if(first->data!=second->data){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    Node* head=NULL;
    Node* tail=NULL;
    cout<<"Enter node values: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode=new Node(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    if(obj.isPalindrome(head)){
        cout<<"Palindrome Linked List";
    }
    else{
        cout<<"Not a Palindrome Linked List";
    }
    return 0;
}