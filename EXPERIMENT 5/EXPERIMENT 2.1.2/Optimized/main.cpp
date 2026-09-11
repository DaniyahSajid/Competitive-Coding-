#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void backtrack(vector<int>&candidates,int start,vector<int>&current,int remaining,vector<vector<int>>&result){
        //Target reached
        if(remaining==0){
            result.push_back(current);
            return;
        }
        //Try candidates from the current index
        for(int i=start;i<candidates.size();i++){
            //Prune if candidate is larger than remaining target
            if(candidates[i]>remaining){
                break;
            }
            current.push_back(candidates[i]);//Choose candidate
            //Use i again because repetition is allowed
            backtrack(candidates,i,current,remaining-candidates[i],result);
            current.pop_back();//Backtrack
        }
    }
    vector<vector<int>>combinationSum(vector<int>&candidates,int target){
        vector<vector<int>>result;
        vector<int>current;
        //Sort candidates for effective pruning
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,current,target,result);
        return result;
    }
};
int main(){
    Solution obj;
    int n,target;
    cout<<"Enter number of candidates: ";
    cin>>n;
    vector<int>candidates(n);
    cout<<"Enter candidates: ";
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }
    cout<<"Enter target: ";
    cin>>target;
    vector<vector<int>>result=obj.combinationSum(candidates,target);
    cout<<"Unique combinations:"<<endl;
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