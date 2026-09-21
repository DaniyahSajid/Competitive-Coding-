#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:
    int findDuplicate(vector<int>& nums){
        unordered_set<int> seen;
        
        //Check every number
        for(int x:nums){
            //If already seen, it is the duplicate
            if(seen.count(x)){
                return x;
            }
            //Store the number
            seen.insert(x);
        }
        return -1;
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