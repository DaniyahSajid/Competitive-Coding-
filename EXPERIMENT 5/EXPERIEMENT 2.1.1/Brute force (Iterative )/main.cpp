#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>>subsets(vector<int>&nums){
        vector<vector<int>>result;
        int n=nums.size();
        int total=1<<n;//Total number of subsets is 2^n
        for(int mask=0;mask<total;mask++){//Generate every possible bitmask
            vector<int>current;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){//Check if the i-th bit is set
                    current.push_back(nums[i]);//Include the element
                }
            }
            result.push_back(current);//Store the current subset
        }
        return result;
    }
};

int main(){
    Solution obj;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>result=obj.subsets(nums);
    cout<<"All subsets:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"[";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j];
            if(j<result[i].size()-1){
                cout<<",";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}