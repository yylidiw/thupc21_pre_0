#include <cstdio>
#include <algorithm>
using namespace std;
#define MOD 1000000007
struct Rectangle {
	int u, d, l, r;
} obs[100008];
bool compRow(const Rectangle &a, const Rectangle &b){
	return a.u < b.u;
}
bool compCol(const Rectangle &a, const Rectangle &b){
	return a.l < b.l;
}
int sum(int l, int r){		// l + (l+1) + ... + r
	return 1ll * (l + r) * (r - l + 1) / 2 % MOD;
}
int diffsum(int l, int r){	// (l-l) + ((l+1)-l) + ... + (r-l) + ((l+1)-(l+1)) + ((l+2)-(l+1)) + ... + (r-r)
	int d = r - l + 1;
	return 166666668ll * (d - 1) % MOD * d % MOD * (d + 1) % MOD;
}
int rectsum(int h, int w){	// sum of pairs inside h * w rectangle
	return (1ll * diffsum(1, h) * w % MOD * w + 1ll * diffsum(1, w) * h % MOD * h) % MOD;
}
int main(){
	int n, m, p, i, plus, minus = 0, h, w, s, pre, cnt, tmp;
	scanf("%d %d %d", &n, &m, &p);
	plus = rectsum(n, m);
	if (p == 0) {
		printf("%d\n", plus);
		return 0;
	}
	// ans = no-obstacle + detour - one obstacle - inside same obstacle + two different obstacles
	for (i = 1; i <= p; ++i) {
		scanf("%d %d %d %d", &obs[i].u, &obs[i].d, &obs[i].l, &obs[i].r);
		h = obs[i].d - obs[i].u + 1;
		w = obs[i].r - obs[i].l + 1;
		s = 1ll * h * w % MOD; 
		// detour
		plus = (plus + 1ll * (obs[i].u - 1) * (n - obs[i].d) % MOD * ((1ll * (w + 1) * w % MOD * w + 4ll * (MOD - diffsum(1, w))) % MOD)) % MOD;
		plus = (plus + 1ll * (obs[i].l - 1) * (m - obs[i].r) % MOD * ((1ll * (h + 1) * h % MOD * h + 4ll * (MOD - diffsum(1, h))) % MOD)) % MOD;
		// inside same obstacle
		minus = (minus + rectsum(obs[i].d - obs[i].u + 1, obs[i].r - obs[i].l + 1)) % MOD;
		// one in i, one out
		minus = (minus + (1ll * sum(obs[i].u, obs[i].d) * (obs[i].u - 1) - 1ll * sum(1, obs[i].u - 1) * h) % MOD * m % MOD * w) % MOD;
		minus = (minus + (1ll * sum(obs[i].d + 1, n) * h - 1ll * sum(obs[i].u, obs[i].d) * (n - obs[i].d)) % MOD * m % MOD * w) % MOD;
		minus = (minus + (1ll * sum(obs[i].l, obs[i].r) * (obs[i].l - 1) - 1ll * sum(1, obs[i].l - 1) * w) % MOD * n % MOD * h) % MOD;
		minus = (minus + (1ll * sum(obs[i].r + 1, m) * w - 1ll * sum(obs[i].l, obs[i].r) * (m - obs[i].r)) % MOD * n % MOD * h) % MOD;
		minus = (minus + 2ll * diffsum(obs[i].u, obs[i].d) * (m - w) % MOD * w) % MOD;
		minus = (minus + 2ll * diffsum(obs[i].l, obs[i].r) * (n - h) % MOD * h) % MOD;
	}
	
	sort(obs + 1, obs + p + 1, compRow);
	pre = cnt = 0;
	for (i = 1; i <= p; ++i) {
		h = 1ll * sum(obs[i].u, obs[i].d) * (obs[i].r - obs[i].l + 1) % MOD;
		s = 1ll * (obs[i].d - obs[i].u + 1) * (obs[i].r - obs[i].l + 1) % MOD;
		plus = (plus + 1ll * h * cnt) % MOD;
		minus = (minus + 1ll * pre * s) % MOD;
		pre = (pre + h) % MOD;
		cnt = (cnt + s) % MOD;
	}
	sort(obs + 1, obs + p + 1, compCol);
	pre = cnt = 0;
	for (i = 1; i <= p; ++i) {
		w = 1ll * sum(obs[i].l, obs[i].r) * (obs[i].d - obs[i].u + 1) % MOD;
		s = 1ll * (obs[i].d - obs[i].u + 1) * (obs[i].r - obs[i].l + 1) % MOD;
		plus = (plus + 1ll * w * cnt) % MOD;
		minus = (minus + 1ll * pre * s) % MOD;
		pre = (pre + w) % MOD;
		cnt = (cnt + s) % MOD;
	}
	printf("%d\n", (plus + MOD - minus) % MOD);
	return 0;
}
