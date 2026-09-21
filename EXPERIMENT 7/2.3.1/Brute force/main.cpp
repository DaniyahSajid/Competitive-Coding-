#include<iostream>
using namespace std;
class Solution{
    public:
    int addDigits(int num){
        //Repeat until num becomes a single digit
        while(num>=10){
            int sum=0;
            //Calculate the sum of digits
            while(num>0){
                sum+=num%10;//Add the last digit
                num/=10;//Remove the last digit
            }
            num=sum;//Update num with the digit sum
        }
        return num;
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