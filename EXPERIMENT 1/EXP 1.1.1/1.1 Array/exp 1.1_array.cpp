#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter the size of array: ";
    cin>>n;
    int nums[n];//Stores the input array elements.
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    bool found=false;//Acts as a flag to indicate whether a valid duplicate is found.
    for(int i=0;i<n;i++){//Selects one element at a time for comparison.
        for(int j=i+1;j<n;j++){//Compares the selected element with the remaining elements.
            if(nums[i]==nums[j]&&abs(i-j)<=k){//Checks if duplicate elements are within a distance of k. abs() returns the absolute difference between indices.
                found=true;
                break;
            }
        }
        if(found)//Stops further comparisons once a valid duplicate is found.
            break;
    }
    if(found){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}