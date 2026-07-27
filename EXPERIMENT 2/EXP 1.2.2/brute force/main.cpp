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
    int k;
    cout<<"Enter the rotation position: ";
    cin>>k;
    int rotated[n];
    for(int i=0;i<n;i++){
        rotated[i]=nums[(i+k)%n];//rotate the array
    }
    cout<<"Rotated Array: ";
    for(int i=0;i<n;i++){
        cout<<rotated[i]<<" ";
    }
    int target;
    cout<<"\nEnter the target element: ";
    cin>>target;
    for(int i=0;i<n;i++){
        if(rotated[i]==target){//target found
            cout<<"Output: "<<i;
            return 0;//terminate program
        }
    }
    cout<<"Output: -1";//target not present
}