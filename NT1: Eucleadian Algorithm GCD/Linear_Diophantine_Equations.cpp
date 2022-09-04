/*
Linear Diaphantine Equations:
============================
Diophantine Equation: Polynomial equation in two or more unknowns, such that only integral solution
are required.
Problem Statement:
Given three integers of the form ax+by = c. Determine the equation has a solution such that x
and y are both integral solutions

ax+by =c;
*/
#include <bits/stdc++.h>
using namespace std;
// a x + b y = gcd(a,b); returns (x), (y) and (gcd of a,b)
vector<int> extended_gcd(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    vector<int> result = extended_gcd(b, a % b);

    // after recursive call is over
    int smallx = result[0];
    int smally = result[1];
    int gcd = result[2];

    int x = smally;
    int y = smallx - (a / b) * smally;

    return {x, y, gcd};
}
vector<int> linear_D_eq(int a, int b, int c)
{
    vector<int> result1 = extended_gcd(a, b);
    if (c % result1[2] == 0)
    {
        cout << "Solution Exists" << endl;
        int k = c / result1[2];
        int x = result1[0];
        int y = result1[1];
        int g = result1[2];
       // cout << x << " and " << y << " gcd: " << g << endl;
        for (int i = 1; i < 10; i++)
        {
            x = x + (b / g) * i;
            y = y - (a / g) * i;
            cout << x << " and " << y << endl;
        }
        return {k * result1[0], k * result1[1], result1[2]};
    }
    else
    {
        cout << "Solution Doesn't Exists" << endl;
        return {-1, -1, -1};
    }
}
int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}
int main()
{
    int a = 25, b = 15, c = 400;
    vector<int> ans = linear_D_eq(a, b, c);

return 0;
}