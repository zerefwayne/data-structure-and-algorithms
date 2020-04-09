## Approach 1: Bit Manipulation Original ACCEPTED Time O(n) Space O(1)

Take a bit counter array of size 32. Loop through all the numbers and for each number, raise the bitcounter[i] by 1
if the ith bit is set. Hence, since all numbers are appearing thrice, each bitcounter[i] should be a multiple of 3.
But since there's an extra number, at all the places where bitcounter[i]%3 != 0, means that the number has contributed
a bit to it.

```cpp
int Solution::singleNumber(const vector<int> &A)
{

    vector<int> bits(32, 0);
    int num;
    int bit = 0;

    for (int i = 0; i < A.size(); i++)
    {

        num = A[i];

        for (int j = 0; j < 32; j++)
        {
            if (num >> j & 1)
            {
                bits[j]++;
            }
        }
    }

    int res = 0;

    for (int i = 0; i < 32; i++)
    {

        if (bits[i] % 3 != 0)
        {
            res += (int)pow(2, i);
        }
    }

    return res;
}
```

## Approach 2: Unordered Map O(n) time O(n) space

```py
from collections import defaultdict

class Solution:
	# @param A : tuple of integers
	# @return an integer
	def singleNumber(self, A):
        umap = defaultdict(int)
        for num in A:
            umap[num] += 1
            if umap[num] == 3:
                del umap[num]
        for k, v in umap.items():
            return k
```