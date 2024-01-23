// @algorithm @lc id=10 lang=cpp 
// @title regular-expression-matching


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("aa","a")=false
// @test("aa","a*")=true
// @test("ab",".*")=true
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(m,vector<bool>(n));
        bool fflag = false;
        if(p[0] == '*'){
            dp[0][0] = true;
        }else if(p[0] == '.'){
            dp[0][0] = true;
        }else if(p[0] == s[0]){
            dp[0][0] = true;
        }else{
            dp[0][0] = false;
        }
        for(int i = 1; i < n; i++) {
                dp[0][i] = fflag;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 0;j < n; j++) {
                if(p[i] == '*') {
                    dp[i][j] = 
                }
            }
        }
    }
};