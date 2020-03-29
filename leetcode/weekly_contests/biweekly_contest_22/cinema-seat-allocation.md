## Approach 1: Pattern Observation Time O(nlogn) Space(1) Beats 56%

```cpp
bool sortSeats(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
    {
        return a[0] < b[0];
    }

    return a[1] < b[1];
}

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {

        sort(reservedSeats.begin(), reservedSeats.end(), sortSeats);

        int count = 0;

        vector<bool> avail(11, true);

        int row;
        int col;
        int flag;

        int rows = n;

        int current = reservedSeats[0][0];
        avail[reservedSeats[0][1]] = false;

        for (int i = 1; i < reservedSeats.size(); i++)
        {

            row = reservedSeats[i][0];
            col = reservedSeats[i][1];

            if (row == current)
            {
                avail[col] = false;
            }
            else
            {

                flag = 0;
                rows--;

                if (avail[2] && avail[3] && avail[4] && avail[5])
                {
                    flag = 1;
                    count++;
                }

                if (avail[6] && avail[7] && avail[8] && avail[9])
                {
                    flag = 1;
                    count++;
                }

                if (flag == 0 && avail[6] && avail[7] && avail[4] && avail[5])
                {
                    count++;
                }

                current = row;
                avail.clear();
                avail.resize(11, true);
                avail[col] = false;
            }
        }

        rows--;

        flag = 0;

        if (avail[2] && avail[3] && avail[4] && avail[5])
        {
            flag = 1;
            count++;
        }

        if (avail[6] && avail[7] && avail[8] && avail[9])
        {
            flag = 1;
            count++;
        }

        if (flag == 0 && avail[6] && avail[7] && avail[4] && avail[5])
        {
            count++;
        }

        count += rows * 2;

        return count;
    }
};
```

## Approach 2: Bit Masking Time O(n)

```py
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        seats = collections.defaultdict(int) 
        res = 0
		
        for row, col in reservedSeats:
            seats[row] = seats[row] | (1 << (col-1))

        for reserved in seats.values():
            curr = 0
            curr += (reserved & int('0111100000', 2)) == 0
            curr += (reserved & int('0000011110', 2)) == 0
            curr += (reserved & int('0001111000', 2)) == 0 and curr == 0

            res += curr    

        return res + 2 * (n - len(seats))
```

