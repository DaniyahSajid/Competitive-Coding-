#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int nums[n];
    int answer[n];//stores prefix products and final answer
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];//input array elements
    }
    answer[0]=1;//no elements on the left of first element
    for(int i=1;i<n;i++){
        answer[i]=answer[i-1]*nums[i-1];//store product of all left elements
    }
    int right=1;//stores product of right side elements
    for(int i=n-1;i>=0;i--){
        answer[i]*=right;//combine prefix and suffix products
        right*=nums[i];//update sufix product for next iteration
    }
    cout<<"Product array:";
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
}