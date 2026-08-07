#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool search(vector<int>&nums,int target){
        //Traverse the entire array
        for(int i=0;i<nums.size();i++){
            //Target found
            if(nums[i]==target){
                return true;
            }
        }
        //Target not found
        return false;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter target: ";
    cin>>target;
    if(obj.search(nums,target)){
        cout<<"Target Found";
    }
    else{
        cout<<"Target Not Found";
    }
    return 0;
}