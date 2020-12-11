#include <cstdio>
#include <cmath>
using namespace std;
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define MAX_NM 504
struct Point {
	double x, y, z;
	inline double dot (const Point &q) const {
		return x * q.x + y * q.y + z * q.z;
	}
} safe[MAX_NM], iron[MAX_NM];
double getz(double r, double x, double y, char sgn){
	if (sgn == '+') return sqrt(r * r - x * x - y * y);
	return -sqrt(r * r - x * x - y * y);
}
Point findCenter(double r, double xa, double ya, double za, double xb, double yb, double zb){
	double cp = xa * yb - xb * ya;
	double c1 = (yb * (r - za) - ya * (r - zb)) / cp, c2 = -(xb * (r - za) - xa * (r - zb)) / cp;
	double zo = r / sqrt(c1 * c1 + c2 * c2 + 1);
	return (Point){c1 * zo, c2 * zo, zo};
}
char s[18];
int main(){
	int n, m, t, i, j;
	double r, x, y, z, xa, ya, za, xb, yb, zb;
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
		tmp = (Point){x, y, getz(r, x, y, s[0])};
		for (j = 1; j <= n; ++j) {
			if (safe[j].dot(tmp) >= safe[j].z * r) break;
		}
		if (j <= n) {
			puts("Safe");
			continue;
		}
		for (j = 1; j <= m; ++j) {
			if (iron[j].dot(tmp) >= iron[j].z * r) break;
		}
		if (j <= m) puts("Goodbye");
		else puts("Passer");
	}
	return 0;
}
