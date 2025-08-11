class Solution {
  public:
    void subset(int idx, int sum, vector<int>& arr, int N, vector<int> & Sumsubset){
        if(idx == N){
            Sumsubset.push_back(sum);
            return;
        }
        subset (idx + 1, sum + arr[idx], arr, N , Sumsubset);
        subset (idx + 1 , sum, arr, N, Sumsubset);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> Sumsubset;
        int N = arr.size();
        subset(0, 0 , arr, N, Sumsubset);
        sort(Sumsubset.begin(), Sumsubset.end());
        return Sumsubset;
    }
};