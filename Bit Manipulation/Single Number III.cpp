//BUG: when XORall = INT_MIN -2^31 (negation of -2147483648) cannot be represented in type 'int' [1,1,0,-2147483648]
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XORall = 0; //BUG
        for (int n:nums) {
            XORall ^= n;   //A ^ A = 0, 0 ^ A = A, 1 ^ A = ~A
        }

        long long diffbit = XORall & (-XORall); //x & -x isolates the lowest set bit = the rightmost 1 bit //BUG Even if you store the result in a long long, C++ evaluates -xorAll before assigning it to the long long. The overflow happens instantly,
        int x = 0;
        for (int n:nums) {
            if (n & diffbit) { 
                x ^= n;
            }
        }
        return {x, (int)(XORall ^ x)}; //~A = XORall ^ x
        
    }
};
