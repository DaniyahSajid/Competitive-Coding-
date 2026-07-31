#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int largestArea(vector<int>&heights){
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++){//Select each bar as the starting point
            int minHeight=heights[i];
            for(int j=i;j<n;j++){//Extend the rectangle to the right
                if(heights[j]<minHeight){
                    minHeight=heights[j];//Update minimum height
                }
                int width=j-i+1;
                int area=minHeight*width;
                if(area>maxArea){
                    maxArea=area;//Update maximum area
                }
            }
        }
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