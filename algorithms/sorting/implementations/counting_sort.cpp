#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int> &arr)
{

    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    int k = max - min + 1;

    vector<int> count(k, 0);

    for (auto &num : arr)
    {
        count[num]++;
    }

    for(auto &n: count) {
        cout<<n<<' ';
    }
    cout<<'\n';

    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }

    cout<<'\n';
    for(auto &n: count) {
        cout<<n<<' ';
    }
    cout<<'\n';

    for (int i = k-1; i > 0; i--)
    {
        count[i] = count[i - 1];
    }

    count[0] = 0;

    cout<<'\n';
    for(auto &n: count) {
        cout<<n<<' ';
    }
    cout<<"\n\n";

    count[0] = 0;

    vector<int> res(arr.size(), 0);

    for (auto &num : arr)
    {
        int index = count[num];
        res[index] = num;
        count[num] += 1;
    }

    arr.clear();
    arr.assign(res.begin(), res.end());
}

int main()
{

    vector<int> arr = {1, 4, 3, 2, 2, 2, 5, 0, 6, 4};

    for (auto &num : arr)
    {
        cout << num << ' ';
    }

    cout << "\n\n";

    cout << "Sorted Array\n\n";

    countingSort(arr);

    for (auto &num : arr)
    {
        cout << num << ' ';
    }

    cout << '\n';

    return 0;
}