// Problem: Kadene's algorithm || Maximum Subarray

/* Example:
 1) [-2,1,-3,4,-1,2,1,-5,4] -> [4,-1,2,1]
 2) [-1,0] -> [0]
 3) [-1,-2,-3,-4] ->[-1]
*/

// Solution

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArrayvector(vector<int> &nums)
    {
        // Maxsum Will be taken as negative for the 2nd number Example case
        int CurrSum = 0, MaxSum = -1, Chatur = 0;
        int flag = 1;
        for (auto it : nums)
        {
            CurrSum += it;
            if (CurrSum > MaxSum)
            {
                MaxSum = CurrSum;
            }
            if (CurrSum < 0)
            {
                if (flag == 1)
                {
                    // Only Run Once
                    Chatur = CurrSum;
                }
                // Comparing Chatur with all -ve numbers that can be in the vector , The greatest will be stored in the Chatur
                if (Chatur < CurrSum)
                {
                    Chatur = CurrSum;
                }
                // Making CurrSum = 0 , cuz if the sum uptil now is -ve then we can't make the largest subarray.
                CurrSum = 0;
            }
            if (MaxSum == -1)
            {
                return Chatur;
            }
            else
            {
                return MaxSum;
            }
        }
        return nums;
    }
};

int main()
{
    Solution s = new Solution();
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    s.maxSubArrayvector(a);

    return 0;
}