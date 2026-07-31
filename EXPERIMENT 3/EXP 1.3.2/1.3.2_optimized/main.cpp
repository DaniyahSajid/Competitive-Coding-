#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution{
    public:
    int largestArea(vector<int>&heights){
        heights.push_back(0);// Add a sentinel bar of height 0
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int height=heights[st.top()];
                st.pop();
                int left;
                if(st.empty()){
                    left=-1;
                }
                else{
                    left=st.top();
                }
                int width=i-left-1;
                int area=height*width;
                if(area>maxArea){
                    maxArea=area;
                }
            }
            st.push(i);
        }
        heights.pop_back();// Remove the sentinel bar
        return maxArea;
    }
};

int main(){
    Solution obj;
    int n;
    cout<<"Enter number of bars: ";
    cin>>n;
    vector<int>heights(n);
    cout<<"Enter heights: ";
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    cout<<"Largest Rectangle Area = "<<obj.largestArea(heights);
    return 0;
}