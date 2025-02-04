//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countSetBits(int n)
    {
        if (n == 0) return 0;
        
        int x = log2(n); 
        int bitsUpTo2x = x * (1 << (x - 1)); 
        int msbFrom2xToN = n - (1 << x) + 1; 
        int remaining = n - (1 << x);
        
        return bitsUpTo2x + msbFrom2xToN + countSetBits(remaining);
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends