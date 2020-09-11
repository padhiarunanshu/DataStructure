/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 * @brief  : LC 5. Longest Palindromic Substring
 * @author : apadhi
 */
// Problem: Given a string find the Longest palendromic substring.
// Solution is brute force O(N^3) - 10^9 time, accepted is 10^8 in leetcode
// ToDo: Optimized version with DP to be written.

#include <bits/stdc++.h>

class Solution {
  public:
    std::string longestPalindrome(const std::string& iStr, int& oBestLen);

  private:
    bool isPalindrome(const std::string& iStr);
};


bool Solution::isPalindrome(const std::string& iStr) {
//   std::string rev = iStr;
//   std::reverse(rev.begin(), rev.end());
//   return rev == iStr;

  for(int i = 0, j = iStr.length() - 1; i < j; i++, j--) {
      if(iStr[i] != iStr[j]) return false;
  }
  return true;
}

std::string Solution::longestPalindrome(const std::string& iStr, int& oLen) {
  std::string aLongestSub = "";
  int size = iStr.size();
  for(int i = 0; i < size; ++i) {
    for(int j = i; j < size; ++j) {
      int len = j - i + 1;
      std::string sub = iStr.substr(i, len);
      if(len > oLen && isPalindrome(sub)) {
        oLen = len;
        aLongestSub = sub;
      }
    }
  }
  return aLongestSub;
}

int main() {
    Solution s;
    int len = 0;

    std::cout << "Longest palendromic substring is [" << s.longestPalindrome("aaaabbaa", len) << "] with length : "<< len << std::endl;

    return 0;
}