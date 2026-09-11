#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution{
    public:
    set<vector<int>>uniqueCombinations;//Set removes duplicate combinations
    void backtrack(vector<int>&candidates,int remaining,vector<int>&current){
        //Target reached
        if(remaining==0){
            vector<int>combination=current;
            //Sort combination so different orders become identical
            for(int i=0;i<combination.size();i++){
                for(int j=i+1;j<combination.size();j++){
                    if(combination[i]>combination[j]){
                        swap(combination[i],combination[j]);
                    }
                }
            }
            uniqueCombinations.insert(combination);
            return;
        }
        //Target exceeded
        if(remaining<0){
            return;
        }
        //Try every candidate
        for(int i=0;i<candidates.size();i++){
            current.push_back(candidates[i]);//Choose candidate
            backtrack(candidates,remaining-candidates[i],current);//Explore
            current.pop_back();//Backtrack
        }
    }
    vector<vector<int>>combinationSum(vector<int>&candidates,int target){
        vector<vector<int>>result;
        vector<int>current;
        backtrack(candidates,target,current);
        //Convert set into result vector
        for(auto combination:uniqueCombinations){
            result.push_back(combination);
        }
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