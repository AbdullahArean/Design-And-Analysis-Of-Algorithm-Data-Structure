#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
/*
Number of operartion:
Required Number of operations to multiply a matrix of size n*m and size m*p
need operation is n*m*p 


Multiplying a chain of matrix produces a matrix whose the number of rows of the first
matrix and the number of columns is the number of columns of the last matrix

A n*p size matrix
B p*m size matrix
C m*q size matrix
D q*r size matrix
E r*z size matrix
dimension (AB)= rows(A)* cols(B)= n*m
dimension (CDE)= rows(C)* cols(E)= m*z

cost of AB by CDE is n*m*z

so min cost of compute (AB)(CDE) = min cost to compute AB 
                                    + min cost to compute CDE
                                    + cost of computing AB by CDE
*/






















int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}