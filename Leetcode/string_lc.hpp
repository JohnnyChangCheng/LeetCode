#pragma once
#include <vector>
#include <limits>

using namespace std;

/*-----------------------------------------------------------------------------------------------------------
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous 
subarray of which the sum ≥ s. If there isn't one, return 0 instead.
Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
--------------------------------------------------------------------------------------------------------------*/
class Solution_209 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int windowSum = 0, windowStart = 0;
        int minWindowSize = numeric_limits<int>::max();

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            windowSum += nums[windowEnd];

            // If subarray sum > target, shrink
            while (windowSum >= s) {
                minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }

        return minWindowSize == numeric_limits<int>::max() ? 0 : minWindowSize;
    }
};

/*-----------------------------------------------------------------------------------------------------------
Given a string s, find the length of the longest substring without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
--------------------------------------------------------------------------------------------------------------*/
class Solution_3 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> st;
        int maxLen = 0, windowStart = 0, windowEnd = 0;

        while (windowEnd < n) {
            if (st.find(s[windowEnd]) == st.end()) {
                st.insert(s[windowEnd]);
                maxLen = max(maxLen, windowEnd - windowStart + 1);
                windowEnd++;
            }
            else {
                st.erase(st.find(s[windowStart]));
                windowStart++;
            }
        }

        return maxLen;
    }
};