#include <bits/stdc++.h>

using namespace std;

void kadane1D(vector<int> &arr)
{

    int n = arr.size();

    vector<int> sum(n, 0);
    vector<int> parent(n, 0);

    sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        if (arr[i] + sum[i - 1] >= arr[i])
        {
            sum[i] = arr[i] + sum[i - 1];
            parent[i] = parent[i - 1];
        }
        else
        {
            sum[i] = arr[i];
            parent[i] = i;
        }
    }

    cout << "Original Array\n\n";
    for (auto &num : arr)
    {
        cout << num << '\t';
    }
    cout << '\n';
    cout << '\n';
    cout << "Sum Array\n\n";
    for (auto &num : sum)
    {
        cout << num << '\t';
    }
    cout << '\n';
    cout << '\n';
    cout << "Parent Array\n\n";
    for (auto &num : parent)
    {
        cout << num << '\t';
    }
    cout << '\n';
    cout << '\n';

    int max = *max_element(sum.begin(), sum.end());

    int range_end = max_element(sum.begin(), sum.end()) - sum.begin();
    int range_start = parent[range_end];

    cout << "Max range: " << range_start << '-' << range_end << " with a sum: " << max << '\n';
}

int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    kadane1D(arr);

    return 0;
}