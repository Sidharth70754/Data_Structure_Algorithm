class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int n = arr.size();
        int high = n-1 ;
        int low = 0;
        
        while(low <= high){
            int mid = (low + high) /2;
            
            
            if(arr[mid] == key) return mid;
            
            
            if(arr[low] <= arr[mid]){
                if(arr[low] <= key && key < arr[mid]){
                    high = mid - 1;
                } else {
                    low = mid +1;
                }
                
            }
            else {
                if(arr[mid] < key && key <= arr[high]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
        
    }
};