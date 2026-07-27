#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int nums[n];
    int answer[n];//stores the final product array
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){//calculate answer for each index
        int product=1;// 1 is multiplicative identity
        for(int j=0;j<n;j++){//multiply all elements except current
            if(i!=j){//skip the current element
                product*=nums[j];//multiply product with current element
            }
        }
        answer[i]=product;//store product in answer array
    }
    cout<<"Product array: ";
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
}