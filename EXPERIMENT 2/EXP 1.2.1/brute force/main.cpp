#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int nums[n];
    cout<<"Enter the sorted array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];//input sorted array
    }
    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    for(int i=0;i<n;i++){
        if(nums[i]>=target){//target found or insertion position reached
            cout<<"Insert Position: "<<i;
            return 0;//terminate program
        }
    }
    cout<<"Insert Position: "<<n;//target is greater than all elements
}