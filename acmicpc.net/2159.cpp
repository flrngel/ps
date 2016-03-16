#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

#define MAX 500007
#define _abs(a) (((a)>0)?(a):-(a))
#define def pair<long long,long long>

using namespace std;

vector<int> node[MAX];
bool check[MAX];

int main() {
  int n;
  long long dx[5] = {0, 0, 1, 0, -1};
  long long dy[5] = {0, -1, 0, 1, 0};
  scanf("%d", &n);

  long long sx, sy;
  scanf("%lld %lld", &sx, &sy);
  
  long long x1, y1;
  scanf("%lld %lld", &x1, &y1);

  priority_queue <def, vector<def>, greater<def> > pq;
  for(int i=0;i<5;i++) {
    long long X1 = x1 + dx[i];
    long long Y1 = y1 + dy[i];
    pq.push(make_pair(_abs(sx-X1) + _abs(sy-Y1), i));
  }

  for(int i=0;i<n-1;i++) {
    long long x2, y2;
    scanf("%lld %lld", &x2, &y2);

    for(int j=0;j<5;j++) {
      long long X1 = x1 + dx[j];
      long long Y1 = y1 + dy[j];
      for(int k=0;k<5;k++) {
        long long X2 = x2 + dx[k];
        long long Y2 = y2 + dy[k];

        node[i*5+j].push_back( _abs(X1-X2) + _abs(Y1-Y2) );
      }
    }

    x1 = x2;
    y1 = y2;
  }
  
  while (!pq.empty()) {
    def top = pq.top(); pq.pop();

    if( check[top.second] == 1 ) {
      continue;
    }
    check[top.second] = 1;

    if ( top.second/5 == n-1 ) {
      printf("%lld\n", top.first);
      break;
    }

    for(int i=0;i<node[top.second].size();i++) {
      pq.push(make_pair(top.first + node[top.second][i], 5*(top.second/5+1)+i));
    }
  }
  return 0;
}
