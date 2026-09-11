#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    void backtrack(vector<int>&nums,int start,vector<int>&current,vector<vector<int>>&result){
        //Store the current subset
        result.push_back(current);
        //Try every element from the current index
        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);//Include the current element
            backtrack(nums,i+1,current,result);//Move to the next index
            current.pop_back();//Backtrack and remove the last element
        }
    }
    vector<vector<int>>subsets(vector<int>&nums){
        vector<vector<int>>result;
        vector<int>current;
        backtrack(nums,0,current,result);
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