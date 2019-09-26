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
#define MAX_PRECISION cout << setprecision(numeric_limits<double>::max_digits10);

i32 main() {
  ios::sync_with_stdio(false);  // Makes IO faster, remove this line if C style scanf/printf needed.
  int s, e;
  cin >> s >> e;

  queue<int> q;
  q.push(s);
  unordered_map<int, int> dis;
  dis[s] = 0;
  
  while(!q.empty()) {
    int item = q.front();
    q.pop();
    if (item == e) {
      cout << dis[e] << "\n";
      return 0;
    }
    
    vi32 choices = { item - 1, item * 2 };
    for (int c : choices) {
      if (c < 1 || c > 2e4 || dis.find(c) != dis.end()) continue;
      q.push(c);
      dis[c] = dis[item] + 1;
    }
  }

  return -1;
}
