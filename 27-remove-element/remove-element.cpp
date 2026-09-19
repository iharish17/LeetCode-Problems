class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        if(nums.size() == 0){
            return false;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};