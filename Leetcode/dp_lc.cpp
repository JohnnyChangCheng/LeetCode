#include <vector>
#include <limits>
#include <set>
#include <string>

using namespace std;

/*------------------------------------------------------------------------------------------
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
------------------------------------------------------------------------------------------*/
class Solution_322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
/*-----------------------------------------------------------------------------------------
You are given coins of different denominationsand a total amount of money.Write a function 
to compute the number of combinations that make up that amount.You may assume that you have 
infinite number of each kind of coin.
Example 1:
Input: amount = 5, coins = [1, 2, 5]
Output : 4
Explanation : there are four ways to make up the amount :
5 = 5
5 = 2 + 2 + 1
5 = 2 + 1 + 1 + 1
5 = 1 + 1 + 1 + 1 + 1
-----------------------------------------------------------------------------------------*/
class Solution_518 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int j = 0; j < coins.size(); ++j) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coins[j] >= 0) {
                    dp[i] += dp[i - coins[j]];
                }
            }
        }
        return dp[amount];
    }
};