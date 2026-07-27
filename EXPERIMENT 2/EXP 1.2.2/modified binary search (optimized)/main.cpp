#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int nums[n];
    cout<<"Enter the rotated sorted array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];//input rotated array
    }
    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;//calculate middle index
        cout<<"\nLeft="<<left<<" Mid="<<mid<<" Right="<<right<<endl;
        if(nums[mid]==target){//target found
            cout<<"Output: "<<mid;
            return 0;//terminate program
        }
        if(nums[left]<=nums[mid]){//left half is sorted
            cout<<"Left half is sorted"<<endl;
            if(nums[left]<=target && target<nums[mid]){
                cout<<"Target lies in left half"<<endl;
                right=mid-1;//search left half
            }
            else{
                cout<<"Target lies in right half"<<endl;
                left=mid+1;//search right half
            }
        }
        else{//right half is sorted
            cout<<"Right half is sorted"<<endl;
            if(nums[mid]<target && target<=nums[right]){
                cout<<"Target lies in right half"<<endl;
                left=mid+1;//search right half
            }
            else{
                cout<<"Target lies in left half"<<endl;
                right=mid-1;//search left half
            }
        }
    }
    cout<<"Output: -1";//target not found
}