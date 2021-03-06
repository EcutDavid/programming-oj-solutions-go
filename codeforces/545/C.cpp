#include <bits/stdc++.h>
using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef pair<i32, i32> pi32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

#define all(c) (c).begin(), (c).end()
#define REP(i, a, b) for (auto i = a; i < b; i++)
#define REPA(i, a, b, acc) for (auto i = a; i < b; i += acc)
#define PB push_back
#define PF push_front
#define PRINT(x) cout << #x ": " << (x) << endl;
#define TR(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); (it)++)

// greedy solution
i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  i32 n;
  cin >> n;

  if (n < 3) {
    cout << n << endl;
    return 0;
  }

  vector<pi32> t;
  REP(i, 0, n) {
    i32 x, h;
    cin >> x >> h;
    t.push_back({x, h});
  }

  i32 total = 2, l = t[0].first;
  REP(i, 1, n - 1) {
    i32 nextI = t[i].first;
    if (t[i].first - t[i].second > l) {
      total++;
    } else if (t[i].first + t[i].second < t[i + 1].first) {
      total++;
      nextI += t[i].second;
    }
    l = nextI;
  }
  cout << total << endl;
}

// DP solution, also AC-ed, but harder to understand due to bad code, but the computation model works.
// i32 main() {
//   ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.

//   i32 n;
//   cin >> n;

//   vector<pi32> t;
//   REP(i, 0, n) {
//     i32 x, h;
//     cin >> x >> h;
//     t.push_back({x, h});
//   }

//   i32 dp[n][2];
//   dp[0][0] = 1;
//   dp[0][1] = t[0].first + t[0].second < t[1].first ? 1 : 0;

//   REP(i, 1, n) {
//     dp[i][1] = dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

//     if (t[i].first - t[i].second > t[i - 1].first) {  // Can cut to left
//       dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);

//       if (t[i].first - t[i].second > t[i - 1].first + t[i - 1].second) {
//         dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
//       }
//     }
//     if ((t[i].first + t[i].second < t[i + 1].first) || (i == (n - 1))) {
//       dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
//     }
//   }

//   cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
// }
