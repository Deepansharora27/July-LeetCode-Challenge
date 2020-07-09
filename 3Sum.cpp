
/*

PROBLEM STATEMENT : 

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]



*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        if(nums.size() < 3) return {};
        
        sort(nums.begin() , nums.end());
        vector < vector<int> > result ; 
        
        set<vector<int>> mySet ;
        
        for(int i=0 ; i<nums.size()-2 ; i++){
            int j = i+1 ;
            int k = nums.size()-1 ; 
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                   mySet.insert({nums[i] , nums[j++] , nums[k--]});
                }else if(sum > 0){
                    k-- ; 
                }else if(sum < 0){
                    j++ ; 
                }
            }
        }
        
       for(auto x : mySet){
           result.push_back(x);
       }
        
        return result ;
        
    }
};