#include <iostream>
using namespace std;

int main()
{
    int n, h0, a, c, q;
    cin >> n >> h0 >> a >> c >> q;
    int *heights = new int[n];
    heights[n - 1] = h0;

    for (int i = n - 2; i >= 0; i--)
    {
        heights[i] = (a * heights[i + 1] + c) % q;
    }

    int count = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        int closeHight = heights[i + 1]; // visible max hight
        count++;
        for (int j = i + 1; j < n; j++)
        {
            if ((heights[j] > closeHight))
            {
                closeHight = heights[j];
                count++;
            }
        }
    }

    cout << count << endl;

    delete[] heights;

    return 0;
}

/*
When standing in a line, some people are more noticeable than others, and height has a lot to do with it. For this problem, we define a person i as noticeable to person j if and only if:

Person i is standing in front of person j in line, and
There are no people standing between person i and j that are as tall or taller than person i.

Given the heights of people in line, and these definitions, you are to count how many people are noticeable in a line.

Standard Input
Input consists of 5 space-separated integers, n, ℎ(0), a, c, and q. n is the number of people in the line, and the other values are used in the formula below.

To find the heights of people in the line, you should apply the following formula:

ℎ = (a * h(i-1) +c) mod q, for 1≤i<n

The person with height ℎ(0)  is standing at the front of the line, the person with height ℎ(1)  is second in line, the person with height ℎ(2) is third in line, and so on.

Standard Output
Output the total number of noticeable people in the line.

Sample Input:
5 2012 37 31 2573

Output :
5

Explanation:
The heights of the people in line are:

A : 2012, B : 2431, C : 2496, D : 2328, E : 1258

Because there is no one standing in front of A, the person at the front of the line, no one is noticeable to A.

B notices A.

C notices B, but does not notice A, since B has a height that is greater than or equal to A's height.

D notices C, but not B or A, since C is taller than both B and A.

E notices both D and C, but not A or B, since C is taller than A and B.

1≤h(0)<q≤10
1≤a<q
1≤c<q


*/