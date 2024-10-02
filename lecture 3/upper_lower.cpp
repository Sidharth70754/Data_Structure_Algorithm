#include<iostream>
using namespace std;
int main() {
    char ch;
    cout<< "Enter the character";
    cin >> ch;
    
    if(ch >='a' && ch <='z')
    {
        cout<<" the character is in Lower case";
    }
    else if(ch >='A' && ch <='Z')
    {
        cout<< " the character is in Upper case";
    }
    else 
    {
        cout<< " This is not a character";
    }
    return 0;
}