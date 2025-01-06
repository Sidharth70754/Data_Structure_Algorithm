class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n,0);

        int count = 0, steps = 0;

        //left to right pass
        for(int i = 0; i<n;i++){
            res[i] += steps;
            count += (boxes[i] == '1' ? 1:0);
            steps += count;
        }

        count = 0;
        steps = 0;
        //right to left pass
        for(int i = n-1;i >= 0;i--){
            res[i] += steps;
            count += (boxes[i] == '1' ? 1:0);
            steps += count;
        }
        return res;
    }
};