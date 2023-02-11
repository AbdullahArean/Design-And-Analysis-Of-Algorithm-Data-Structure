//12
//12
//12
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int track1[MAXN];
int track2[MAXN];
void makesetfrominp(int v)
{
    track1[v] = v;
    track2[v] = 1;
}
int findsetandreturnidentifier(int v)
{
    if (v == track1[v])
        return v;
    return track1[v] = findsetandreturnidentifier(track1[v]);
}
void uniongivenset(int a, int b)
{
    a = findsetandreturnidentifier(a);
    b = findsetandreturnidentifier(b);
    if (a != b)
    {
        if (track2[a] < track2[b])
            swap(a, b);
        track1[b] = a;track2[a] += track2[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        makesetfrominp(i);
    }
    while (k--)
    {
        string s; int a,b;
        cin>>s>>a>>b;
        if(s=="JOIN"){
            uniongivenset(a,b);

        }
        else {
            if(findsetandreturnidentifier(a)==findsetandreturnidentifier(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

    return 0;
}