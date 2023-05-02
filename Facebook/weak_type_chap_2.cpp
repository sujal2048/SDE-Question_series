#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define lcm(x, y) ((x * y) / __gcd(x, y))
#define ps(x, y) fixed << setprecision(y) << x
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define init(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, p, q) for (ll i = p; i < q; i++)
#define rep_(i, p, q) for (ll i = p; i <= q; i++)
#define deb(x) cout << #x << " = " << x << "\n"
#define cin(arr, n)            \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define uset unordered_set
#define umap unordered_map
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

const int MOD = 1000000007;
ll countf[800000];
int main()
{
    FIO;
    ll t;
    cin >> t;
    for (ll p = 1; p <= t; p++)
    {
        // p++;
        ll n;
        cin >> n;
        string str;
        cin >> str;
        char ch = 'N';
        ll count = 0;
        vector<bool> change(n,0);
        //bool change[n] = {0};
        bool flag = true;
        ll cf = 0;
        char c;
        rep(i, 0, n)
        {
            c = str[i];
            if ((flag) && (c == 'X' || c == 'O'))
            {
                ch = str[i];
                flag = false;
            }
            if (c == 'F')
            {
                cf++;
            }
            else
            {
                countf[i] = cf;
                cf = 0;
            }
        }
        if (ch == 'N')
        {
            cout << "Case #" << p << ": " << 0 << "\n";
            continue;
        }
        char dh;
        rep(i, 0, n)
        {
            dh = str[i];
            if (dh != ch && dh != 'F')
            {
                change[i] = true;
                ch = dh;
            }
            else
            {
                change[i] = false;
            }
        }
        ll a, b = 0;
        rep(i, 1, n)
        {
            if (str[i] == 'F' || str[i] == str[i - 1])
            {
                a = b;
            }
            else if ((str[i] == 'X' && str[i - 1] == 'O') || (str[i] == 'O' && str[i - 1] == 'X'))
            {
                a = b + i;
            }
            else
            {
                if (change[i])
                {
                    a = b + i - countf[i];
                }
                else
                {
                    a = b;
                }
            }
            count = (a + count) % MOD;
            b = a;
        }
        cout << "Case #" << p << ": " << count << "\n";
    }
    return 0;
}