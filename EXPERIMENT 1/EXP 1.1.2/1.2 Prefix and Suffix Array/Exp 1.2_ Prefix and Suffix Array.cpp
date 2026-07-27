#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int nums[n];
    int answer[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];//input array elements
    }
    answer[0]=1;//no element on the left of first element
    for(int i=1;i<n;i++){
        answer[i]=answer[i-1]*nums[i-1];//store prefix product
    }
    int right=1;//stores suffix product
    for(int i=n-1;i>=0;i--){
        answer[i]*=right;//multiply prefix and suffix product
        right*=nums[i];//update the product
    }
    cout<<"Product array: ";
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
}