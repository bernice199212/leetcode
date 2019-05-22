//description
/*
1049. Last Stone Weight II    Medium

We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 100
*/

/*
解法：利用背包思想，可看做将石头分为两堆，互相碰撞，分堆后，每堆石头总和接近
全部总和的一半。
也可理解为所有石头可以组成的重量数值，不同组合生成的重量值不同，由于两块石头可以相互
抵消，因此最大可组合值*2即为所有石头可以生成的总重量。
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
       int sum = accumulate(stones.begin(),stones.end(),0);
        vector<bool>dp(sum/2+1,0);
        dp[0] = 1;
        for(int i=0;i<stones.size();i++)
        {
            for(int j = sum/2;j>=stones[i];j--)
            {
                dp[j] = dp[j]|dp[j-stones[i]];
            }
        }
        int res = sum;
        for(int i=0;i<=sum/2;i++)
        {
            res = min(res,sum-dp[i]*i*2);
        }
        return res;
        
    }
};