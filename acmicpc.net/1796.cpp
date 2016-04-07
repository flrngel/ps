#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <memory.h>

#define abs(a) (((a)>0)?(a):(-(a)))
#define _max(a,b) (((a)>(b))?(a):(b))
#define _min(a,b) (((a)>(b))?(b):(a))
#define MAX 1007

using namespace std;

int d[MAX][2];
pair<char, int> ut[MAX];
pair<int,int> arr[MAX];

int main() {
  int N,n;
  N = 1;
  string str;

  cin >> str;
  n = str.length();

  for (int i=0;i<n;i++) {
    ut[i].first = str[i];
    ut[i].second = i;
  }

  sort(ut, ut+n);
  for(int i=0;i<n;) {
    int j=0;
    for(j=0;j<=n;j++) {
      if ( i+j < n && ut[i].first == ut[i+j].first ) {
        arr[N].first = ut[i].second;
        arr[N].second = ut[i+j].second;
      }
      else {
        N++;
        i = i+j;
        break;
      }
    }
  }

  memset(d, 0x7f, sizeof(d));
  d[0][0] = 0;
  d[0][1] = 0;

  for(int i=1;i<N;i++) {
    d[i][0] = d[i-1][0] + abs(arr[i-1].first - arr[i].second) + abs(arr[i].first - arr[i].second);
    d[i][0] = _min(d[i-1][1] + abs(arr[i-1].second - arr[i].second) + abs(arr[i].first - arr[i].second), d[i][0]);

    d[i][1] = d[i-1][0] + abs(arr[i-1].first - arr[i].first) + abs(arr[i].first - arr[i].second);
    d[i][1] = _min(d[i-1][1] + abs(arr[i-1].second - arr[i].first) + abs(arr[i].first - arr[i].second), d[i][1]);
  }

  cout << n + _min( d[N-1][0], d[N-1][1] ) << endl;

  return 0;
}
