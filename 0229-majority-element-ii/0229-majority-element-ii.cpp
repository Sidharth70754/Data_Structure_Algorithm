class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 =0;
        int count2 = 0;
        int elm1= INT_MIN;
        int elm2 = INT_MIN;
        for (int i =0; i<nums.size();i++){
            if(count1 == 0 && nums[i]!= elm2){
                count1 = 1 ; 
                elm1 = nums[i];
            }
        else if (count2 == 0  && nums[i]!= elm1){
            count2 = 1; 
            elm2 = nums[i];
        }
        else if(elm1 == nums[i]){
            count1++;
        }
        else if (elm2 == nums[i]){
            count2++;
        }
        else{
            count1 --;
            count2 --;
        }
        }
    
        vector<int> ls;
        count1 =0, count2 =0;
        for (int i = 0; i<nums.size();i++){
            if(elm1 == nums[i]) count1++;
            if(elm2 == nums[i]) count2++;
        }
        int mini = (int) (nums.size()/3) +1;
        if (count1 >= mini) ls.push_back(elm1);
        if (count2 >= mini) ls.push_back(elm2);
        sort(ls.begin(), ls.end());
        return ls;
    }
    
};
