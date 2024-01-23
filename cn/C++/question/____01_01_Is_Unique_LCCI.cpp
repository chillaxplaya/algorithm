// @algorithm @lc id=100158 lang=cpp 
// @title is-unique-lcci


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test("leetcode")=false
// @test("abc")=true
class Solution {
public:
    bool isUnique(string astr) {
        unsigned long long vis = 0;
        for(char &c : astr) {
            if((vis & (1 << (c - 'a')))) return false;
            vis |= (1 << (c - 'a'));
        }
        return true;
    }
};