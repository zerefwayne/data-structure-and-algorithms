/*

    Problem Link: https://cses.fi/problemset/task/1163
    Name: Traffic Lights
    Topic: Sorting and Searching

    There is a street of length x whose positions are numbered 0,1,…,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.

    Your task is to calculate the length of the longest passage without traffic lights after each addition.

    Input

    The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.

    Then, the next line contains n integers p1,p2,…,pn: the position of each set of traffic lights. Each position is distinct.

    Output

    Print the length of the longest passage without traffic lights after each addition.

    Constraints
    1≤x≤109
    1≤n≤2⋅105
    0<pi<x
    Example

    Input:
    8 3
    3 6 2


*/

/*
    APPROACH 1:
        Boolean array of isTrafficLight, calculate the traffic light nearest in both directions and put new traffic light in between.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x, q;
    cin >> x >> q;

    vector<bool> isTrafficLight(x + 1, false);
    isTrafficLight[0] = true;

    int longestInterval = x;
    int longestIntervalStartsFrom = 0;

    for (int i = 0; i < q; i++)
    {

        int position_t;
        cin >> position_t;

        int t_before_post = 0;
        int t_after_post = x;

        isTrafficLight[position_t] = true;

        for (int j = position_t; j >= 0; j--)
        {

            if (isTrafficLight[j])
            {
                t_before_post = j;
                break;
            }
        }

        for (int j = position_t + 1; j <= x; j++)
        {

            if (isTrafficLight[j])
            {
                t_after_post = j;
                break;
            }
        }

        int leftLength = position_t - t_before_post;
        int rightLength = t_after_post - position_t;

        if (longestInterval < max(leftLength, rightLength)) {



        }

        cout << longestInterval << '\n';
    }

    cout << '\n';
}
