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
#define TR(c, it) for (auto (it) = (c).begin(); (it) != (c).end(); (it)++)

class Solution {
 public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<i32> vs(people.size());
    REP(i, 0, people.size()) vs[i] = i;

    TR(people, i) i->second *= -1;
    sort(all(people));

    vector<pair<int, int>> ans(people.size());
    TR(people, it) {
      ans[vs[-it->second]] = pair<i32, i32>{it->first, -it->second};
      vs.erase(vs.begin() - it->second);
    }
    return ans;
  }
};

i32 main() {
  ios::sync_with_stdio(false); // Makes IO faster, remove this line if C style scanf/printf needed.
}