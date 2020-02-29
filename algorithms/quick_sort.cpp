#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int l, int h)
{

    int pivot = arr[h];

    int i = l - 1;

    for (int j = l; j < h; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            int x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
        }
    }

    int x = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = x;

    return i + 1;
}

void quickSort(vector<int> &arr, int l, int h)
{

    if (l >= h)
    {
        return;
    }

    int pivot = partition(arr, l, h);

    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, h);
}

int main()
{

    vector<int> arr = {3, 2, 4, 5, 1, 6, -1, 0, 8};

    cout<<"Original Array\n\n";

    for(auto &num: arr) {
        cout<<num<<' ';
    }

    cout<<"\n\n";

    cout<<"Sorted Array\n\n";

    quickSort(arr, 0, arr.size() - 1);

    for(auto &num: arr) {
        cout<<num<<' ';
    }

    cout<<'\n';

    return 0;
}