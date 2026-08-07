#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool search(vector<int>&nums,int target){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            //Target found
            if(nums[mid]==target){
                return true;
            }
            //Duplicates at both ends
            if(nums[left]==nums[mid]&&nums[mid]==nums[right]){
                left++;
                right--;
            }
            //Left half is sorted
            else if(nums[left]<=nums[mid]){
                if(nums[left]<=target&&target<nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            //Right half is sorted
            else{
                if(nums[mid]<target&&target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
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