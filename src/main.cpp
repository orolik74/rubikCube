#include <bits/extc++.h>
#include <z3++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace z3;

#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#define itn int
#define all(a) (a).begin(), (a).end()
#define pii pair <int, int>
#define ff first
#define ss second
#define ld long double
#define sz(a) (a).size()
#define retrun return

expr plus1(const expr& v) {
    context &ctx = v.ctx();
    return ite(v == 0, ctx.bv_val(1, 2),
    ite(v == 1, ctx.bv_val(2, 2),
    ctx.bv_val(0, 2)));
}
expr plus2(const expr & v) {
    context &ctx = v.ctx();
    return ite(v == 0, ctx.bv_val(2, 2),
    ite(v == 1, ctx.bv_val(0, 2),
    ctx.bv_val(1, 2)));
}

expr R(const expr& v) {
    const expr c1 = v.extract(29, 27);
    expr p1 = v.extract(26, 25);

    const expr c5 = v.extract(14, 12);
    expr p5 = v.extract(11, 10);

    const expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    const expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    p1 = plus1(p1);
    p3 = plus2(p3);
    p5 = plus2(p5);
    p7 = plus1(p7);

    return concat(v.extract(34, 30),//0
    concat(c3,concat(p3,//1
    concat(v.extract(24, 20),//2
    concat(c7, concat(p7,//3
    concat(c1, concat(p1,//5
    concat(v.extract(9, 5),//6
    concat(c5, p5))))))))));//7
}

expr U(const expr& v) {
    const expr c0 = v.extract(34, 30);
    const expr c1 = v.extract(29, 25);
    const expr c2 = v.extract(24, 20);
    const expr c3 = v.extract(19, 15);
    return concat(c2, // 0
        concat(c0, // 1
        concat(c3, // 2
        concat(c1, // 3
        v.extract(14, 0))))); // 567
}

expr F(const expr& v) {

    const expr c2 = v.extract(24, 22);
    expr p2 = v.extract(21, 20);

    const expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    const expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    const expr c6 = v.extract(9, 7);
    expr p6 = v.extract(6, 5);


    p2 = plus2(p2);
    p3 = plus1(p3);
    p7 = plus2(p7);
    p6 = plus1(p6);

    return concat(v.extract(34, 25), //01
        concat(c6, concat(p6, //2
        concat(c2, concat(p2, // 3
        concat(v.extract(14, 10), // 5
        concat(c7, concat(p7, // 6
        concat(c3, p3))))))))); // 7
}



expr R2(const expr& v) {
    const expr c1 = v.extract(29, 25);

    const expr c5 = v.extract(14, 10);

    const expr c7 = v.extract(4, 0);

    const expr c3 = v.extract(19, 15);

    return concat(v.extract(34, 30),//0
        concat(c7,//1
        concat(v.extract(24, 20),//2
        concat(c5, //3
        concat(c3, //5
        concat(v.extract(9, 5),//6
        c1))))));//7
}

expr R1(const expr& v) {
    const expr c1 = v.extract(29, 27);
    expr p1 = v.extract(26, 25);

    const expr c5 = v.extract(14, 12);
    expr p5 = v.extract(11, 10);

    const expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    const expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    p1 = plus1(p1);
    p3 = plus2(p3);
    p5 = plus2(p5);
    p7 = plus1(p7);

    return concat(v.extract(34, 30),//0
        concat(c5,concat(p5,//1
        concat(v.extract(24, 20),//2
        concat(c1, concat(p1,//3
        concat(c7, concat(p7,//5
        concat(v.extract(9, 5),//6
        concat(c3, p3))))))))));//7
}

expr U2(const expr& v) {
    const expr c0 = v.extract(34, 30);
    const expr c1 = v.extract(29, 25);
    const expr c2 = v.extract(24, 20);
    const expr c3 = v.extract(19, 15);
    return concat(c3, // 0
        concat(c2, // 1
        concat(c1, // 2
        concat(c0, // 3
        v.extract(14, 0))))); // 567
}

expr U1(const expr& v) {
    const expr c0 = v.extract(34, 30);
    const expr c1 = v.extract(29, 25);
    const expr c2 = v.extract(24, 20);
    const expr c3 = v.extract(19, 15);
    return concat(c1, // 0
        concat(c3, // 1
        concat(c0, // 2
        concat(c2, // 3
        v.extract(14, 0))))); // 567
}

expr F2(const expr& v) {
    const expr c2 = v.extract(24, 20);

    const expr c3 = v.extract(19, 15);

    const expr c7 = v.extract(4, 0);

    const expr c6 = v.extract(9, 5);


    return concat(v.extract(34, 25), //01
        concat(c7, //2
        concat(c6,  // 3
        concat(v.extract(14, 10), // 5
        concat(c3,  // 6
        (c2)))))); // 7
}
expr F1(const expr& v) {
    const expr c2 = v.extract(24, 22);
    expr p2 = v.extract(21, 20);

    const expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    const expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    const expr c6 = v.extract(9, 7);
    expr p6 = v.extract(6, 5);


    p2 = plus2(p2);
    p3 = plus1(p3);
    p7 = plus2(p7);
    p6 = plus1(p6);

    return concat(v.extract(34, 25), //01
        concat(c3, concat(p3, //2
        concat(c7, concat(p7, // 3
        concat(v.extract(14, 10), // 5
        concat(c2, concat(p2, // 6
        concat(c6, p6))))))))); // 7
}


expr next_state(const expr & v, const expr & turn) {
     // 0 -- R 1 -- R1 2 -- R2
     // 3 -- U 4 -- U1 5 -- U2
     // 6 -- F 7 -- F1 8 -- F2
     return ite(turn == 0, R(v),
         ite(turn == 1, R1(v),
         ite(turn == 2, R2(v),
         ite(turn == 3, U(v),
         ite(turn == 4, U1(v),
         ite(turn == 5, U2(v),
         ite(turn == 6, F(v),
         ite(turn == 7, F1(v),F2(v)))))))));
}

uint64_t val(const string &t) {
    uint64_t value = 0;
    for (const char c : t) {
        value = (value << 1) | (c - '0');
    }
    return value;
}

constexpr int maxCntTurns = 1;

void solve() {
    uint64_t t;
    context ctx;
    int ans = 0;
    while (cin >> t) {
        const expr cube = ctx.bv_val(t, 35);

        for (int cntTurns = 0; cntTurns <= maxCntTurns; ++cntTurns) {
            expr_vector turns(ctx);
            expr curCube = cube;
            auto s = solver(ctx);
            for (int i = 0; i < cntTurns; ++i) {
                turns.push_back(ctx.int_const(("t"+to_string(i)).c_str()));
                s.add(turns[i] <= 8 && turns[i] >= 0);
            }
            for (int i = 0; i < cntTurns - 1; ++i) {
                s.add(turns[i] / 3 != turns[i + 1] / 3);
            }
            for (int i = 0; i < cntTurns; ++i) {
                curCube = next_state(curCube, turns[i]);
            }
            s.add(curCube == ctx.bv_val(143020828, 35));
            if (s.check() == sat) {
                ans++;
                break;
            }
        }
    }
    cout << "Столько скрамблов можно собрать за <= " << maxCntTurns << " ходов: " << ans << '\n';
}


signed main() {
    const auto unused = freopen("allCubes.txt", "r", stdin);
    (void)unused;
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}