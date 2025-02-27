#include <bits/stdc++.h>
using namespace std;

#define 	ll long long int
#define 	new(a,n) ll*a = new ll[n]
#define 	new1(a,n,m) ll**a = new ll*[n]; for(ll i = 0 ; i < n ; i++) a[i] = new ll[m];
#define 	mp make_pair
#define 	pb push_back
#define 	fi first
#define 	pii pair<ll,ll>
#define 	si second
#define 	fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define 	F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define 	F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define 	P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define 	P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define 	NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define 	NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define 	PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define 	PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define 	init(a,n,v) for(int i = 0 ; i <n ; i++) a[i]=v;
#define 	init2(a,n,m,v) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){a[i][j]=v;}}
#define 	w(t) int t;cin>>t;while(t--)
#define 	f(n) for(int __i=0;__i<n;__i++)
#define 	AS 200001
#define 	mod 1000000007

// class node {
// public:
// 	vector<ll> v;
// };

vector<ll> tree[AS];
ll arr[AS];
ll i, j, k, ans = 0, q, n;

void buildTree(ll s, ll e, ll indx = 0) {
	if (s == e) {
		tree[indx].push_back(arr[s]);
		return;
	}
	if (s > e) return;
	ll mid = (s + e) / 2;
	buildTree(s, mid, 2 * indx + 1);
	buildTree(mid + 1, e, 2 * indx + 2);
	merge(tree[2 * indx + 1].begin(), tree[2 * indx + 1].end(),
	      tree[2 * indx + 2].begin(), tree[2 * indx + 2].end(),
	      back_inserter(tree[indx]));
}

int query(ll s, ll e, ll  l, ll r, ll k, ll indx = 0) {
	// 1. no overlap
	if (s > r || e < l) return 0;

	if (s >= l and e <= r) {
		return
		    tree[indx].size() -
		    (upper_bound(tree[indx].begin(), tree[indx].end(), k) - tree[indx].begin());
	}

	ll mid = (s + e) / 2;
	ll left = query(s, mid, l, r, k, 2 * indx + 1);
	ll right = query(mid + 1, e, l, r, k, 2 * indx + 2);
	return left + right;
}

void solve() {

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	buildTree(0, n - 1);

	w(t) {
		cin >> i >> j >> k;
		i ^= ans;
		j ^= ans;
		k ^= ans;

		i--;
		j--;

		ans = query(0, n - 1, i, j, k);
		cout << ans << endl;
	}

}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}











