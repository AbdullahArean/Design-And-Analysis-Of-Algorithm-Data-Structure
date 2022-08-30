#include <bits/stdc++.h>
using namespace std;

// summation
class segmenttree
{
    // Segemnt Tree;
    vector<int> st;
    vector<int> lazy;
    int n;
    void build(int start, int ending, int node, vector<int> &v)
    {
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }
        int mid = start + (ending - start) / 2;
        // left subtree is (Start, Mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid+1, ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }
    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping
        if (start > r || ending < l)
        {
            return 0;
        }
        if(lazy[node]!= 0 ){
            //pending update

            //update the segment tree
            st[node] +=lazy[node]*(ending-start+1);
            if(start!= ending){
                //propagating 
            lazy[node*2+1]= lazy[node];

            lazy[node*2+2]= lazy[node];
            }
            lazy[node]=0;
        }
        // Complete Overlapping
        if (start >= l && ending <= r)
        {
            return st[node];
        }
        // partial case
        int mid = start + (ending - start) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
        return q1 + q2;
    }
    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }
        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // right subtree
            update(mid + 1, ending, 2 * node + 2, index, value);
        }
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
        return;
    }

public:
    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    void build(vector<int> &v)
    {
        build(0, v.size() - 1, 0, v);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};
// Maximum
class segmenttreemax
{
    // Segemnt Tree;
    vector<int> st;
    int n;
    void build(int start, int ending, int node, vector<int> &v)
    {
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }
        int mid = start + (ending - start) / 2;
        // left subtree is (Start, Mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid+1, ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = max(st[node * 2 + 1] , st[node * 2 + 2]);
    }
    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping
        if (start > r || ending < l)
        {
            return 0;
        }
        
        // Complete Overlapping
        if (start >= l && ending <= r)
        {
            return st[node];
        }
        // partial case
        int mid = start + (ending - start) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
        return max(q1 , q2);
    }
    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }
        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // right subtree
            update(mid + 1, ending, 2 * node + 2, index, value);
        }
        st[node] =max( st[node * 2 + 1] ,st[node * 2 + 2]);
        return;
    }

public:
    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }
    void build(vector<int> &v)
    {
        build(0, v.size() - 1, 0, v);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};
//Xor
class segmenttreexor
{
    // Segemnt Tree;
    vector<int> st;
    int n;
    void build(int start, int ending, int node, vector<int> &v)
    {
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }
        int mid = start + (ending - start) / 2;
        // left subtree is (Start, Mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid+1, ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] ^ st[node * 2 + 2];
    }
    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping
        if (start > r || ending < l)
        {
            return 0;
        }
        // Complete Overlapping
        if (start >= l && ending <= r)
        {
            return st[node];
        }
        // partial case
        int mid = start + (ending - start) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
        return q1 ^ q2;
    }
    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }
        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // right subtree
            update(mid + 1, ending, 2 * node + 2, index, value);
        }
        st[node] = st[node * 2 + 1] ^ st[node * 2 + 2];
        return;
    }

public:
    void init(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }
    void build(vector<int> &v)
    {
        build(0, v.size() - 1, 0, v);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};
//Link: https://leetcode.com/problems/xor-queries-of-a-subarray/
 vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        segmenttreexor tree;
        tree.init(arr.size());
        tree.build(arr);
        vector<int>ans;
        for(auto i:queries){
            ans.push_back(tree.query(i[0], i[1]));
        }
        return ans;
    }
int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    // // cout<<v.size();
    // segmenttree tree;
    // tree.init(v.size());
    // tree.build(v);
    // cout << tree.query(2, 6) << endl;
    // tree.update(4, 6);
    // cout << tree.query(2, 6) << endl;

    segmenttreemax tree;
    tree.init(v.size());
    tree.build(v);
     cout << tree.query(1, 5) << endl;
    tree.update(1, 13);
    cout << tree.query(1, 5) << endl;
    return 0;
}