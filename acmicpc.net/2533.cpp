#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

#define MAX 1000007

using namespace std;

int check[MAX];
int cache[MAX][2];
vector<int> node[MAX];

int dfs(int i, int status) {
  check[i] = 1;
  if ( cache[i][status] != -1 ) {
    return cache[i][status];
  }

  int sum = status;
  for(int j=0;j<node[i].size();j++) {
    if ( check[node[i][j]] == 1 ) {
      continue;
    }

    if ( status == 1 ) {
      sum += min(dfs(node[i][j],0), dfs(node[i][j],1));
    }
    else {
      sum += dfs(node[i][j],1);
    }
  }

  check[i] = 0;
  return cache[i][status] = sum;
}

int main() {
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  memset(cache, 0xff, sizeof(cache));
  memset(check, 0xff, sizeof(check));
  int result1 = dfs(1,0);
  memset(cache, 0xff, sizeof(cache));
  memset(check, 0xff, sizeof(check));
  int result2 = dfs(1,1);

  cout << min(result1, result2) << endl;
  return 0;
}
