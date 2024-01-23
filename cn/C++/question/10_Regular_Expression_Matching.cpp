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
// @test("aab", "c*a*b")=true
// @test("mississippi", "mis*is*p*.")=false
// @test("mississippi", "mis*is*ip*.")=true
// @test("aaa", "aaaa")=false
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
                if(j == 0){
                    if(p[i] == '*') {
                        dp[i][j] = true;
                    }else if(p[i] == '.') {
                        dp[i][j] =  true;
                    }else if(p[i] == s[j]) {
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                    continue;
                }
                if(p[i] == '*') {
                    if(dp[i-1][j-1] && (p[i-1] == s[j] || p[i-1] == '.')) dp[i][j] = true;
                    else dp[i][j] = false;
                }else if(p[i] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i] == s[j]) {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[m-1][n-1];
    }
};