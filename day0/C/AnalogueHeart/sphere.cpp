#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define MAX_NM 504
const double eps = 1e-7;
struct Point {
	double x, y;
	inline bool operator < (const Point &q) const {
		return x == q.x ? y < q.y : x < q.x;
	}
	inline Point operator + (const Point &q) const {
		return (Point){x + q.x, y + q.y};
	}
	inline Point operator - (const Point &q) const {
		return (Point){x - q.x, y - q.y};
	}
	inline double operator * (const Point &q) const {
		return x * q.y - y * q.x; 
	}
};
double Calc(const Point &A, const Point &B, const Point &C){
	return (B - A) * (C - A);
}
struct Hull {
	Point p[MAX_NM];
	int rim, tot;	// 0 ~ rim, rim ~ tot
	static Point stk[];
	void append(const Point &q) {
		p[++tot] = q;
		return ;
	}
	void build () {
		int cnt, i;
		sort(p + 1, p + tot + 1);
		stk[cnt = 0] = p[1];
		for (i = 2; i <= tot; ++i) {
			while (cnt && Calc(stk[cnt - 1], stk[cnt], p[i]) <= 0) --cnt;
			stk[++cnt] = p[i];
		}
		rim = cnt;
		for (i = tot - 1; i; --i) {
			while (cnt > rim && Calc(stk[cnt - 1], stk[cnt], p[i]) <= 0) --cnt;
			stk[++cnt] = p[i];
		}
		memcpy(p, stk, sizeof(Point) * (cnt + 1));
		tot = cnt;
		return ;
	}
	double queryMax (double a, double b) {	// return max(ax+by)
		if (fabs(b) < eps) return (a > 0 ? a * p[rim].x : a * p[0].x);
		int lbd, rbd, mid;
		double ans, k = -a / b;
		if (b > 0) lbd = rim, rbd = tot;
		else lbd = 0, rbd = rim;
		ans = dmax(a * p[lbd].x + b * p[lbd].y, a * p[rbd].x + b * p[rbd].y);
		while (rbd - lbd > 1) {
			mid = (lbd + rbd) / 2;
			if ((p[mid + 1].y - p[mid].y) / (p[mid + 1].x - p[mid].x) >= k) rbd = mid;
			else lbd = mid;
		}
		return dmax(ans, a * p[rbd].x + b * p[rbd].y);
	}
} safe, iron;
// iron: union of inside -> not in intersection of outside	(dangerous)
Point Hull::stk[MAX_NM];
double getz(double r, double x, double y, char sgn){
	if (sgn == '+') return sqrt(r * r - x * x - y * y);
	return -sqrt(r * r - x * x - y * y);
}
Point findCenter(double r, double xa, double ya, double za, double xb, double yb, double zb){
	double cp = xa * yb - xb * ya;
	return (Point){(yb * (r - za) - ya * (r - zb)) / cp, -(xb * (r - za) - xa * (r - zb)) / cp};
}
Point toxoy(double r, double x, double y, double z){
	double t = 1 - z / r;
	return (Point){x / t, y / t};
}
char s[18];
int main(){
	int n, m, t, i;
	double r, x, y, xa, ya, za, xb, yb, zb;
	Point tmp;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%lf", &r);
	for (i = 1; i <= n; ++i) {
		scanf("%lf %lf %s", &xa, &ya, s);
		za = getz(r, xa, ya, s[0]);
		scanf("%lf %lf %s", &xb, &yb, s);
		zb = getz(r, xb, yb, s[0]);
		safe.append(findCenter(r, xa, ya, za, xb, yb, zb));
	}
	safe.build();
	for (i = 1; i <= m; ++i) {
		scanf("%lf %lf %s", &xa, &ya, s);
		za = getz(r, xa, ya, s[0]);
		scanf("%lf %lf %s", &xb, &yb, s);
		zb = getz(r, xb, yb, s[0]);
		iron.append(findCenter(r, xa, ya, za, xb, yb, zb));
	}
	iron.build();
	for (i = 1; i <= t; ++i) {
		scanf("%lf %lf %s", &x, &y, s);
		tmp = toxoy(r, x, y, getz(r, x, y, s[0]));
		if (safe.queryMax(tmp.x, tmp.y) > r) puts("Safe");
		else if (iron.queryMax(tmp.x, tmp.y) > r) puts("Goodbye");
		else puts("Passer");
	}
	return 0;
}
