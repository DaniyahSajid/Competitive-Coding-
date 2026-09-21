#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int findDuplicate(vector<int>& nums){
        //Phase 1: Find the meeting point inside the cycle
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];//Move one step
            fast=nums[nums[fast]];//Move two steps
        }while(slow!=fast);

        //Phase 2: Find the entrance of the cycle
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;//Duplicate number
    }
};

int main(){
    Solution obj;
    int n;

    cout<<"Enter n: ";
    cin>>n;

    vector<int> nums(n+1);
    cout<<"Enter "<<n+1<<" elements: ";
    for(int i=0;i<=n;i++){
        cin>>nums[i];
    }

    cout<<"Duplicate Number: "<<obj.findDuplicate(nums);
    return 0;
}