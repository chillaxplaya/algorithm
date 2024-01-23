// @algorithm @lc id=2870 lang=cpp 
// @title longest-alternating-subarray


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,3,4,3,4])=4
// @test([4,5,6])=2
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int f = -1;
        int l = nums.size();
        int ans = -1;
        for(int i = 0; i < l; i++) {
            if(f != -1) {
                if(i + 1 < l && (i - f + 1) % 2 == nums[i + 1] - nums[f]){
                        continue;
                }
                    
                ans = max(ans,i - f + 1);
                f = -1;
            }
            if(i + 1 < l && nums[i + 1] - nums[i] == 1) {
                    f = i;
            }
        }
        return ans;
    }
};