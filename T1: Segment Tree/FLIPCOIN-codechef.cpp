//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
//Link: https://www.codechef.com/problems/FLIPCOIN
// summation
struct segmenttree {
	int n;
	vector<int> st, lazy;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
	}
	int query(int start, int ending, int l, int r, int node) {

		// lazy propagation / clear the lazy update
		if (lazy[node] ) {
			// pending updates
			// update the segment tree node
            st[node]=(ending - start + 1)-st[node];
            if (start != ending) {
				// propagate the updated value
				lazy[2 * node + 1] = !lazy[2 * node + 1];
				lazy[2 * node + 2] = !lazy[2 * node + 2];
			}
			lazy[node] = 0;
		}
		// non overlapping case
		if (start > r || ending < l) {
			return 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + ending) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void update(int start, int ending, int node, int l, int r, int value) {

		// lazy propagation / clear the lazy update
		if (lazy[node]) {
			// pending updates
			// update the segment tree node
            st[node]=(ending - start + 1)-st[node];
            if (start != ending) {
				// propagate the updated value
				lazy[2 * node + 1] = !lazy[2 * node + 1];
				lazy[2 * node + 2] = !lazy[2 * node + 2];
			}
			lazy[node] = 0;
		}
		// non overlapping case
		if (start > r || ending < l) {
			return ;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			if (start != ending) {
				lazy[2 * node + 1] = !lazy[2 * node + 1];
				lazy[2 * node + 2] = !lazy[2 * node + 2];
			}
			st[node] = (ending - start + 1)-st[node];
			return;
		}

		// partial case
		int mid = (start + ending) / 2;

		update(start, mid, 2 * node + 1, l, r, value);

		update(mid + 1, ending, 2 * node + 2, l, r, value);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}
	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int l, int r, int x) {
		update(0, n - 1, 0, l, r, x);
	}
};
void solve() {
  int  n, q, a, l, r;
  cin>>n>>q;
  segmenttree tree;
  tree.init(n);
  while(q--){
    cin>>a>>l>>r;
    if(a==0){
        tree.update(l,r,1);

    }
    if(a==1){
        cout<<tree.query(l,r)<<endl;
        
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}