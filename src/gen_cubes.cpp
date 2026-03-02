#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define itn int
#define int long long
#define all(a) (a).begin(), (a).end()
#define pii pair <int, int>
#define ff first
#define ss second
#define ld long double
#define sz(a) (a).size()
#define retrun return

int cur[7];

uint64_t val(const string &t) {
    uint64_t value = 0;
    for (char c : t) {
        value = (value << 1) | (c - '0');
    }
    return value;
}

void printCube(const vector<pii>& cube) {
    string crr;
    for (auto [x, y]: cube) {
        if (x == 4) continue;
        crr += char(((x&4)>>2) + '0');
        crr += char(((x&2)>>1) + '0');
        crr += char((x & 1) + '0');
        crr += char(((y&2)>>1) + '0');
        crr += char((y&1) + '0');
    }
    cout << val(crr) << ' ';
}

int ans = 0;
int cnt = 0;
void calc(int k) {
    if (k == 7) {
        if (cnt == 1000) {
            exit(0);
        }

        vector <pii> cube(8);

        int sm = 0;
        for (int i = 0; i < 4; ++i) {
            cube[i].ss = cur[i];
            sm += cur[i];
        }
        for (int i = 5; i < 8; ++i) {
            cube[i].ss = cur[i - 1];
            sm += cur[i - 1];
        }
        if (sm % 3 != 0) {
            return;
        }

        vector <int> posl = {0, 1, 2, 3, 5, 6, 7};
        do {
            for (int i = 0; i < 4; ++i) {
                cube[i].ff = posl[i];
            }
            cube[4].ff = 4;
            for (int i = 5; i < 8; ++i) {
                cube[i].ff = posl[i - 1];
            }

            printCube(cube);
        }while (next_permutation(all(posl)));

        return;
    }

    for (int i = 0; i <= 2; ++i) {
        cur[k] = i;
        calc(k + 1);
        cur[k] = 0;
    }
}

void solve() {
    calc(0);
}


signed main() {
    const auto unused = freopen("allCubes.txt", "w", stdout);
    (void)unused;
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
