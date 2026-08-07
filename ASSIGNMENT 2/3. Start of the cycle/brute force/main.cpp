#include<iostream>
#include<unordered_set>
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
    ListNode*detectCycle(ListNode*head){
        unordered_set<ListNode*>visited;
        ListNode*temp=head;
        while(temp!=NULL){
            //If node is already visited, it is the start of the cycle
            if(visited.find(temp)!=visited.end()){
                return temp;
            }
            //Store current node
            visited.insert(temp);
            temp=temp->next;
        }
        //No cycle exists
        return NULL;
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
    ListNode*start=obj.detectCycle(head);
    if(start!=NULL){
        cout<<"Cycle starts at node "<<start->val;
    }
    else{
        cout<<"No Cycle";
    }
    return 0;
}