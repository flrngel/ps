#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

#define MAX 103
#define _max(a,b) (((a)<(b))?(b):(a))

using namespace std;

class Olympic {
  public:
    int gold, silver, bronze;

    bool operator < (const Olympic& cmp) const {
      if ( gold == cmp.gold ) {
        if ( silver == cmp.silver ) {
          return bronze < cmp.bronze;
        }
        return silver < cmp.silver;
      }
      return gold < cmp.gold;
    }
};

Olympic arr[MAX];
int d[MAX][2 * MAX * MAX];

int main() {
  int n,m,result=0;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    cin >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
  }

  arr[0].gold += m;

  memset(d, 0xff, sizeof(d));
  d[0][m] = m;

  for(int i=1;i<n;i++) {
    for(int j=n-1;j>=1;j--) {
      for(int k=0;k<=m;k++) {
        // if wins
        if ( arr[0] < arr[i] )
          d[j][k] = _max(d[j][k], d[j-1][k]);
        // silver bulllet
        int sb = _max(0, 1 + (arr[0].silver - arr[i].silver));
        arr[i].silver += sb;
        if ( sb <= m && arr[0] < arr[i] )
          d[j][k] = _max(d[j][k], d[j-1][k + sb]);
        arr[i].silver -= sb;

        // bronze bullet
        sb = _max(0, (arr[0].silver - arr[i].silver));
        int bb = _max(0, 1 + (arr[0].bronze - arr[i].bronze));
        arr[i].silver += sb;
        arr[i].bronze += bb;
        if ( sb <= m && bb <= m-sb && arr[0] < arr[i] )
          d[j][k] = _max(d[j][k], d[j-1][k + sb] - bb);
        arr[i].silver -= sb;
        arr[i].bronze -= bb;

        if ( d[j][k] >= 0 ) {
          result = _max(result, j);
        }
      }
    }
  }

  cout << result+1 << endl;
  return 0;
}
