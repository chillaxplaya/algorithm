// @algorithm @lc id=3114 lang=cpp 
// @title beautiful-towers-i


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,3,4,1,1])=13
// @test([6,5,3,9,2,7])=22
// @test([3,2,5,5,2,3])=18
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int len = maxHeights.size();
        long long ans = 0;
        for(int i = 0; i < len; i++) {
            long long res = maxHeights[i];
            int pre = maxHeights[i];
            for(int j = i + 1; j < len; j++){
                pre = min(pre,maxHeights[j]);
                res += pre;
            }
            pre = maxHeights[i];
            for(int j = i - 1; j >= 0; j--){
                pre = min(pre,maxHeights[j]);
                res += pre;
            }
            ans = (long long)max(res,ans);
        }
        return ans;
    }
};