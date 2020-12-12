#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define weakAssert(_cond, _ret) if (!(_cond)) return _ret
const double eps = 1e-7;
struct Point {
	double x, y, z;
	inline bool operator < (const Point &q) const {
		return x == q.x ? (y == q.y ? z < q.z : y < q.y) : x < q.x;
	}
	inline bool operator == (const Point &q) const {
		return fabs(x - q.x) < eps && fabs(y - q.y) < eps && fabs(z - q.z) < eps;
	}
	double dot (const Point &q) const {
		return x * q.x + y * q.y + z * q.z;
	}
	void pr () const {
		printf("%lf %lf %lf\n", x, y, z);
	}
} allpts[200007], cen[200007];
double theta[200007];
Point findCenter(double r, Point p, Point q){
	double cp = p.x * q.y - q.x * p.y;
	double c1 = (q.y * (r - p.z) - p.y * (r - q.z)) / cp, c2 = -(q.x * (r - p.z) - p.x * (r - q.z)) / cp;
	double zo = r / sqrt(c1 * c1 + c2 * c2 + 1);
	return (Point){c1 * zo, c2 * zo, zo};
}
char s[180];
FILE *FL; 
int readAxis(double r, double &x){
	static char buf[18];
	int a, b;
	char *ptr;
	fscanf(FL, "%s", buf);
	sscanf(buf, "%d", &a);
	ptr = strchr(buf, '.') + 1;
	weakAssert(strlen(ptr) == 3, 1);
	sscanf(ptr, "%d", &b);
	x = (buf[0] == '-' ? (a - b / 1000.0) : (a + b / 1000.0));
	weakAssert(1 <= fabs(x) && fabs(x) <= r, 1);
	return 0;
}
int readPoint(double r, Point &p){
	static char buf[18];
	double s;
	if (readAxis(r, p.x)) return 1;
	if (readAxis(r, p.y)) return 1;
	fscanf(FL, "%s", buf);
	weakAssert(strlen(buf) == 1 && (buf[0] == '+' || buf[0] == '-'), 1);
	s = p.x * p.x + p.y * p.y;
	weakAssert(1 <= s && s <= r * r, 1);
	if (buf[0] == '+') p.z = sqrt(r * r - s);
	else p.z = -sqrt(r * r - s);
	return 0;
}
int validator(){
	int n, m, t, i, j, rbd = 0, tot = 0, v = 0;
	double r;
	Point p, q;
	fscanf(FL, "%d %d %d", &n, &m, &t);
	fscanf(FL, "%lf", &r);
	weakAssert(1 <= n && n <= 5000, 1);
	weakAssert(1 <= m && m <= 5000, 2);
	weakAssert(1 <= t && t <= 150000, 3);
	weakAssert(1 <= r && r <= 1000, 4);
	
	for (i = 1; i <= n; ++i) {
		if (readPoint(r, p)) return 500000 + i;
		allpts[++tot] = p;
		if (readPoint(r, q)) return 600000 + i;
		allpts[++tot] = q;
		if (fabs(p.x * q.y - q.x * p.y) < eps) return 700000 + i;
		cen[i] = findCenter(r, p, q);
		theta[i] = acos(cen[i].z / r);
	}
	for (i = 1; i <= m; ++i) {
		if (readPoint(r, p)) return 800000 + i;
		allpts[++tot] = p;
		if (readPoint(r, q)) return 900000 + i;
		allpts[++tot] = q;
		if (fabs(p.x * q.y - q.x * p.y) < eps) return 1000000 + i;
		cen[n + i] = findCenter(r, p, q);
		theta[n + i] = acos(cen[n + i].z / r);
	}
	for (i = 1; i <= t; ++i) {
		if (readPoint(r, p)) return 1100000 + i;
		allpts[++tot] = p;
		for (j = 1; j <= n + m; ++j) {
			if (r * fabs(theta[j] - acos(p.dot(cen[j]) / r / r)) < 1e-6) {
				printf("%d %d(%s) %e\n", i, j > n ? j - n : j, j > n ? "Tinytree" : "ustze", r * fabs(theta[j] - acos(p.dot(cen[j]) / r / r)));
				v = (1200000 + i) * 1000 + j; //return (1200000 + i) * 1000 + j;
			}
		}
	}
	
	sort(allpts + 1, allpts + tot + 1);
	for (i = 1; i < tot; ++i) {
		while (rbd <= tot && (rbd <= i || allpts[rbd].x - allpts[i].x < 1e-3)) ++rbd;
		for (j = i + 1; j < rbd; ++j) {
			if (allpts[i] == allpts[rbd]) return 1300000 + i;
		}
	}
	return v;
}
int main(){
	int T = 15, i, v, cnt = 0;
	for (i = 1; i <= T; ++i) {
		sprintf(s, "../data/sphere%d.in", i);
		FL = fopen(s, "r");
		v = validator();
		if (v) printf("Error %d in %s\n", v, s);
		else printf("%s OK.\n", s), ++cnt;
	}
	if (cnt != T) puts("Error!!!!!!!!!");
	return 0;
}
