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
        // Empty or single-node list is always a palindrome
        if(head==NULL || head->next==NULL){
            return true;
        }
        // Find the middle using slow and fast pointers
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // Reverse the second half of the linked list
        Node* prev=NULL;
        Node* curr=slow->next;
        while(curr!=NULL){
            Node* nextNode=curr->next; // Store next node
            curr->next=prev; // Reverse the link
            prev=curr;
            curr=nextNode;
        }
        // Compare the first half with the reversed second half
        Node* first=head;
        Node* second=prev;
        while(second!=NULL){
            if(first->data!=second->data){
                return false; // Values don't match
            }
            first=first->next;
            second=second->next;
        }
        return true; // All values matched
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
    // Create the linked list
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
    // Check whether the linked list is a palindrome
    if(obj.isPalindrome(head)){
        cout<<"Palindrome Linked List";
    }
    else{
        cout<<"Not a Palindrome Linked List";
    }
    return 0;
}
