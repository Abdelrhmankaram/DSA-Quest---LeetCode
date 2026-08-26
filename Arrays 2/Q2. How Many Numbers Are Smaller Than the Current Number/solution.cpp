class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       int prefix[101];

       for(int i = 0 ; i < nums.size() ; i++) {
        prefix[nums[i]]++;
       }

       for(int i = 1 ; i <= 100 ; i++) {
        prefix[i] += prefix[i-1];
       }

       vector<int> ans;

       for(int i = 0 ; i < nums.size() ; i++) {
        if(nums[i] == 0){
            ans.push_back(0);
        }
        else{
            ans.push_back(prefix[nums[i]-1]);
        }
       }

       return ans;
    }
};