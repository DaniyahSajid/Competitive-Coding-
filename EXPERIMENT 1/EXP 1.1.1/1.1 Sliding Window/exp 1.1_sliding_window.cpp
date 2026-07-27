#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter the array size: ";
    cin>>n;
    int nums[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    unordered_set<int>window;//Stores the unique elements in the current sliding window.
    bool found=false;
    for(int i=0;i<n;i++){
        if(window.find(nums[i])!=window.end()){//Checks whether the current element already exists in the sliding window.
            found=true;
            break;
        }
        window.insert(nums[i]);//Adds the current element to the sliding window.
        if(window.size()>k){//Checks if the window size exceeds k.
            window.erase(nums[i-k]);//Removes the element that moves out of the sliding window.
        }
    }
    if(found){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}