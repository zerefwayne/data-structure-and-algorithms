#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1);
    vector<int> right(n2);

    for (i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }

    for (i = 0; i < n2; i++)
    {
        right[i] = arr[m + 1 + i];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {

        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{

    if (l >= r)
    {
        return;
    }

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main()
{

    vector<int> arr = {-1, 3, 2, 1, 4, 1, 6};

    cout << "Original Array\n\n";

    for (auto &num : arr)
    {
        cout << num << ' ';
    }

    cout << "\n\n";

    cout << "Sorted Array\n\n";

    mergeSort(arr, 0, arr.size() - 1);

    for (auto &num : arr)
    {
        cout << num << ' ';
    }

    cout << '\n';

    return 0;
}