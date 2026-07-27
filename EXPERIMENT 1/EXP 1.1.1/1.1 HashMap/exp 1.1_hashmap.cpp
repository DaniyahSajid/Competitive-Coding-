#include<iostream>
#include<unordered_map>//Hash map-stores data in key-value pairs.
using namespace std;
int main(){
    int n,k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int nums[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    unordered_map<int,int>seen;//Stores each array element as the key and its latest index as the value.
    bool found=false;
    for(int i=0;i<n;i++){
        if(seen.find(nums[i])!=seen.end() && i-seen[nums[i]]<=k){//Checks if the current element already exists and whether the index difference is at most k.
            found=true;
            break;
        }
        seen[nums[i]]=i;//Updates the hash map with the current index of the element.
    }
    if(found){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}