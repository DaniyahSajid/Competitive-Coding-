#include<iostream>
using namespace std;
class Solution{
    public:
    int addDigits(int num){
        //Zero has a digital root of zero
        if(num==0){
            return 0;
        }
        //Digital root formula
        return 1+(num-1)%9;
    }
};
int main(){
    Solution obj;
    int num;
    cout<<"Enter a non-negative integer: ";
    cin>>num;
    cout<<"Digital Root: "<<obj.addDigits(num);
    return 0;
}