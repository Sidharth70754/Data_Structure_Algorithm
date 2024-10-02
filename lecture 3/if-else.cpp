//  check the number is positive or negative using if-else statement

#include<iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number:";
    cin>>num;
    if(num>=0)
    {
        cout<< "this number is positive number"<<endl;
    }
    else {
        cout<< "this number is negative number"<<endl;
    }
    return 0;

}
