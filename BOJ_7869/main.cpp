#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

const double Pi = acos(-1);

class Point {
public:
	double x{};
	double y{};
};

class Circle {
public:
	Point c{};
	double r{};
};

double dist(const Point& p, const Point& q) {
	const auto dx = q.x - p.x;
	const auto dy = q.y - p.y;

	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Circle a, b;
	cin >> a.c.x >> a.c.y >> a.r >>
		b.c.x >> b.c.y >> b.r;

	if (0 == a.r || 0 == b.r) {
		cout << fixed << setprecision(3) << 0.;
		return 0;
	}

	const auto d = dist(a.c, b.c);

	if (a.r + b.r <= d) {
		cout << fixed << setprecision(3) << 0.;
		return 0;
	}

	if (d <= abs(a.r - b.r)) {
		cout << fixed << setprecision(3) << round(Pi * pow(min(a.r, b.r), 2) * 1000) / 1000;
		return 0;
	}

	const auto ta = 2 * acos((pow(a.r, 2) + pow(d, 2) - pow(b.r, 2)) / (2 * a.r * d));
	const auto sa = 0.5 * pow(a.r, 2) * (ta - sin(ta));
	const auto tb = 2 * acos((pow(b.r, 2) + pow(d, 2) - pow(a.r, 2)) / (2 * b.r * d));
	const auto sb = 0.5 * pow(b.r, 2) * (tb - sin(tb));

	cout << fixed << setprecision(3) << round((sa + sb) * 1000) / 1000;

	return 0;
}