#include<iostream>
using namespace std;
int main () {
    int marks;
    cout<<"Enter your marks:";
    cin>>marks;

    if(marks >= 90)
    {
        cout<<" you are pass with A grade";
    }
    else if(marks >= 80 && marks <=90)
    {
        cout<<" you are pass with B grade";
    } 
    else if(marks >=70 && marks <=80)
    {
        cout<< " you are pass with C grade";
    }
    else
    {
        cout<<"you are fail";
    }
    return 0;
}