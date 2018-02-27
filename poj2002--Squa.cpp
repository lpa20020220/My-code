#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define R register
#define	W while
#define IN inline
#define gc getchar()
namespace Geometry
{
	using std::lower_bound;
	#define db double
	#define EPS 1e-8
	const db PI = acos((double) -1);
	struct pt
	{
		db x, y;
		IN bool operator < (const pt &x)const
		{
			return this->x == x.x ? this->y > x.y : this->x < x.x;
		}
		IN bool operator == (const pt &x) const
		{
			return fabs(this->x - x.x) < EPS && fabs(this->y - x.y) < EPS;
		}
	};
	IN pt operator + (const pt &x, const pt &y){return (pt){x.x + y.x, x.y + y.y};}
	IN pt operator - (const pt &x, const pt &y){return (pt){x.x - y.x, x.y - y.y};}
	IN db operator * (const pt &x, const pt &y){return x.x * y.y - x.y * y.x;}
	IN pt cal (const int &type, const pt &start, const pt &endd)
	{return (pt){(start.x + endd.x) / 2 - (endd.y - start.y) / 2 * type, (start.y + endd.y) / 2 + (endd.x - start.x) / 2 * type};}
	int num, ans;
	pt data[1005], up, down;
	IN bool found (const pt &x)
	{
		int pos = lower_bound(data + 1, data + 1 + num, x) - data;
		if(data[pos] == x) return true;
		return false;
	}
}
using namespace std;
using namespace Geometry;
int main()
{
	W (233)
	{
		ans = 0;
		scanf("%d", &num);
		if(!num) return 0;
		for (R int i = 1; i <= num; ++i)
		{
			scanf("%lf%lf", &data[i].x, &data[i].y);
		}
		sort(data + 1, data + 1 + num);
		for (R int i = 1; i <= num; ++i)
		{
			for (R int j = i + 1; j <= num; ++j)
			{
				up = cal(1, data[i], data[j]);
				down = cal(-1, data[i], data[j]);
				if(found(up) && found (down)) ans++;
			}
		}
		printf("%lld\n", ans / 2);
	}
}
