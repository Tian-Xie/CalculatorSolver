#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

const long long INF = 1000000;

long long reverse(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	long long ret = 0;
	for (int i = len - 1; i >= 0; i --) ret = ret * 10 + buf[i] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long mirror(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	long long ret = 0;
	for (int i = 0; i < len; i ++) ret = ret * 10 + buf[i] - '0';
	for (int i = len - 1; i >= 0; i --) ret = ret * 10 + buf[i] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long rshift(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	long long ret = 0;
	for (int i = 0; i < len; i ++) ret = ret * 10 + buf[(i - 1 + len) % len] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long inv10(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	long long ret = 0;
	for (int i = 0; i < len; i ++) ret = ret * 10 + (10 - (buf[i] - '0')) % 10;
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long lshift(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	long long ret = 0;
	for (int i = 0; i < len; i ++) ret = ret * 10 + buf[(i - 1 + len) % len] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long delright(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	long long ret = x / 10;
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long sum(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	long long ret = 0;
	for (int i = 0; i < len; i ++) ret += buf[i] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

////////////////////////////////////////////////////////////////////////////////////

template <long long A, long long B>
long long chg(long long x, long long& delta) {
	long long intfrom = A + delta;
	long long intto = B + delta;
	char strfrom[10]; sprintf(strfrom, "%lld", intfrom); int lenfrom = strlen(strfrom);
	char strto[10]; sprintf(strto, "%lld", intto); int lento = strlen(strto);
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	for (int i = 0; i < len; i ++) {
		int cmp = 0; for (int j = 0; j < lenfrom; j ++) cmp += strfrom[j] == buf[i + j];
		if (cmp != lenfrom) continue;
		for (int j = 0; j < lenfrom; j ++) buf[i + j] = -1;
		buf[i] = -2;
	}
	long long ret = 0;
	for (int i = 0; i < len; i ++) {
		if (buf[i] == -2) for (int j = 0; j < lento; j ++) ret = ret * 10 + strto[j] - '0';
		else if (buf[i] != -1) ret = ret * 10 + buf[i] - '0';
	}
	if (ret >= INF) return x * sign;
	return ret * sign;
}

template <const char* A, const char* B>
long long chgstr(long long x, long long& delta) {
	char strfrom[10]; sprintf(strfrom, "%s", A); int lenfrom = strlen(strfrom);
	char strto[10]; sprintf(strto, "%s", B); int lento = strlen(strto);
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", x); int len = strlen(buf);
	for (int i = 0; i < len; i ++) {
		int cmp = 0; for (int j = 0; j < lenfrom; j ++) cmp += strfrom[j] == buf[i + j];
		if (cmp != lenfrom) continue;
		for (int j = 0; j < lenfrom; j ++) buf[i + j] = -1;
		buf[i] = -2;
	}
	long long ret = 0;
	for (int i = 0; i < len; i ++) {
		if (buf[i] == -2) for (int j = 0; j < lento; j ++) ret = ret * 10 + strto[j] - '0';
		else if (buf[i] != -1) ret = ret * 10 + buf[i] - '0';
	}
	if (ret >= INF) return x * sign;
	return ret * sign;
}

template <long long U> long long add(long long x, long long& delta) { 
	return x + (U + delta);
}

template <long long U> long long sub(long long x, long long& delta) { 
	return x - (U + delta);
}

template <long long U> long long mul(long long x, long long& delta) {
	return x * (U + delta);
}

template <long long U> long long div(long long x, long long& delta) {
	long long divisor = U + delta;
	return (x % divisor == 0) ? (x / divisor) : x;
}

template <long long U> long long put(long long x, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", U + delta); int len = strlen(buf);
	long long ret = x;
	for (int i = 0; i < len; i ++) ret = ret * 10 + buf[i] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

long long putm(long long x, long long m, long long& delta) {
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; sprintf(buf, "%lld", m); int len = strlen(buf);
	long long ret = x;
	for (int i = 0; i < len; i ++) ret = ret * 10 + buf[i] - '0';
	if (ret >= INF) return x * sign;
	return ret * sign;
}

template <long long U> long long deltaadd(long long x, long long& delta) {
	delta += U;
	return x;
}

// Stage dependent
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
const long long S = 3002;
const long long T = 3507;
const long long steplimit = 6;
const int nfunc = 4;
const int nstore = 0;
// if you need chgstr<strfrom, strto>: 
extern const char strfrom[] = "31";
extern const char strto[] = "00";
long long (*func[]) (long long, long long&) = {&put<7>, &chg<3,5>, &inv10, &rshift};
// portal position from rightmost to leftmost, 0-based. if no portal, set the following values -1
const int portal_from = 4;
const int portal_to = 0;
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

long long portal(long long x) {
	if (portal_from == -1) return x;
	assert(portal_from > portal_to);
	long long tmpx = x;
	int sign = (x < 0) ? -1 : 1; x *= sign;
	char buf[20]; int len = 0; while (x) { buf[len ++] = x % 10; x /= 10; }
	int loop = 0;
	while (len > portal_from) {
		// if (++ loop >= 20) printf("%lld\n", tmpx);
		buf[portal_to] += buf[portal_from];
		for (int i = portal_from; i < len; i ++)
			buf[i] = buf[i + 1];
		len --;
		for (int i = 0; i < len; i ++) if (buf[i] > 10) {
			buf[i + 1] += buf[i] / 10;
			buf[i] %= 10;
		}
		while (len > 0 && buf[len - 1] == 0) len --;
	}
	long long ret = 0;
	for (int i = len - 1; i >= 0; i --) ret = ret * 10 + buf[i];
	if (ret >= INF) return x * sign;
	return ret * sign;
}

int d[steplimit + 1];
int sv[steplimit + 1];

void DFS(long long x, long long delta, vector <long long> store, long long curstep, long long steplimit) {
	if (x == T) {
		for (int i = 0; i < curstep; i ++) {
			if (sv[i] != -1) printf("[sv %d] ", sv[i] + 1);
			if (d[i] < nfunc) printf("%d ", d[i] + 1); else printf("[re %d] ", d[i] - nfunc + 1); 
		}
		printf("\n");
		return;
	}
	if (curstep == steplimit) {
		return;
	}
	for (sv[curstep] = -1; sv[curstep] < nstore; sv[curstep] ++) {
		vector <long long> afterstore = store;
		if (sv[curstep] != -1) {
			if (x < 0) continue;
			afterstore[sv[curstep]] = x;
		}
		for (d[curstep] = 0; d[curstep] < nfunc; d[curstep] ++) {
			long long afterdelta = delta;
			long long after = (*func[d[curstep]])(x, afterdelta);
			after = portal(after);
			if (after == x && afterdelta == delta) continue;
			DFS(after, afterdelta, afterstore, curstep + 1, steplimit);
		}
		for (d[curstep] = nfunc; d[curstep] < nfunc + nstore; d[curstep] ++)
			if (afterstore[d[curstep] - nfunc] != INF) {
				long long after = putm(x, afterstore[d[curstep] - nfunc], delta);
				after = portal(after);
				if (after == x) continue;
				DFS(after, delta, afterstore, curstep + 1, steplimit);
			}
	}
}

int main()
{
	vector <long long> store(nstore, INF);
	DFS(S, 0, store, 0, steplimit);
	return 0;
}
