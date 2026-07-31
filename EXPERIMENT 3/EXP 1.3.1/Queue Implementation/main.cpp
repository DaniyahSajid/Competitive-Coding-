#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s1,s2;
    int choice,x;
    while(true){
        cout<<"\n1.Push\t2.Pop\t3.Peek\t4.Empty\t5.Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element: ";
                cin>>x;
                s2.push(x);//push new element into second stack
                while(!s1.empty()){
                    s2.push(s1.top());//move all elements to second stack
                    s1.pop();
                }
                while(!s2.empty()){
                    s1.push(s2.top());//move elements back to first stack
                    s2.pop();
                }
                break;
            case 2:
                if(s1.empty()){
                    cout<<"Queue is Empty";
                }
                else{
                    cout<<"Deleted Element: "<<s1.top();
                    s1.pop();//delete front element
                }
                break;
            case 3:
                if(s1.empty()){
                    cout<<"Queue is Empty";
                }
                else{
                    cout<<"Front Element: "<<s1.top();//display front element
                }
                break;
            case 4:
                if(s1.empty()){
                    cout<<"Queue is Empty";
                }
                else{
                    cout<<"Queue is Not Empty";
                }
                break;
            case 5:
                return 0;//terminate program
            default:
                cout<<"Invalid Choice";
        }
    }
}