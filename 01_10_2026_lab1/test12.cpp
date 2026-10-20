#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>        
#include <unordered_set>
#include <vector>
#define pi pair<long long, long long>
#define fi first
#define se second
#define PI 3.14159265358979323846

using namespace std;

struct query { long long l, r, idx; };
long long curAns = 0, c = 380;
vector <long long> cnt, ans;
vector <vector <query> > b;

void add(long long v)
{
    cnt[v]++;
    if (cnt[v] == 1) curAns++;
}

void del(long long v)
{
    cnt[v]--;
    if (cnt[v] == 0) curAns--;
}
int main()
{
    long long n; cin >> n;
    vector <long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];

    long long q; cin >> q;
    ans.resize(q);
    b.resize(c);
    for (long long i = 0; i < q; i++)
    {
        char j; cin >> j;
        long long l, r; cin >> l >> r; l--; r--;
        b[l / c].push_back({l, r, i});
    }

    for (long long i = 0; i < c; i++)
        sort(b[i].begin(), b[i].end(), [&](query a, query b) {return a.r < b.r; });

    for (long long i = 0; i < c; i++)
    {
        curAns = 0;
        cnt.clear();
        cnt.assign(2e5 + 1, 0);
        long long l = 0, r = -1;
        for (auto &q : b[i])
        {
            while (r < q.r) add(a[++r]);
            while (l < q.l) del(a[l++]);
            while (l > q.l) add(a[--l]);
            ans[q.idx] = curAns;
        }
    }

    for (long long i : ans) cout << i << "\n";
    
    return 0;
}