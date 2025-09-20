// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
       int i = 0;
       int j = s.size() -1;
       while(i <j){
           char temp = s[i];
           s[i] = s[j];
           s[j] = temp;
           
           i++;
           j--;
       }
       return s;
    }
};
