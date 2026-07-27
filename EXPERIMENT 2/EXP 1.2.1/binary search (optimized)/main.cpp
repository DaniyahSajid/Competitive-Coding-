#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int nums[n];
    cout<<"Enter the sorted array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    int left=0;
    int right=n-1;//starts from last index
    while(left<=right){
        int mid=left+(right-left)/2;//calculate middle index
        if(nums[mid]==target){//target found
            cout<<"Insert position: "<<mid;
            return 0;//end the program
        }else if(nums[mid]<target){//search in right half
            left=mid+1;
        }else{// search in the left half
            right=mid-1;
        }
    }
    cout<<"Inseret position: "<<left;//left gives insertion position
}