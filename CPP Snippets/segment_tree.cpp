// Segement tree(root 0 indexed)
// RANGE MAX QUERY & UPDATE A[idx] += val 

const int N = 1e5+1;
const int sz = 1e6+1;
int A[N], tree[sz];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = dp[start];
		return;
	}
	int mid = (start+end)/2;
	build(1+(node<<1), start, mid);
	build(2+(node<<1), mid+1, end);
	tree[node] = max(tree[1+(node<<1)], tree[2+(node<<1)]);
}
 
void update(int node, int start, int end, int idx, int val){
	if(start==end){
		tree[node] = val;
		dp[idx] = val;
		return;
	}
	int mid = (start+end)/2;
	if(start<=idx && idx<=mid) update(1+(node<<1), start, mid, idx, val);
	else update(2+(node<<1), mid+1, end, idx, val);
	tree[node] = max(tree[1+(node<<1)], tree[2+(node<<1)]);
}
 
int query(int node, int start, int end, int l, int r){
	if(start>r || end<l) return LONG_MIN;
	if(l<=start && end<= r) return tree[node];
	int mid = (start+end)/2;
	int q1 = query(1+(node<<1), start, mid, l, r);
	int q2 = query(2+(node<<1), mid+1, end, l, r);
	return max(q1, q2);
}