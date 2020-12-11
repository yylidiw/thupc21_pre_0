#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define MAX_NM 504
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
} safe[MAX_NM], iron[MAX_NM];
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
	int n, m, t, i, j;
	double r, x, y, xa, ya, za, xb, yb, zb;
	Point tmp;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%lf", &r);
	for (i = 1; i <= n; ++i) {
		scanf("%lf %lf %s", &xa, &ya, s);
		za = getz(r, xa, ya, s[0]);
		scanf("%lf %lf %s", &xb, &yb, s);
		zb = getz(r, xb, yb, s[0]);
		safe[i] = findCenter(r, xa, ya, za, xb, yb, zb);
	}
	for (i = 1; i <= m; ++i) {
		scanf("%lf %lf %s", &xa, &ya, s);
		za = getz(r, xa, ya, s[0]);
		scanf("%lf %lf %s", &xb, &yb, s);
		zb = getz(r, xb, yb, s[0]);
		iron[i] = findCenter(r, xa, ya, za, xb, yb, zb);
	}
	for (i = 1; i <= t; ++i) {
		scanf("%lf %lf %s", &x, &y, s);
		tmp = toxoy(r, x, y, getz(r, x, y, s[0]));
		for (j = 1; j <= n; ++j) {
			if (safe[j].x * tmp.x + safe[j].y * tmp.y >= r) break;
		}
		if (j <= n) {
			puts("Safe");
			continue;
		}
		for (j = 1; j <= m; ++j) {
			if (iron[j].x * tmp.x + iron[j].y * tmp.y >= r) break;
		}
		if (j <= m) puts("Goodbye");
		else puts("Passer");
	}
	return 0;
}
