#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to return the second largest element
    int print2largest(vector<int> &a, int n) {
        if (n < 2) return -1;  
        
        int largest = a[0];
        int slargest = -1;
        
        for (int i = 1; i < n; i++) {
            if (a[i] > largest) {
                slargest = largest;
                largest = a[i];
            } else if (a[i] < largest && a[i] > slargest) {
                slargest = a[i];
            }
        }
        
        return slargest;
    }
};

int main() {
    vector<int> arr = {10, 34, 20, 8};
    int n = arr.size();
    Solution ob;
    int ans = ob.print2largest(arr, n);
    cout << ans << endl;
    return 0;
}
