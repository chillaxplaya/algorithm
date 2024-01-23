// @algorithm @lc id=5 lang=cpp 
// @title longest-palindromic-substring


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("babad")="bab"
// @test("cbbd")="bb"
// @test("babad")="bab"
// @test("babad")="bab"
// @test("bb")="bb"
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 1)return s;
        vector<vector<bool>> dp(len,vector<bool>(len));
        for(int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        for(int L = 2; L <= len; L++) {
            for(int i = 0; i < len; i++){
                int j = i + L - 1;
                if(j > len) break;
                if(s[i] == s[j]){
                    if(L <= 3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        int ans = 1;
        int L,R;
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++) {
                if(dp[i][j] && j - i + 1 > ans){
                    ans = j - i + 1;
                    L=i;
                    R=j;
                }
            }
        }
        if(ans == 1) return s.substr(0,1);
        return s.substr(L,R - L + 1);
    }
};