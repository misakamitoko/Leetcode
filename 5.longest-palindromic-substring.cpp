/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30109
 *
 * [5] 最长回文子串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int l=s.length();
        int begin=0,maxLength=1;
        vector<vector<int>> dp(l,vector<int>(l));
        for(int i=0;i<l;i++){
            dp[i][i]=1;
        }
        for(int L=2;L<=l;L++){
            for(int j=0;j<l;j++){
                int k=j+L-1;
                if(k>=l){
                    break;
                }
                if(s[k]==s[j]){
                    if(L==2){
                        dp[j][k]=1;
                    }else{
                        dp[j][k]=dp[j+1][k-1];
                    }
                }
                if(dp[j][k]&&L>maxLength){
                    begin=j;
                    maxLength=L;
                }
            }
        }
        return s.substr(begin,maxLength);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

