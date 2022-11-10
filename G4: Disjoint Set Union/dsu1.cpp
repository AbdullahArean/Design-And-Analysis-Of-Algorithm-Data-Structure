#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
// Link: https://cp-algorithms.com/data_structures/disjoint_set_union.html
int parent[MAXN];
int size[MAXN];
void makeset(int v)
{
    /*
    To create a new set (operation make_set(v)),
    we simply create a tree with root in the vertex v,
     meaning that it is its own ancestor.
    */
    parent[v] = v;
    size[v] = 1;
}
int findset(int v)
{
    /*
        Finally the implementation of the find representative
        function (operation find_set(v)): we simply climb the
        ancestors of the vertex v until we reach the root, i.e.
        a vertex such that the reference to the ancestor leads to
        itself. This operation is easily implemented recursively.
    */
    if (v == parent[v])
        return v;
    //return findset(parent[v]); // Without Path Compression
    return parent[v] = findset(parent[v]);
    /*
    ****make the paths for all those nodes shorter, by setting the parent of each visited vertex directly to p.
    ****first find the representative of the set (root vertex), and then in the process of stack unwinding the visited
        nodes are attached directly to the representative.

    */
}
void unionset(int a, int b)
{
    /*
    To combine two sets (operation union_sets(a, b)), we first find
    he representative of the set in which a is located, and the
    representative of the set in which b is located. If the representatives
    are identical, that we have nothing to do, the sets are already merged.
    Otherwise, we can simply specify that one of the representatives is the
    parent of the other representative - thereby combining the two trees.
    */
    a = findset(a);
    b = findset(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
/*
    Time complexity

As mentioned before, if we combine both optimizations - path compression with union by size / rank - we will reach nearly constant time queries. It turns out, that the final amortized time complexity is
, where is the inverse Ackermann function, which grows very slowly. In fact it grows so slowly, that it doesn't exceed for all reasonable (approximately

).

Amortized complexity is the total time per operation, evaluated over a sequence of multiple operations. The idea is to guarantee the total time of the entire sequence, while allowing single operations to be much slower then the amortized time. E.g.
in our case a single call might take
in the worst case, but if we do such calls back to back we will end up with an average time of

.

We will also not present a proof for this time complexity, since it is quite long and complicated.
Also, it's worth mentioning that DSU with union by size / rank, but without path compression works in
time per query.
*/