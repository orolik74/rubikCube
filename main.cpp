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
    expr c1 = v.extract(29, 27);
    expr p1 = v.extract(26, 25);

    expr c5 = v.extract(14, 12);
    expr p5 = v.extract(11, 10);

    expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    // return concat(v.extract(34, 30), v.extract(29, 0));

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
    expr c0 = v.extract(34, 30);
    expr c1 = v.extract(29, 25);
    expr c2 = v.extract(24, 20);
    expr c3 = v.extract(19, 15);
    return concat(c2, concat(c0, concat(c3, concat(c1, v.extract(14, 0)))));
}

expr F(const expr& v) {

    expr c2 = v.extract(24, 22);
    expr p2 = v.extract(21, 20);

    expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    expr c6 = v.extract(9, 7);
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
    expr c1 = v.extract(29, 27);
    expr p1 = v.extract(26, 25);

    expr c5 = v.extract(14, 12);
    expr p5 = v.extract(11, 10);

    expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    return concat(v.extract(34, 30),//0
        concat(c7,concat(p7,//1
        concat(v.extract(24, 20),//2
        concat(c5, concat(p5,//3
        concat(c3, concat(p3,//5
        concat(v.extract(9, 5),//6
        concat(c1, p1))))))))));//7
}

expr R1(const expr& v) {
    expr c1 = v.extract(29, 27);
    expr p1 = v.extract(26, 25);

    expr c5 = v.extract(14, 12);
    expr p5 = v.extract(11, 10);

    expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    expr c3 = v.extract(19, 17);
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
    expr c0 = v.extract(34, 30);
    expr c1 = v.extract(29, 25);
    expr c2 = v.extract(24, 20);
    expr c3 = v.extract(19, 15);
    return concat(c3, concat(c2, concat(c1, concat(c0, v.extract(14, 0)))));
}

expr U1(const expr& v) {
    expr c0 = v.extract(34, 30);
    expr c1 = v.extract(29, 25);
    expr c2 = v.extract(24, 20);
    expr c3 = v.extract(19, 15);
    return concat(c1, concat(c3, concat(c0, concat(c2, v.extract(14, 0)))));
}

expr F2(const expr& v) {
    expr c2 = v.extract(24, 22);
    expr p2 = v.extract(21, 20);

    expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    expr c6 = v.extract(9, 7);
    expr p6 = v.extract(6, 5);


    return concat(v.extract(34, 25), //01
        concat(c7, concat(p7, //2
        concat(c6, concat(p6, // 3
        concat(v.extract(14, 10), // 5
        concat(c3, concat(p3, // 6
        concat(c2, p2))))))))); // 7
}
expr F1(const expr& v) {
    expr c2 = v.extract(24, 22);
    expr p2 = v.extract(21, 20);

    expr c3 = v.extract(19, 17);
    expr p3 = v.extract(16, 15);

    expr c7 = v.extract(4, 2);
    expr p7 = v.extract(1, 0);

    expr c6 = v.extract(9, 7);
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
     // 0 -- R
     // 1 -- R1
     // 2 -- R2
     // 3 -- U
     // 4 -- U1
     // 5 -- U2
     // 6 -- F
     // 7 -- F1
     // 8 -- F2
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
    for (char c : t) {
        value = (value << 1) | (c - '0');
    }
    return value;
}


void solve() {
    uint64_t t;
    int cur = 0;
    context ctx;
    // params p(ctx);
    // p.set("parallel.enable", true);
    int ans = 0;
    while (cin >> t) {
        if (cur % 10000 == 0) {
            cout << cur << ' ' << ans << '\n';
        }
        cur++;
        // cout << cur++ << '\n';
        expr cube = ctx.bv_val(t, 35);

        bool f = 0;
        for (int cntTurns = 0; cntTurns <= 1; ++cntTurns) {
            expr_vector turns(ctx);
            expr curCube = cube;
            solver s = solver(ctx);
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
                f = 1;
                ans++;
                // cout << s.get_model().eval(curCube) << '\n';
                break;
            }
        }
        if (!f) {
            // cout << "Ой-ой, не могу собрать(((\n\n";
            // cout << t << '\n';
            // ans++;
            // return;
        }
    }
    // cout << "Все скрамблы можно собрать за <= 11 ходов" << '\n';
    cout << ans << '\n';
}


signed main() {
    freopen("allCubes.txt", "r", stdin);
    // cin.tie(nullptr)->sync_with_stdio(false);
    // cout << setprecision(20) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
