#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the rotated sorted array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            cout<<"Output: "<<mid;
            return 0;
        }
        if(nums[left]<=nums[mid]){//left half is sorted
            if(nums[left]<=target && target<nums[mid])
                right=mid-1;//search left half
            else
                left=mid+1;//search right half
        }else{//right half is sorted
            if(nums[mid]<target && target<=nums[right])
                left=mid+1;//search right half
            else
                right=mid-1;//search left half
        }
    }
    cout<<"Output: -1";
}
